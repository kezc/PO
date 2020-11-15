#include <iostream>
#include <fstream>
#include "Rownoboczny.h"
#include "OstroslupTrojkatnyPrawidlowy.h"
#include "InneTrojkaty.h"
#include "MenedzerFigur.h"

int FiguryGeometryczne::licznik = 0;

int main() {
    MenedzerFigur menedzerFigur;

//    menedzerFigur.dodajRownoboczny();
//    menedzerFigur.dodajInneCzworokaty();
//    menedzerFigur.dodajInneTrojkaty();
//    menedzerFigur.dodajOstroslupCzworokatnyPrawidlowy();
//    menedzerFigur.dodajOstroslupTrojkatnyPrawidlowy();
//
//    menedzerFigur.zapiszDoPliku();
    menedzerFigur.odczytajZPliku();
    menedzerFigur.wypiszTrojkatyRownoboczne();
//    menedzerFigur.wypiszInneCzworokaty();
    menedzerFigur.wypiszInneTrojkaty();
//    menedzerFigur.wypiszOstroslupyCzworokatnePrawidlowe();
    menedzerFigur.wypiszOstroslupyTrojkatnePrawidlowe();
    return 0;
}
