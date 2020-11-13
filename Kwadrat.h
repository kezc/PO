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

    virtual void obliczPole();

public:

    void ustawBok(double bok);

    Kwadrat(int kolor, double bok);

    double getPole();

    void obliczObwod() override;
};


#endif //PROJEKT_KWADRAT_H
