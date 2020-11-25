//
// Created by wojtek on 10.11.2020.
//

#include <tgmath.h>
#include "Trojkat.h"

Trojkat::Trojkat(int kolor,std::string &nazwa, double bokA, double bokB, double bokC) : FiguryGeometryczne(kolor, nazwa), bokA(bokA), bokB(bokB),
                                                                     bokC(bokC) {
    obliczObwod();
    obliczPole();
}

void Trojkat::ustawBoki(double bokA, double bokB, double bokC) {
    Trojkat::bokA = bokA;
    Trojkat::bokB = bokB;
    Trojkat::bokC = bokC;
    obliczObwod();
    obliczPole();
}

double Trojkat::getPole() const {
    return pole;
}

void Trojkat::ustawObwod(double obwod) {
    Trojkat::obwod = obwod;
}

double Trojkat::getObwod() {
    return obwod;
}

void Trojkat::obliczObwod() {
    obwod = bokA + bokB + bokC;
}

void Trojkat::obliczPole() {
    double polowaObwodu = getObwod() / 2;
    pole = sqrt(polowaObwodu * (polowaObwodu - bokA) * (polowaObwodu - bokB) * (polowaObwodu - bokC));
}


