//
// Created by wojtek on 11.11.2020.
//

#include <ctgmath>
#include "OstroslupTrojkatnyPrawidlowy.h"

void OstroslupTrojkatnyPrawidlowy::obliczObwod() {
    ustawObwod(3 * (bokA + krawedz));
}

void OstroslupTrojkatnyPrawidlowy::obliczKrawedz() {
    krawedz = sqrt(pow((bokA * sqrt(3) / 6.0), 2) + pow(wysokosc, 2));
}


OstroslupTrojkatnyPrawidlowy::OstroslupTrojkatnyPrawidlowy(int kolor, double bokPodstawy,
                                                           double wysokosc)
        : FiguryGeometryczne(kolor), Punkt<double>(kolor, 0, 0, wysokosc),
          Trojkat(kolor, bokPodstawy, bokPodstawy, bokPodstawy), wysokosc(wysokosc) {
    obliczKrawedz();
    obliczObwod();
    obliczPole();
}


void OstroslupTrojkatnyPrawidlowy::ustawBok(double bok) {
    ustawBoki(bok, bok, bok);
    obliczKrawedz();
    obliczObwod();
    obliczPole();
}

void OstroslupTrojkatnyPrawidlowy::ustawWysokosc(double wysokosc) {
    Punkt::ustawNoweKoordynaty(0, 0, wysokosc);
    obliczKrawedz();
    obliczObwod();
}

void OstroslupTrojkatnyPrawidlowy::obliczPole() {
    double wysokoscBoku = sqrt(pow(krawedz, 2) - pow((bokA / 2.0), 2));
    pole = pow(bokA, 2) * sqrt(3) / 4.0 + 2 * bokA * wysokoscBoku;
}
