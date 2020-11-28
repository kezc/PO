//
// Created by wojtek on 13.11.2020.
//

#ifndef PROJEKT_OSTROSLUPCZWOROKATNYPRAWIDLOWY_H
#define PROJEKT_OSTROSLUPCZWOROKATNYPRAWIDLOWY_H


#include <vector>
#include <algorithm>
#include "Kwadrat.h"
#include "Punkt.h"

class OstroslupCzworokatnyPrawidlowy : public Punkt<double>, public Kwadrat {
private:
    double krawedz;

    void obliczKrawedz();

protected:
    double objetosc;

    void obliczObwod() override;

    void obliczPole() override;

public:

    OstroslupCzworokatnyPrawidlowy(int kolor, std::string &nazwa, double bokPodstawy,
                                   double wysokosc);
    OstroslupCzworokatnyPrawidlowy(int kolor, std::string &nazwa, double bokPodstawy,
                                   double wysokosc, int id);

    void ustawBok(double bok) override;

    void ustawWysokosc(double wysokosc);

    void modifykuj() override;

    void wypiszDane() override;

    void obliczObjetosc();

    void zapiszDoPliku(std::ofstream &plik) override;

    static std::vector<OstroslupCzworokatnyPrawidlowy *> liscie;

    static OstroslupCzworokatnyPrawidlowy *znajdzNaLiscie(std::string &nazwa);

    static bool usunZListy(std::string &nazwa);

    static void wypiszWszystkie();
};


#endif //PROJEKT_OSTROSLUPCZWOROKATNYPRAWIDLOWY_H
