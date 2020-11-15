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
    std::string etykieta;
protected:
    T x;
    T y;
    T z;
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

    const std::string &getEtykieta() const {
        return etykieta;
    }

    Punkt(int kolor, std::string &etykieta, T x, T y, T z) : FiguryGeometryczne(kolor), etykieta(etykieta), x(x),
                                                             y(y), z(z) {}

    double odleglosc(Punkt<T> *punkt) {
        double xDist = Punkt::x - punkt->x;
        double yDist = Punkt::y - punkt->y;
        double zDist = Punkt::z - punkt->z;
        return sqrt(pow(xDist, 2) + pow(yDist, 2) + pow(zDist, 2));
    }

    Punkt *operator+=(Punkt<T> const &obj) {
        this->x += obj.getX();
        this->y += obj.getY();
        this->z += obj.getZ();
        return this;
    }
};

#endif //PROJEKT_PUNKT_H
