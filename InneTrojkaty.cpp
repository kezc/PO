//
// Created by wojtek on 13.11.2020.
//

#include <ctgmath>
#include <iostream>
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
    obliczSredniaDlugoscBoku();
    obliczNajkrotszyBok();
}

void InneTrojkaty::modifykuj() {
    std::cout << "Co chcesz zmienić?" << std::endl;
    std::cout << "1. Kolor" << std::endl;
    std::cout << "2. Boki" << std::endl;
    int opcja;
    std::cin >> opcja;
    if (opcja == 1) {
        std::cout << "Podaj nowy kolor" << std::endl;
        std::cin >> kolor;
    } else if (opcja == 2) {
        double nowyBokA, nowyBokB, nowyBokC;
        std::cout << "Podaj nowe długości boków:" << std::endl;
        std::cin >> nowyBokA >> nowyBokB >> nowyBokC;
        ustawBoki(nowyBokA, nowyBokB, nowyBokC);
    } else {
        std::cout << "Nieznana operacja" << std::endl;
    }
}

void InneTrojkaty::wypiszDane() {
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Bok A: " << bokA << ", bok B: " << bokB << ", bok C: " << bokC << std::endl;
    std::cout << "Kolor: " << kolor << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
    std::cout << "Pole: " << pole << std::endl;
    std::cout << "Srednia dlugosc boku: " << sredniaDlugoscBoku << std::endl;
    std::cout << "Najkrotszy bok: " << najkrotszyBok << std::endl;
}

void InneTrojkaty::zapiszDoPliku(std::ofstream &plik) {
    plik << "InneTrojkaty" << std::endl;
    plik << getId() << std::endl;
    plik << kolor << std::endl;
    plik << bokA << std::endl;
    plik << bokB << std::endl;
    plik << bokC << std::endl;
}
