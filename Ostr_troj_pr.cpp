//
// Created by wojtek on 11.11.2020.
//

#include <ctgmath>
#include "Ostr_troj_pr.h"

void Ostr_troj_pr::obliczObwod() {
    obwod = 3 * (bokA + krawedz);
}

void Ostr_troj_pr::obliczKrawedz() {
    krawedz = sqrt(pow((bokA * sqrt(3) / 6.0), 2) + pow(wysokosc, 2));
}


Ostr_troj_pr::Ostr_troj_pr(int kolor, double bokPodstawy, double wysokosc)
        : Punkt<double>(kolor, 0, 0, wysokosc), Trojkat(kolor, bokPodstawy, bokPodstawy, bokPodstawy),
          wysokosc(wysokosc) {
    obliczKrawedz();
    Ostr_troj_pr::obliczObwod();
}

int Ostr_troj_pr::getId() const {
    return Trojkat::getId();
}

void Ostr_troj_pr::ustawBok(double bok) {
    Trojkat::ustawBoki(bok, bok, bok);
    obliczKrawedz();
    obliczObwod();
}

void Ostr_troj_pr::ustawWysokosc(double wysokosc) {
    Punkt::setZ(wysokosc);
    obliczKrawedz();
    obliczObwod();
}
