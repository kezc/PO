//
// Created by wojtek on 13.11.2020.
//

#include "OstroslupCzworokatnyPrawidlowy.h"

void OstroslupCzworokatnyPrawidlowy::obliczKrawedz() {
    krawedz = sqrt(pow((bokA * sqrt(2) / 2), 2) + pow(wysokosc, 2));
}

void OstroslupCzworokatnyPrawidlowy::obliczObwod() {
    ustawObwod(4 * (bokA + krawedz));
}


OstroslupCzworokatnyPrawidlowy::OstroslupCzworokatnyPrawidlowy(int kolor, double bokPodstawy,
                                                               double wysokosc)
        : FiguryGeometryczne(kolor), Punkt<double>(kolor, 0, 0, wysokosc),
          Kwadrat(kolor, bokPodstawy), wysokosc(wysokosc) {
    obliczKrawedz();
    obliczObwod();
    obliczPole();
}


void OstroslupCzworokatnyPrawidlowy::ustawBok(double bok) {
    ustawBok(bok);
    obliczKrawedz();
    obliczObwod();
    obliczPole();
}

void OstroslupCzworokatnyPrawidlowy::ustawWysokosc(double wysokosc) {
    Punkt::ustawNoweKoordynaty(0, 0, wysokosc);
    obliczKrawedz();
    obliczObwod();
}

void OstroslupCzworokatnyPrawidlowy::obliczPole() {
    double wysokoscBoku = sqrt(pow(krawedz, 2) - pow((bokA / 2.0), 2));
    pole = pow(bokA, 2) * sqrt(3) / 4.0 + 2 * bokA * wysokoscBoku;
}
