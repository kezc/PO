//
// Created by wojtek on 10.11.2020.
//

#ifndef PROJEKT_TROJKAT_H
#define PROJEKT_TROJKAT_H


#include "FiguryGeometryczne.h"

class Trojkat : public virtual FiguryGeometryczne {
private:
    double obwod;
protected:
    double bokA, bokB, bokC, pole;

    virtual void obliczObwod();

    virtual void obliczPole();

    void ustawObwod(double obwod);

    virtual void ustawBoki(double bokA, double bokB, double bokC);
public:
    Trojkat(int kolor, std::string &nazwa, double bokA, double bokB, double bokC);

    double getObwod();


};


#endif //PROJEKT_TROJKAT_H
