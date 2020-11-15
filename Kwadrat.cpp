//
// Created by wojtek on 11.11.2020.
//

#include "Kwadrat.h"

Kwadrat::Kwadrat(int kolor, double bok) : FiguryGeometryczne(kolor), Czworokat(kolor, bok, bok, bok, bok) {
    obliczPole();
    obliczObwod();
}

double Kwadrat::getPole() {
    return pole;
}

void Kwadrat::obliczPole() {
    pole = bokA * bokA;
}

void Kwadrat::ustawBok(double bok) {
    ustawBoki(bok, bok, bok, bok);
    obliczPole();
}
