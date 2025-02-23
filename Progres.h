
#ifndef PROGRES_H
#define PROGRES_H

class Progres {
private:
    float distanceParcourue; // en km
    float caloriesBrulees; // en kcal

public:
    Progres(float distanceParcourue, float caloriesBrulees);
    void calculerProgression();
    float getDistance() const;
    float getCalories() const;
};

#endif
