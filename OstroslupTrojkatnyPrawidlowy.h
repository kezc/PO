//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_OSTROSLUPTROJKATNYPRAWIDLOWY_H
#define PROJEKT_OSTROSLUPTROJKATNYPRAWIDLOWY_H


#include "Trojkat.h"
#include "Punkt.h"

class OstroslupTrojkatnyPrawidlowy : public Punkt<double>, public Trojkat {
private:
    double krawedz;

    void obliczKrawedz();

protected:
    double objetosc;

    void obliczObwod() override;

    void obliczPole() override;

public:
    OstroslupTrojkatnyPrawidlowy(int kolor, std::string &etykietaWierzcholka, double bokPodstawy, double wysokosc);

    void ustawBok(double bok);

    void ustawWysokosc(double wysokosc);

    void obliczObjetosc();

    void modifykuj() override;

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;
};


#endif //PROJEKT_OSTROSLUPTROJKATNYPRAWIDLOWY_H
