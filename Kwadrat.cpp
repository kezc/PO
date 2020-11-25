//
// Created by wojtek on 11.11.2020.
//

#include "Kwadrat.h"

Kwadrat::Kwadrat(int kolor,std::string &nazwa, double bok) : FiguryGeometryczne(kolor, nazwa), Czworokat(kolor, nazwa, bok, bok, bok, bok) {
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
