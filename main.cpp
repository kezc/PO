#include <iostream>
#include "Rownoboczny.h"
#include "OstroslupTrojkatnyPrawidlowy.h"
#include "InneTrojkaty.h"

int FiguryGeometryczne::licznik = 0;

int main() {
    FiguryGeometryczne::ustawLicznik(5);
//    OstroslupTrojkatnyPrawidlowy a(0, 5, 3);
    OstroslupTrojkatnyPrawidlowy b(0, 5, 3);
    InneTrojkaty c(0, 5, 5, 5);
    Rownoboczny d(0, 5);
//    std::cout << a.getObwod() << std::endl;
    std::cout << b.getPole() << std::endl;
    std::cout << c.getPole() << std::endl;
    std::cout << d.getPole() << std::endl;
    return 0;
}
