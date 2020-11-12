//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_KWADRAT_H
#define PROJEKT_KWADRAT_H


#include "Czworokat.h"

class Kwadrat : public Czworokat {
private:
    double przekatna;
protected:
    double pole;

    void obliczPole();

public:

    void ustawBok(int bok);

    Kwadrat(int color, int bok);

    double getPole();

};


#endif //PROJEKT_KWADRAT_H
