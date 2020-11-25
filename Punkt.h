//
// Created by wojtek on 12.11.2020.
//

#ifndef PROJEKT_PUNKT_H
#define PROJEKT_PUNKT_H

#include <string>
#include <ctgmath>
#include "FiguryGeometryczne.h"

template<typename T>
class Punkt : public virtual FiguryGeometryczne {
private:
    // dodaj cos
protected:
    T x;
    T y;
    T z;
public:
    void ustawNoweKoordynaty(T x, T y, T z) {
        Punkt::x = x;
        Punkt::y = y;
        Punkt::z = z;
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    T getZ() const {
        return z;
    }

    Punkt(int kolor, std::string &nazwa, T x, T y, T z) : FiguryGeometryczne(kolor, nazwa), x(x),
                                                             y(y), z(z) {}

};

#endif //PROJEKT_PUNKT_H
