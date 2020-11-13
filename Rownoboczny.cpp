//
// Created by wojtek on 11.11.2020.
//

#include "Rownoboczny.h"

Rownoboczny::Rownoboczny(int kolor, double bok) : FiguryGeometryczne(kolor), Trojkat(kolor, bok, bok, bok) {
    obliczObwod();
    obliczPole();
}

void Rownoboczny::ustawBok(double bok) {
    ustawBoki(bok, bok, bok);
    obliczPole();
    obliczObwod();
}

void Rownoboczny::obliczObwod() {
    ustawObwod(3 * bokA);
}

void Rownoboczny::obliczPole() {
    pole = pow(bokA, 2) * sqrt(3) / 4.0;
}

double Rownoboczny::getHeight() const {
    return bokA * sqrt(3) / 2.0;;
}

