#include <iostream>
#include <fstream>
#include "Rownoboczny.h"
#include "OstroslupTrojkatnyPrawidlowy.h"
#include "InneTrojkaty.h"
#include "MenedzerFigur.h"
#include "Konsola.h"

int FiguryGeometryczne::licznik = 0;

int main() {
    Konsola konsola;
    konsola.wczytajFigury();
    konsola.wypiszWszystko();
    konsola.zmienWezel();
    konsola.wypiszObiektyZAktualnegoWezla();
    konsola.wypiszSzczegolyDlaObiektuZLisciaPoId();
    konsola.wypiszSzczegolyDlaObiektuZLisciaPoId();

    return 0;
}
