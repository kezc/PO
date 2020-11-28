//
// Created by wojtek on 11.11.2020.
//

#ifndef PROJEKT_CZWOROKAT_H
#define PROJEKT_CZWOROKAT_H

#include "FiguryGeometryczne.h"

class Czworokat : public virtual FiguryGeometryczne {
private:
    double obwod;
protected:
    double bokA, bokB, bokC, bokD;

    void ustawObwod(double obwod);

public:
    virtual void obliczObwod();

    double getObwod();

    void ustawBoki(double bokA, double bokB, double bokC, double bokD);

    Czworokat(int kolor, std::string &nazwa, double bokA, double bokB, double bokC, double bokD);
};


#endif //PROJEKT_CZWOROKAT_H
