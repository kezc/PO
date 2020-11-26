//
// Created by wojtek on 11.11.2020.
//

#include <ctgmath>
#include <iostream>
#include "OstroslupTrojkatnyPrawidlowy.h"

void OstroslupTrojkatnyPrawidlowy::obliczObwod() {
    ustawObwod(3 * (bokA + krawedz));
}

void OstroslupTrojkatnyPrawidlowy::obliczKrawedz() {
    krawedz = sqrt(pow((2 * bokA * sqrt(3) / 6.0), 2) + pow(getOdlegloscOdSrodkaUkladu(), 2));
}


OstroslupTrojkatnyPrawidlowy::OstroslupTrojkatnyPrawidlowy(int kolor, std::string &nazwa,
                                                           double bokPodstawy,
                                                           double wysokosc)
        : FiguryGeometryczne(kolor, nazwa), Punkt<double>(kolor, nazwa, 0, 0, wysokosc),
          Trojkat(kolor, nazwa, bokPodstawy, bokPodstawy, bokPodstawy) {
    obliczKrawedz();
    obliczObwod();
    obliczPole();
    obliczObjetosc();
}


void OstroslupTrojkatnyPrawidlowy::ustawBok(double bok) {
    ustawBoki(bok, bok, bok);
    obliczKrawedz();
    obliczObwod();
    obliczPole();
    obliczObjetosc();
}

void OstroslupTrojkatnyPrawidlowy::ustawWysokosc(double wysokosc) {
    Punkt::ustawNoweKoordynaty(0, 0, wysokosc);
    obliczKrawedz();
    obliczObwod();
    obliczPole();
    obliczObjetosc();
}

void OstroslupTrojkatnyPrawidlowy::obliczObjetosc() {
    objetosc = bokA * bokA * getOdlegloscOdSrodkaUkladu() / 3.0;
}


void OstroslupTrojkatnyPrawidlowy::obliczPole() {
    double wysokoscBoku = sqrt(pow((bokA * sqrt(3) / 6.0), 2) + pow(getOdlegloscOdSrodkaUkladu(), 2));
    pole = pow(bokA, 2) * sqrt(3) / 4.0 + 3 * bokA * wysokoscBoku / 2;
}

void OstroslupTrojkatnyPrawidlowy::modifykuj() {
    std::cout << "Co chcesz zmienić?" << std::endl;
    std::cout << "1. Kolor" << std::endl;
    std::cout << "2. Bok podstawy" << std::endl;
    std::cout << "3. Wysokosc" << std::endl;
    std::cout << "4. Nazwe" << std::endl;

    int opcja;
    std::cin >> opcja;
    if (opcja == 1) {
        std::cout << "Podaj nowy kolor" << std::endl;
        std::cin >> kolor;
    } else if (opcja == 2) {
        std::cout << "Podaj nowa dlugosc boku podstawy:" << std::endl;
        double bok;
        std::cin >> bok;
        ustawBok(bok);
    } else if (opcja == 3) {
        double nowaWysokosc;
        std::cout << "Podaj nowa wysokosc" << std::endl;
        std::cin >> nowaWysokosc;
        ustawWysokosc(nowaWysokosc);
    } else if (opcja == 4) {
        std::cout << "Podaj nowa nazwe obiektu" << std::endl;
        std::cin >> nazwa;
    } else {
        std::cout << "Nieznana operacja" << std::endl;
    }
}

void OstroslupTrojkatnyPrawidlowy::wypiszDane() {
    std::cout << "Id:" << getId() << std::endl;
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Bok podstawy: " << bokA << std::endl;
    std::cout << "Kolor: " << kolor << std::endl;
    std::cout << "Obwod:" << getObwod() << std::endl;
    std::cout << "Pole powierzchni: " << pole << std::endl;
    std::cout << "Objetosc:" << objetosc << std::endl;
    std::cout << "Wysokosc :" << getOdlegloscOdSrodkaUkladu() << std::endl;
    std::cout << "Krawedz :" << krawedz << std::endl;
}

void OstroslupTrojkatnyPrawidlowy::zapiszDoPliku(std::ofstream &plik) {
    plik << "OstroslupTrojkatnyPrawidlowy" << std::endl;
    plik << getId() << std::endl;
    plik << nazwa << std::endl;
    plik << kolor << std::endl;
    plik << bokA << std::endl;
    plik << z << std::endl;
}
