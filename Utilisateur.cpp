#include "Utilisateur.h"
#include <iostream>

Utilisateur::Utilisateur(const std::string& nom, int age, float poids, float taille)
    : nom(nom), age(age), poids(poids), taille(taille) {}

Utilisateur::~Utilisateur() {
    for (Seance* seance : seances) {
        delete seance;
    }
}

std::string Utilisateur::getNom() const {
    return nom; // Retourne le nom de l'utilisateur
}

void Utilisateur::consulterProgression() const {
    if (seances.empty()) {
        std::cout << "Aucune séance n'a été enregistrée." << std::endl;
        return;
    }

    std::cout << "\n=== Progrès des séances ===" << std::endl;
    for (size_t i = 0; i < seances.size(); ++i) {
        const Seance* seance = seances[i];
        if (seance->isTerminee() && seance->getProgres() != nullptr) {
            std::cout << "Séance " << i + 1 << " : " << seance->getProgres()->getDistance()
                      << " km parcourus, " << seance->getProgres()->getCalories()
                      << " kcal brûlées." << std::endl;
        } else {
            std::cout << "Séance " << i + 1 << " : Pas encore terminée." << std::endl;
        }
    }
}

const std::vector<Seance*>& Utilisateur::getSeances() const {
    return seances;
}


void Utilisateur::setNom(const std::string& nom) { this->nom = nom; }
void Utilisateur::setAge(int age) { this->age = age; }
void Utilisateur::setPoids(float poids) { this->poids = poids; }
void Utilisateur::setTaille(float taille) { this->taille = taille; }




void Utilisateur::ajouterSeance(Seance* seance) {
    seances.push_back(seance);
}


float Utilisateur::getPoids() const {
    return poids;
}


