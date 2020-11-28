//
// Created by wojtek on 13.11.2020.
//

#include <ctgmath>
#include <iostream>
#include "InneTrojkaty.h"

std::vector<InneTrojkaty *> InneTrojkaty::liscie;


void InneTrojkaty::obliczSredniaDlugoscBoku() {
    sredniaDlugoscBoku = (bokA + bokB + bokC) / 3.0;
}

void InneTrojkaty::obliczNajkrotszyBok() {
    double min1 = bokA < bokB ? bokA : bokB;
    najkrotszyBok = min1 < bokC ? min1 : bokC;
}

InneTrojkaty::InneTrojkaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC) :
        FiguryGeometryczne(kolor, nazwa), Trojkat(kolor, nazwa, bokA, bokB, bokC) {
    obliczSredniaDlugoscBoku();
    obliczNajkrotszyBok();
    liscie.push_back(this);
}

InneTrojkaty::InneTrojkaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC, int id)
        : FiguryGeometryczne(kolor, nazwa), Trojkat(kolor, nazwa, bokA, bokB, bokC) {
    obliczSredniaDlugoscBoku();
    obliczNajkrotszyBok();
    setId(id);
    liscie.push_back(this);
}

void InneTrojkaty::modifykuj() {
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
        double nowyBokA, nowyBokB, nowyBokC;
        std::cout << "Podaj nowe długości boków:" << std::endl;
        std::cin >> nowyBokA >> nowyBokB >> nowyBokC;
        ustawBoki(nowyBokA, nowyBokB, nowyBokC);
    } else if (opcja == 3) {
        std::cout << "Podaj nowa nazwe obiektu" << std::endl;
        std::cin >> nazwa;
    } else {
        std::cout << "Nieznana operacja" << std::endl;
    }
}

void InneTrojkaty::wypiszDane() {
    std::cout << "Inny trojkat" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Nazwa: " << nazwa << std::endl;
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
    plik << nazwa << std::endl;
    plik << kolor << std::endl;
    plik << bokA << std::endl;
    plik << bokB << std::endl;
    plik << bokC << std::endl;
}

bool InneTrojkaty::usunZListy(std::string &nazwa) {
    InneTrojkaty *inneTrojkaty = znajdzNaLiscie(nazwa);
    if (inneTrojkaty == nullptr) return false;

    liscie.erase(std::remove(liscie.begin(), liscie.end(), inneTrojkaty),
                 liscie.end());

    delete inneTrojkaty;
    return true;
}

void InneTrojkaty::wypiszWszystkie() {
    std::cout << "Wszystkie inne trojkaty:" << std::endl;
    for (auto &element : InneTrojkaty::liscie) {
        std::cout << "Inny trojkat o nazwie: " << element->getNazwa() << std::endl;
    }
}

InneTrojkaty *InneTrojkaty::znajdzNaLiscie(std::string &nazwa) {
    InneTrojkaty *inneTrojkaty = nullptr;
    for (auto &element : liscie) {
        if (element->getNazwa() == nazwa) {
            inneTrojkaty = element;
        }
    }
    return inneTrojkaty;
}
