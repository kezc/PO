//
// Created by wojtek on 11.11.2020.
//

#include "Rownoboczny.h"

Rownoboczny::Rownoboczny(int kolor, double bok) : Trojkat(kolor, bok, bok, bok) {
    Rownoboczny::obliczePole();
    Rownoboczny::obliczObwod();
}

double Rownoboczny::getPole() {
    return pole;
}

void Rownoboczny::setBok(double bok) {
    ustawBoki(bok, bok, bok);
    obliczePole();
    obliczObwod();
}

void Rownoboczny::obliczePole() {
    pole = pow(bokA, 2) * sqrt(3) / 4.0;
}

