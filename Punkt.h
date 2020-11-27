#ifndef PROJEKT_PUNKT_H
#define PROJEKT_PUNKT_H

#include <string>
#include <ctgmath>
#include "FiguryGeometryczne.h"

template<typename T>
class Punkt : public virtual FiguryGeometryczne {
private:
    double odlegloscOdSrodkaUkladu;
protected:
    T x;
    T y;
    T z;
public:
    void ustawNoweKoordynaty(T x, T y, T z) {
        Punkt::x = x;
        Punkt::y = y;
        Punkt::z = z;
        obliczOdlegloscOdSrodkaUkladu();
    }

    void obliczOdlegloscOdSrodkaUkladu() {
        odlegloscOdSrodkaUkladu = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    double getOdlegloscOdSrodkaUkladu() {
        return odlegloscOdSrodkaUkladu;
    }

    Punkt(int kolor, std::string &nazwa, T x, T y, T z) : FiguryGeometryczne(kolor, nazwa), x(x),
                                                          y(y), z(z) {
        obliczOdlegloscOdSrodkaUkladu();
    }

};

#endif //PROJEKT_PUNKT_H
