#include <iostream>
#include "Rownoboczny.h"

Rownoboczny::Rownoboczny(int kolor, std::string &nazwa, double bok) : FiguryGeometryczne(kolor, nazwa),
                                                                      Trojkat(kolor, nazwa, bok, bok, bok) {

    obliczWysokosc();
    obliczPromienOkreguOpisanego();
}

void Rownoboczny::ustawBok(double bok) {
    ustawBoki(bok, bok, bok);
    obliczPole();
    obliczObwod();
    obliczWysokosc();
    obliczPromienOkreguOpisanego();
}


void Rownoboczny::obliczWysokosc() {
    wysokosc = bokA * sqrt(3) / 2.0;
}

void Rownoboczny::obliczPromienOkreguOpisanego() {
    promienOkreguOpisanego = wysokosc * 2.0 / 3;
}

void Rownoboczny::modifykuj() {
    std::cout << "Co chcesz zmienić?" << std::endl;
    std::cout << "1. Kolor" << std::endl;
    std::cout << "2. Bok" << std::endl;
    std::cout << "3. Nazwa" << std::endl;
    std::cout << "4. Powieksz bok o jeden" << std::endl;
    int opcja;
    std::cin >> opcja;
    if (opcja == 1) {
        std::cout << "Podaj nowy kolor" << std::endl;
        std::cin >> kolor;
    } else if (opcja == 2) {
        double nowyBok;
        std::cout << "Podaj nową długość boków:" << std::endl;
        std::cin >> nowyBok;
        ustawBok(nowyBok);
    } else if (opcja == 3) {
        std::cout << "Podaj nowa nazwe obiektu" << std::endl;
        std::cin >> nazwa;
    } else if (opcja == 4) {
        ++(*this);
    } else {
        std::cout << "Nieznana operacja" << std::endl;
    }
}

void Rownoboczny::wypiszDane() {
    std::cout << "Rownoboczny" << std::endl;
    std::cout << "Bok A: " << bokA << ", bok B: " << bokB << ", bok C: " << bokC << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Nazwa: " << nazwa << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
    std::cout << "Pole: " << pole << std::endl;
    std::cout << "Wysokosc: " << wysokosc << std::endl;
    std::cout << "Promien okregu opisanego: " << promienOkreguOpisanego << std::endl;
}

void Rownoboczny::zapiszDoPliku(std::ofstream &plik) {
    plik << "Rownoboczny" << std::endl;
    plik << getId() << std::endl;
    plik << nazwa << std::endl;
    plik << kolor << std::endl;
    plik << bokA << std::endl;
}

Rownoboczny *Rownoboczny::operator++() {
    ustawBok(bokA + 1);
    return this;
}

