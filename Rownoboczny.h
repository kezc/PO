#ifndef PROJEKT_ROWNOBOCZNY_H
#define PROJEKT_ROWNOBOCZNY_H


#include <ctgmath>
#include <algorithm>
#include <vector>
#include "Trojkat.h"

class Rownoboczny : public Trojkat {
private:
    double promienOkreguOpisanego;
protected:
    double wysokosc;

    void obliczWysokosc();

    void obliczPromienOkreguOpisanego();

public:
    Rownoboczny(int kolor, std::string &nazwa, double bok);

    Rownoboczny(int kolor, std::string &nazwa, double bok, int id);

    void ustawBok(double bok);

    void modifykuj() override;

    Rownoboczny *operator++();

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;

    static std::vector<Rownoboczny *> liscie;

    static bool usunZListy(std::string &nazwa);

    static Rownoboczny *znajdzNaLiscie(std::string &nazwa);

    static void wypiszWszystkie();

};


#endif //PROJEKT_ROWNOBOCZNY_H
