#include <iostream>
#include "Rownoboczny.h"
#include "OstroslupTrojkatnyPrawidlowy.h"
#include "InneTrojkaty.h"
#include "MenedzerFigur.h"

int FiguryGeometryczne::licznik = 0;

int main() {
    MenedzerFigur menedzerFigur;
    menedzerFigur.dodajRownoboczny();
    menedzerFigur.dodajRownoboczny();
    menedzerFigur.usunRownoboczny();
    return 0;
}
