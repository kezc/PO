//
// Created by wojtek on 02.11.2020.
//

#include "FiguryGeometryczne.h"


int FiguryGeometryczne::getKolor() const {
    return kolor;
}

void FiguryGeometryczne::ustawKolor(int kolor) {
    FiguryGeometryczne::kolor = kolor;
}

int FiguryGeometryczne::getId() const {
    return id;
}

FiguryGeometryczne::FiguryGeometryczne(int kolor) : kolor(kolor) {
    id = licznik++;
}

void FiguryGeometryczne::ustawLicznik(int licznik) {
    FiguryGeometryczne::licznik = licznik;
}

void FiguryGeometryczne::setId(int id) {
    FiguryGeometryczne::id = id;
}
