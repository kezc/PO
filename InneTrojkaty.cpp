//
// Created by wojtek on 13.11.2020.
//

#include <tgmath.h>
#include "InneTrojkaty.h"

double InneTrojkaty::getSredniaDlugoscBoku() const {
    return sredniaDlugoscBoku;
}

void InneTrojkaty::obliczSredniaDlugoscBoku() {
    sredniaDlugoscBoku = (bokA + bokB + bokC) / 3.0;
}

void InneTrojkaty::obliczNajkrotszyBok() {
    double min1 = bokA < bokB ? bokA : bokB;
    najkrotszyBok = min1 < bokC ? min1 : bokC;
}

double InneTrojkaty::getNajkrotszyBok() const {
    return najkrotszyBok;
}

InneTrojkaty::InneTrojkaty(int kolor, double bokA, double bokB, double bokC) : FiguryGeometryczne(kolor),
                                                                               Trojkat(kolor, bokA, bokB, bokC) {
    obliczObwod();
    obliczPole();
    obliczSredniaDlugoscBoku();
    obliczNajkrotszyBok();
}

void InneTrojkaty::obliczObwod() {
    ustawObwod(bokA + bokB + bokC);
}

void InneTrojkaty::obliczPole() {
    double polowaObwodu = getObwod() / 2;
    pole = sqrt(polowaObwodu * (polowaObwodu - bokA) * (polowaObwodu - bokB) * (polowaObwodu - bokC));
}
