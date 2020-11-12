//
// Created by wojtek on 12.11.2020.
//

#ifndef PROJEKT_PUNKT_H
#define PROJEKT_PUNKT_H

#include <string>
#include <ctgmath>
#include "FiguryGeometryczne.h"

template<typename T>
class Punkt : public FiguryGeometryczne {
protected:
    T x;
    T y;
    T z;
private:
    std::string etykieta;
public:
    const std::string &getName() const {
        return etykieta;
    }

    void ustawEtykiete(const std::string &etykieta) {
        Punkt::etykieta = etykieta;
    }

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

    Punkt(int kolor, T x, T y, T z) : FiguryGeometryczne(kolor), x(x), y(y), z(z) {}

    T odleglosc(Punkt<T> *punkt) {
        double xDist = Punkt::x - punkt->x;
        double yDist = Punkt::y - punkt->y;
        double zDist = Punkt::z - punkt->z;
        return sqrt(pow(xDist, 2) + pow(yDist, 2) + pow(zDist, 2));
        return 5;
    }

    Punkt *operator+=(Punkt<T> const &obj) {
        this->x += obj.getX();
        this->y += obj.getY();
        this->z += obj.getZ();
        return this;
    }
};

#endif //PROJEKT_PUNKT_H
