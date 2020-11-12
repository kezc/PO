//
// Created by wojtek on 11.11.2020.
//

#include "Kwadrat.h"

Kwadrat::Kwadrat(int color, int bok) : Czworokat(color, bok, bok, bok, bok) {
    Kwadrat::obliczPole();
}

double Kwadrat::getPole() {
    return pole;
}

void Kwadrat::obliczPole() {
    pole = bokA * bokA;
}

void Kwadrat::ustawBok(int bok) {
    ustawBoki(bok, bok, bok, bok);
    obliczPole();
}
