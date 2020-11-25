//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_ROWNOBOCZNY_H
#define PROJEKT_ROWNOBOCZNY_H


#include <ctgmath>
#include "Trojkat.h"

class Rownoboczny : public Trojkat {
private:
    double promienOkreguOpisanego;
protected:
    double wysokosc;

//    void obliczObwod() override;
//
//    void obliczPole() override;

    void obliczWysokosc();

    void obliczPromienOkreguOpisanego();

public:
    Rownoboczny(int kolor,std::string &nazwa, double bok);

    void ustawBok(double bok);

    double getWysokosc() const;

    double getPromienOkreguOpisanego() const;

    void modifykuj() override;

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;
};


#endif //PROJEKT_ROWNOBOCZNY_H
