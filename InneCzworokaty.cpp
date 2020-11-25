//
// Created by wojtek on 13.11.2020.
//

#include <iostream>
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

InneCzworokaty::InneCzworokaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC, double bokD)
        : FiguryGeometryczne(kolor, nazwa), Czworokat(kolor, nazwa, bokA,
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

void InneCzworokaty::modifykuj() {
    std::cout << "Co chcesz zmienić?" << std::endl;
    std::cout << "1. Kolor" << std::endl;
    std::cout << "2. Boki" << std::endl;
    std::cout << "3. Nazwa" << std::endl;

    int opcja;
    std::cin >> opcja;
    if (opcja == 1) {
        std::cout << "Podaj nowy kolor" << std::endl;
        std::cin >> kolor;
    } else if (opcja == 2) {
        double nowyBokA, nowyBokB, nowyBokC, nowyBokD;
        std::cout << "Podaj nowe długości boków:" << std::endl;
        std::cin >> nowyBokA >> nowyBokB >> nowyBokC >> nowyBokD;
        ustawBoki(nowyBokA, nowyBokB, nowyBokC, nowyBokD);
    } else if (opcja == 3) {
        std::cout << "Podaj nowa nazwe obiektu" << std::endl;
        std::cin >> nazwa;
    } else {
        std::cout << "Nieznana operacja" << std::endl;
    }

}

void InneCzworokaty::wypiszDane() {
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Bok A: " << bokA << ", bok B: " << bokB << ", bok C: " << bokC << ", bok D:" << bokD << std::endl;
    std::cout << "Kolor: " << kolor << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
    std::cout << "Srednia dlugosc boku: " << sredniaDlugoscBoku << std::endl;
    std::cout << "Iloczyn dlugosci bokow: " << iloczynDlugosciBokow << std::endl;

}

void InneCzworokaty::zapiszDoPliku(std::ofstream &plik) {
    plik << "InneCzworokaty" << std::endl;
    plik << getId() << std::endl;
    plik << nazwa << std::endl;
    plik << kolor << std::endl;
    plik << bokA << std::endl;
    plik << bokB << std::endl;
    plik << bokC << std::endl;
    plik << bokD << std::endl;
}
