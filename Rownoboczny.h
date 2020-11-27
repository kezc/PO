#ifndef PROJEKT_ROWNOBOCZNY_H
#define PROJEKT_ROWNOBOCZNY_H


#include <ctgmath>
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

    void ustawBok(double bok);

    void modifykuj() override;

    Rownoboczny *operator++();

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;
};


#endif //PROJEKT_ROWNOBOCZNY_H
