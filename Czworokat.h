//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_CZWOROKAT_H
#define PROJEKT_CZWOROKAT_H

#include "FiguryGeometryczne.h"

class Czworokat : public FiguryGeometryczne {
protected:
    int bokA, bokB, bokC, bokD;
    double obwod;
public:
    virtual void obliczObwod();

    double getObwod();

    int getBokA() const;

    int getBokB() const;

    int getBokC() const;

    int getBokD() const;

    void ustawBoki(int bokA, int bokB, int bokC, int bokD);

    Czworokat(int kolor, int bokA, int bokB, int bokC, int bokD);
};


#endif //PROJEKT_CZWOROKAT_H
