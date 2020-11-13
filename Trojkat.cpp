//
// Created by wojtek on 10.11.2020.
//

#include "Trojkat.h"

Trojkat::Trojkat(int kolor, double bokA, double bokB, double bokC) : FiguryGeometryczne(kolor), bokA(bokA), bokB(bokB),
                                                                     bokC(bokC) {
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


