//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_ROWNOBOCZNY_H
#define PROJEKT_ROWNOBOCZNY_H


#include <ctgmath>
#include "Trojkat.h"

class Rownoboczny : public Trojkat {
protected:
    double pole;

    virtual void obliczePole();

public:
    Rownoboczny(int kolor, double bok);

    void ustawBok(double bok);

    double getPole();

};


#endif //PROJEKT_ROWNOBOCZNY_H
