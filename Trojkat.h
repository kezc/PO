//
// Created by wojtek on 10.11.2020.
//

#ifndef PROJEKT_TROJKAT_H
#define PROJEKT_TROJKAT_H


#include "FiguryGeometryczne.h"
#include "Punkt.h"

class Trojkat : public FiguryGeometryczne {
private:
protected:
    virtual void obliczObwod();

    double obwod;
    double bokA, bokB, bokC;
public:
    Trojkat(int kolor, double bokA, double bokB, double bokC);

    double getObwod();

    void ustawBoki(double bokA, double bokB, double bokC);
};


#endif //PROJEKT_TROJKAT_H
