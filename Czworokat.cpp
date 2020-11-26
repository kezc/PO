//
// Created by wojtek on 11.11.2020.
//

#include "Czworokat.h"

Czworokat::Czworokat(int kolor, std::string &nazwa, double bokA, double bokB, double bokC, double bokD) : FiguryGeometryczne(kolor, nazwa),
                                                                                      bokA(bokA),
                                                                                      bokB(bokB), bokC(bokC),
                                                                                      bokD(bokD) {
}

double Czworokat::getObwod() {
    return obwod;
}


void Czworokat::ustawBoki(double bokA, double bokB, double bokC, double bokD) {
    Czworokat::bokA = bokA;
    Czworokat::bokB = bokB;
    Czworokat::bokC = bokC;
    Czworokat::bokD = bokD;
    obliczObwod();
}

void Czworokat::obliczObwod() {
    obwod = bokA + bokB + bokC + bokD;
}

void Czworokat::ustawObwod(double obwod) {
    Czworokat::obwod = obwod;
}





