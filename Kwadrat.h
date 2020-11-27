#ifndef PROJEKT_KWADRAT_H
#define PROJEKT_KWADRAT_H


#include "Czworokat.h"

class Kwadrat : public Czworokat {
private:
    double przekatna;
protected:
    double pole;

    virtual void obliczPole();

public:

    virtual void ustawBok(double bok);

    Kwadrat(int kolor,std::string &nazwa, double bok);

    void obliczPrzekatna();

    double getPrzekatna();
};


#endif //PROJEKT_KWADRAT_H
