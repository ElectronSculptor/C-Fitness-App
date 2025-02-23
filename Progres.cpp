
#include "Progres.h"

Progres::Progres(float distanceParcourue, float caloriesBrulees)
    : distanceParcourue(distanceParcourue), caloriesBrulees(caloriesBrulees) {}

void Progres::calculerProgression() {
    // Exemple de logique pour calculer les progrès
}

float Progres::getDistance() const {
    return distanceParcourue;
}

float Progres::getCalories() const {
    return caloriesBrulees;
}
