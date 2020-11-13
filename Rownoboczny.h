//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_ROWNOBOCZNY_H
#define PROJEKT_ROWNOBOCZNY_H


#include <ctgmath>
#include "Trojkat.h"

class Rownoboczny : public Trojkat {
private:
    double height;
protected:
    void obliczObwod() override;

    void obliczPole() override;

    void obliczWysokosc();

public:
    Rownoboczny(int kolor, double bok);

    void ustawBok(double bok);

    double getHeight() const;

};


#endif //PROJEKT_ROWNOBOCZNY_H
