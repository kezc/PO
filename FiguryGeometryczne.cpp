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

int FiguryGeometryczne::getId() {
    return id;
}

FiguryGeometryczne::FiguryGeometryczne(int kolor, std::string &nazwa) : kolor(kolor), nazwa(nazwa) {
    id = licznik++;
}

void FiguryGeometryczne::ustawLicznik(int licznik) {
    FiguryGeometryczne::licznik = licznik;
}

void FiguryGeometryczne::setId(int id) {
    FiguryGeometryczne::id = id;
}

const std::string &FiguryGeometryczne::getNazwa() {
    return nazwa;
}
