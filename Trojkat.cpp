//
// Created by wojtek on 10.11.2020.
//

#include "Trojkat.h"

Trojkat::Trojkat(int kolor, double bokA, double bokB, double bokC) : FiguryGeometryczne(kolor), bokA(bokA), bokB(bokB),
                                                                     bokC(bokC) {
    Trojkat::obliczObwod();
}

double Trojkat::getObwod() {
    return obwod;
}

void Trojkat::obliczObwod() {
    obwod = bokA + bokB + bokC;
}

void Trojkat::ustawBoki(double bokA, double bokB, double bokC) {
    Trojkat::bokA = bokA;
    Trojkat::bokB = bokB;
    Trojkat::bokC = bokC;
    obliczObwod();
}


