//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_OSTR_TROJ_PR_H
#define PROJEKT_OSTR_TROJ_PR_H


#include "Punkt.h"
#include "Trojkat.h"

class Ostr_troj_pr : public Punkt, public Trojkat {
private:
    double krawedz;

    void obliczKrawedz();

protected:
    double wysokosc;

    void obliczObwod() override;

public:

    Ostr_troj_pr(int kolor, double bokPodstawy, double wysokosc);

    void ustawBok(double bok);

    void ustawWysokosc(double wysokosc);

    int getId() const override;
};


#endif //PROJEKT_OSTR_TROJ_PR_H
