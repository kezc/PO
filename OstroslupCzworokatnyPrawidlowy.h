//
// Created by wojtek on 13.11.2020.
//

#ifndef PROJEKT_OSTROSLUPCZWOROKATNYPRAWIDLOWY_H
#define PROJEKT_OSTROSLUPCZWOROKATNYPRAWIDLOWY_H


#include "Kwadrat.h"
#include "Punkt.h"

class OstroslupCzworokatnyPrawidlowy : public Punkt<double>, public Kwadrat {
private:
    double krawedz;

    void obliczKrawedz();

protected:
    double wysokosc;
    double objetosc;

    void obliczObwod() override;

    void obliczPole() override;

public:

    OstroslupCzworokatnyPrawidlowy(int kolor, std::string &etykietaWierzcholka, double bokPodstawy,
                                   double wysokosc);

    void ustawBok(double bok) override;

    void ustawWysokosc(double wysokosc);

    void modifykuj() override;

    void wypiszDane() override;

    void obliczObjetosc();

    void zapiszDoPliku(std::ofstream &plik) override;
};


#endif //PROJEKT_OSTROSLUPCZWOROKATNYPRAWIDLOWY_H
