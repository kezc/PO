//
// Created by wojtek on 13.11.2020.
//

#include "InneCzworokaty.h"

void InneCzworokaty::obliczObwod() {
    ustawObwod(bokA + bokB + bokC + bokD);
}

void InneCzworokaty::obliczSredniaDlugoscBoku() {
    sredniaDlugoscBoku = getObwod() / 4.0;
}

void InneCzworokaty::obliczIloczynDlugosciBokow() {
    iloczynDlugosciBokow = bokA * bokB * bokC * bokD;
}

InneCzworokaty::InneCzworokaty(int kolor, double bokA, double bokB, double bokC, double bokD)
        : FiguryGeometryczne(kolor), Czworokat(kolor, bokA,
                                               bokB, bokC,
                                               bokD) {
    obliczObwod();
    obliczIloczynDlugosciBokow();
    obliczSredniaDlugoscBoku();
}

double InneCzworokaty::getSredniaDlugoscBoku() const {
    return sredniaDlugoscBoku;
}

double InneCzworokaty::getIloczynDlugosciBokow() const {
    return iloczynDlugosciBokow;
}
