//
// Created by wojtek on 11.11.2020.
//

#include "Czworokat.h"

Czworokat::Czworokat(int kolor, int bokA, int bokB, int bokC, int bokD) : FiguryGeometryczne(kolor), bokA(bokA),
                                                                          bokB(bokB), bokC(bokC), bokD(bokD) {}

double Czworokat::getObwod() {
    return obwod;
}

int Czworokat::getBokA() const {
    return bokA;
}

int Czworokat::getBokB() const {
    return bokB;
}

int Czworokat::getBokC() const {
    return bokC;
}

int Czworokat::getBokD() const {
    return bokD;
}

void Czworokat::ustawBoki(int bokA, int bokB, int bokC, int bokD) {
    Czworokat::bokA = bokA;
    Czworokat::bokB = bokB;
    Czworokat::bokC = bokC;
    Czworokat::bokD = bokD;
    Czworokat::obliczObwod();
}

void Czworokat::obliczObwod() {
    obwod = bokA + bokB + bokC + bokD;
}





