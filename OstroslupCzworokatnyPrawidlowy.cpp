//
// Created by wojtek on 13.11.2020.
//

#include <iostream>
#include "OstroslupCzworokatnyPrawidlowy.h"

std::vector<OstroslupCzworokatnyPrawidlowy *> OstroslupCzworokatnyPrawidlowy::liscie;

void OstroslupCzworokatnyPrawidlowy::obliczKrawedz() {
    krawedz = sqrt(pow((bokA * sqrt(2) / 2), 2) + pow(getOdlegloscOdSrodkaUkladu(), 2));
}

void OstroslupCzworokatnyPrawidlowy::obliczObwod() {
    ustawObwod(4 * (bokA + krawedz));
}


OstroslupCzworokatnyPrawidlowy::OstroslupCzworokatnyPrawidlowy(int kolor, std::string &nazwa,
                                                               double bokPodstawy,
                                                               double wysokosc)
        : FiguryGeometryczne(kolor, nazwa), Punkt<double>(kolor, nazwa, 0, 0, wysokosc),
          Kwadrat(kolor, nazwa, bokPodstawy) {
    obliczKrawedz();
    obliczObwod();
    obliczPole();
    obliczObjetosc();
    liscie.push_back(this);
}

OstroslupCzworokatnyPrawidlowy::OstroslupCzworokatnyPrawidlowy(int kolor, std::string &nazwa,
                                                               double bokPodstawy,
                                                               double wysokosc, int id)
        : FiguryGeometryczne(kolor, nazwa), Punkt<double>(kolor, nazwa, 0, 0, wysokosc),
          Kwadrat(kolor, nazwa, bokPodstawy) {
    obliczKrawedz();
    obliczObwod();
    obliczPole();
    obliczObjetosc();
    setId(id);
    liscie.push_back(this);
}


void OstroslupCzworokatnyPrawidlowy::ustawBok(double bok) {
    obliczKrawedz();
    obliczObwod();
    obliczPole();
    obliczObjetosc();
}

void OstroslupCzworokatnyPrawidlowy::ustawWysokosc(double wysokosc) {
    Punkt::ustawNoweKoordynaty(0, 0, wysokosc);
    obliczKrawedz();
    obliczObwod();
    obliczPole();
    obliczObjetosc();
}

void OstroslupCzworokatnyPrawidlowy::obliczPole() {
    double wysokoscBoku = sqrt(pow(krawedz, 2) - pow((bokA / 2.0), 2));
    pole = pow(bokA, 2) * sqrt(3) / 4.0 + 2 * bokA * wysokoscBoku;
}

void OstroslupCzworokatnyPrawidlowy::obliczObjetosc() {
    objetosc = bokA * bokA * getOdlegloscOdSrodkaUkladu() / 3.0;
}

void OstroslupCzworokatnyPrawidlowy::modifykuj() {
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

void OstroslupCzworokatnyPrawidlowy::wypiszDane() {
    std::cout << "Ostroslup Czworokatny Prawidlowy" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Bok podstawy: " << bokA << std::endl;
    std::cout << "Kolor: " << kolor << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
    std::cout << "Pole powierzchni: " << pole << std::endl;
    std::cout << "Objetosc:" << objetosc << std::endl;
    std::cout << "Wysokosc: " << getOdlegloscOdSrodkaUkladu() << std::endl;
    std::cout << "Krawedz: " << krawedz << std::endl;
    std::cout << "Przekatna podstawy: " << getPrzekatna() << std::endl;
}

void OstroslupCzworokatnyPrawidlowy::zapiszDoPliku(std::ofstream &plik) {
    plik << "OstroslupCzworokatnyPrawidlowy" << std::endl;
    plik << getId() << std::endl;
    plik << nazwa << std::endl;
    plik << kolor << std::endl;
    plik << bokA << std::endl;
    plik << getOdlegloscOdSrodkaUkladu() << std::endl;
}

OstroslupCzworokatnyPrawidlowy *OstroslupCzworokatnyPrawidlowy::znajdzNaLiscie(std::string &nazwa) {
    OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = nullptr;
    for (auto &element : liscie) {
        if (element->getNazwa() == nazwa) {
            ostroslupCzworokatnyPrawidlowy = element;
        }
    }
    return ostroslupCzworokatnyPrawidlowy;
}

bool OstroslupCzworokatnyPrawidlowy::usunZListy(std::string &nazwa) {
    OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = znajdzNaLiscie(nazwa);
    if (ostroslupCzworokatnyPrawidlowy == nullptr) return false;

    liscie.erase(
            std::remove(liscie.begin(), liscie.end(),
                        ostroslupCzworokatnyPrawidlowy),
            liscie.end());

    delete ostroslupCzworokatnyPrawidlowy;
    return true;
}

void OstroslupCzworokatnyPrawidlowy::wypiszWszystkie() {
    std::cout << "Wszystkie ostroslupy czworokatne prawidlowe:" << std::endl;
    for (auto &element : OstroslupCzworokatnyPrawidlowy::liscie) {
        std::cout << "Ostroslup Czworokatny Rownoboczny o nazwie: " << element->getNazwa() << std::endl;
    }
    if (liscie.empty()) std::cout << "Brak elementow do wyswietlenia" << std::endl;
}
