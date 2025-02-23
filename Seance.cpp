#include "Seance.h"
#include "Utilisateur.h"
#include <iostream>

Seance::Seance(const std::string& date, int duree, const std::string& type, Utilisateur* utilisateur)
    : date(date), duree(duree), type(type), progres(nullptr), estTerminee(false), utilisateur(utilisateur) {}


Seance::~Seance() {
    delete progres; // Libération de la mémoire allouée pour `Progres`
}


bool Seance::isTerminee() const {
    return estTerminee;
}

float Seance::calculerDistance() const {
    float vitesse = 0.0;

    if (type == "Course") {
        vitesse = 8.0;
    } else if (type == "Vélo") {
        vitesse = 20.0;
    } else if (type == "Natation") {
        vitesse = 3.0;
    } else if (type == "Marche") {
        vitesse = 5.5;
    } else {
        vitesse = 0.0; // Activités statiques (Musculation, Yoga)
    }

    return vitesse * (duree / 60.0); // Convertir durée en heures
}


void Seance::terminer() {
    std::cout << "Séance terminée." << std::endl;

    // Récupère le poids depuis l'utilisateur
    //float poids = utilisateur->getPoids(); 
    float distance = calculerDistance(); // Distance fictive
    float calories = calculerCalories(); // Calcul basé sur l'utilisateur

    progres = new Progres(distance, calories);
    estTerminee = true;
}


Progres* Seance::getProgres() const {
    return progres;
}



float Seance::calculerCalories() const {
    if (!utilisateur) {
        std::cerr << "Erreur : aucun utilisateur associé à cette séance !" << std::endl;
        return 0.0;
    }

    float poids = utilisateur->getPoids(); // Récupère le poids
    float MET = 0.0;

    if (type == "Course") {
        MET = 8.0;
    } else if (type == "Vélo") {
        MET = 7.5;
    } else if (type == "Natation") {
        MET = 6.0;
    } else if (type == "Marche") {
        MET = 4.3;
    } else if (type == "Yoga") {
        MET = 2.5;
    } else if (type == "Musculation (modérée)") {
        MET = 3.5;
    } else if (type == "Musculation (intense)") {
        MET = 6.0;
    } else {
        std::cout << "Activité inconnue, MET par défaut = 1.0" << std::endl;
        MET = 1.0;
    }

    return MET * poids * (duree / 60.0); // Utilisation de `poids`
}


