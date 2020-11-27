#include <tgmath.h>
#include "Kwadrat.h"

Kwadrat::Kwadrat(int kolor, std::string &nazwa, double bok) : FiguryGeometryczne(kolor, nazwa),
                                                              Czworokat(kolor, nazwa, bok, bok, bok, bok) {
    obliczPole();
    obliczObwod();
    obliczPrzekatna();
}

void Kwadrat::obliczPole() {
    pole = bokA * bokA;
}

void Kwadrat::ustawBok(double bok) {
    ustawBoki(bok, bok, bok, bok);
    obliczPole();
}

void Kwadrat::obliczPrzekatna() {
    przekatna = bokA * sqrt(2);
}

double Kwadrat::getPrzekatna() {
    return przekatna;
}

