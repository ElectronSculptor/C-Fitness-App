#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <vector>
#include "Seance.h"



class Utilisateur {
private:
    std::string nom;
    int age;
    float poids;
    float taille;
    std::vector<Seance*> seances;

public:
    Utilisateur(const std::string& nom, int age, float poids, float taille);
    ~Utilisateur();

    std::string getNom() const;
    float getPoids() const; // Ajout de cette méthode

    void consulterProgression() const;
    void ajouterSeance(Seance* seance);
    
    
    void setNom(const std::string& nom);
    void setAge(int age);
    void setPoids(float poids);
    void setTaille(float taille);
    
    const std::vector<Seance*>& getSeances() const;


};

#endif
