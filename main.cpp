#include <iostream>
#include <string>
#include <vector>
#include "Utilisateur.h"
#include "Seance.h"
#include "Progres.h"

// Fonction pour afficher le menu principal
void afficherMenuPrincipal() {
    std::cout << "\n=== Menu principal ===" << std::endl;
    std::cout << "1. Choisir ou créer un utilisateur" << std::endl;
    std::cout << "2. Accéder au menu utilisateur" << std::endl;
    std::cout << "3. Supprimer un utilisateur" << std::endl;
    std::cout << "4. Modifier un utilisateur" << std::endl;
    std::cout << "5. Quitter" << std::endl;
    std::cout << "Votre choix : ";
}

// Fonction pour afficher le menu utilisateur
void afficherMenuUtilisateur() {
    std::cout << "\n=== Menu utilisateur ===" << std::endl;
    std::cout << "1. Ajouter une séance" << std::endl;
    std::cout << "2. Démarrer une séance" << std::endl;
    std::cout << "3. Terminer une séance" << std::endl;
    std::cout << "4. Consulter les progrès" << std::endl;
    std::cout << "5. Retour au menu principal" << std::endl;
    std::cout << "Votre choix : ";
}

// Fonction pour gérer les utilisateurs (choisir ou créer)
Utilisateur* gererUtilisateurs(std::vector<Utilisateur*>& utilisateurs) {
    std::cout << "\n=== Gestion des utilisateurs ===" << std::endl;
    if (utilisateurs.empty()) {
        std::cout << "Aucun utilisateur existant. Veuillez en créer un." << std::endl;
    } else {
        std::cout << "Liste des utilisateurs disponibles : " << std::endl;
        for (size_t i = 0; i < utilisateurs.size(); ++i) {
            std::cout << i + 1 << ". " << utilisateurs[i]->getNom() << std::endl;
        }
    }

    std::cout << "0. Créer un nouvel utilisateur" << std::endl;
    std::cout << "Votre choix : ";
    int choix;
    std::cin >> choix;
    std::cin.ignore();

    if (choix == 0 || utilisateurs.empty()) {
        // Création d'un nouvel utilisateur
        std::string nom;
        int age;
        float poids, taille;
        std::cout << "Entrez le nom de l'utilisateur : ";
        std::getline(std::cin, nom);
        std::cout << "Entrez l'âge : ";
        std::cin >> age;
        std::cout << "Entrez le poids (kg) : ";
        std::cin >> poids;
        std::cout << "Entrez la taille (m) : ";
        std::cin >> taille;
        std::cin.ignore();

        Utilisateur* nouvelUtilisateur = new Utilisateur(nom, age, poids, taille);
        utilisateurs.push_back(nouvelUtilisateur);
        std::cout << "Utilisateur créé avec succès !" << std::endl;
        return nouvelUtilisateur;
    } else if (choix > 0 && choix <= static_cast<int>(utilisateurs.size())) {
        return utilisateurs[choix - 1];
    } else {
        std::cout << "Choix invalide. Retour au menu principal." << std::endl;
        return nullptr;
    }
}

// Fonction pour gérer l'accès au menu utilisateur
void gererMenuUtilisateur(Utilisateur* utilisateurActuel) {
    if (utilisateurActuel == nullptr) {
        std::cout << "Aucun utilisateur sélectionné. Veuillez en choisir ou créer un." << std::endl;
        return;
    }

    int choixUtilisateur;
    do {
        afficherMenuUtilisateur();
        std::cin >> choixUtilisateur;
        std::cin.ignore();

        switch (choixUtilisateur) {
		case 1: {
		    std::string date, type;
		    int duree;
		    std::cout << "Entrez la date de la séance (AAAA-MM-JJ) : ";
		    std::getline(std::cin, date);
		    std::cout << "Entrez le type de la séance (Course, Vélo, etc.) : ";
		    std::getline(std::cin, type);
		    std::cout << "Entrez la durée de la séance (en minutes) : ";
		    std::cin >> duree;
		    std::cin.ignore();

		    Seance* seance = new Seance(date, duree, type, utilisateurActuel);
		    utilisateurActuel->ajouterSeance(seance);
		    std::cout << "Séance ajoutée avec succès !" << std::endl;
		    break;
		}
            case 2: {
                // Démarrer une séance
                std::cout << "Démarrage de la séance." << std::endl;
                break;
            }
		case 3: {
		    // Terminer une séance
		    if (!utilisateurActuel->getSeances().empty()) {
			utilisateurActuel->getSeances().back()->terminer();
			std::cout << "Séance terminée et progrès enregistrés." << std::endl;
		    } else {
			std::cout << "Aucune séance active à terminer." << std::endl;
		    }
		    break;
		}

            case 4: {
                // Consulter les progrès
                utilisateurActuel->consulterProgression();
                break;
            }
            case 5:
                // Retour au menu principal
                std::cout << "Retour au menu principal." << std::endl;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    } while (choixUtilisateur != 5);
}

// Fonction pour supprimer un utilisateur
void supprimerUtilisateur(std::vector<Utilisateur*>& utilisateurs) {
    if (utilisateurs.empty()) {
        std::cout << "Aucun utilisateur à supprimer." << std::endl;
        return;
    }

    std::cout << "Liste des utilisateurs disponibles : " << std::endl;
    for (size_t i = 0; i < utilisateurs.size(); ++i) {
        std::cout << i + 1 << ". " << utilisateurs[i]->getNom() << std::endl;
    }

    std::cout << "Entrez le numéro de l'utilisateur à supprimer : ";
    int choix;
    std::cin >> choix;
    std::cin.ignore();

    if (choix > 0 && choix <= static_cast<int>(utilisateurs.size())) {
        delete utilisateurs[choix - 1];
        utilisateurs.erase(utilisateurs.begin() + (choix - 1));
        std::cout << "Utilisateur supprimé avec succès !" << std::endl;
    } else {
        std::cout << "Choix invalide." << std::endl;
    }
}


// Fonction pour modifier un utilisateur
void modifierUtilisateur(std::vector<Utilisateur*>& utilisateurs) {
    if (utilisateurs.empty()) {
        std::cout << "Aucun utilisateur à modifier." << std::endl;
        return;
    }

    std::cout << "Liste des utilisateurs disponibles : " << std::endl;
    for (size_t i = 0; i < utilisateurs.size(); ++i) {
        std::cout << i + 1 << ". " << utilisateurs[i]->getNom() << std::endl;
    }

    std::cout << "Entrez le numéro de l'utilisateur à modifier : ";
    int choix;
    std::cin >> choix;
    std::cin.ignore();

    if (choix > 0 && choix <= static_cast<int>(utilisateurs.size())) {
        Utilisateur* utilisateur = utilisateurs[choix - 1];
        std::string nom;
        int age;
        float poids, taille;

        std::cout << "Modifier les informations pour " << utilisateur->getNom() << ":" << std::endl;
        std::cout << "Nouveau nom : ";
        std::getline(std::cin, nom);
        std::cout << "Nouvel âge : ";
        std::cin >> age;
        std::cout << "Nouveau poids (kg) : ";
        std::cin >> poids;
        std::cout << "Nouvelle taille (m) : ";
        std::cin >> taille;
        std::cin.ignore();

        utilisateur->setNom(nom);
        utilisateur->setAge(age);
        utilisateur->setPoids(poids);
        utilisateur->setTaille(taille);

        std::cout << "Utilisateur modifié avec succès !" << std::endl;
    } else {
        std::cout << "Choix invalide." << std::endl;
    }
}



int main() {
    std::vector<Utilisateur*> utilisateurs;
    Utilisateur* utilisateurActuel = nullptr;

    int choixPrincipal;

    do {
        afficherMenuPrincipal();
        std::cin >> choixPrincipal;
        std::cin.ignore();

        switch (choixPrincipal) {
            case 1:
                utilisateurActuel = gererUtilisateurs(utilisateurs);
                break;
            case 2:
                gererMenuUtilisateur(utilisateurActuel);
                break;
            case 3:
                supprimerUtilisateur(utilisateurs);
                break;
            case 4:
                modifierUtilisateur(utilisateurs);
                break;
            case 5:
                std::cout << "Merci d'avoir utilisé l'application !" << std::endl;
                break;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
        }
    } while (choixPrincipal != 5);

    for (Utilisateur* utilisateur : utilisateurs) {
        delete utilisateur;
    }

    return 0;
}

