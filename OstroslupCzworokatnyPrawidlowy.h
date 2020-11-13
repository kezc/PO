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

    void obliczObwod() override;

    void obliczPole() override;

public:

    OstroslupCzworokatnyPrawidlowy(int kolor, double bokPodstawy,
                                   double wysokosc);

    void ustawBok(double bok);

    void ustawWysokosc(double wysokosc);

};


#endif //PROJEKT_OSTROSLUPCZWOROKATNYPRAWIDLOWY_H
