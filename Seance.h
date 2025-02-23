#ifndef SEANCE_H
#define SEANCE_H

#include <string>
#include "Progres.h"

class Utilisateur; // Déclaration anticipée

class Seance {
private:
    std::string date;
    int duree; // en minutes
    std::string type;
    Progres* progres;
    bool estTerminee;
    Utilisateur* utilisateur; // Lien vers l'utilisateur

public:
    Seance(const std::string& date, int duree, const std::string& type, Utilisateur* utilisateur);
    ~Seance();

    void demarrer();
    void terminer();
    Progres* getProgres() const;
    bool isTerminee() const;
    float calculerCalories() const;
    float calculerDistance() const;

};

#endif

