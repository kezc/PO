#ifndef PROJEKT_KONSOLA_H
#define PROJEKT_KONSOLA_H

#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <algorithm>
#include <cctype>
#include <string>
#include "FiguryGeometryczne.h"
#include "OstroslupCzworokatnyPrawidlowy.h"
#include "OstroslupTrojkatnyPrawidlowy.h"
#include "Rownoboczny.h"
#include "InneTrojkaty.h"
#include "InneCzworokaty.h"

enum class Wezel {
    FiguryGeometryczne,
    Punkt,
    Trojkat,
    Czworokat,
    Rownoboczny,
    InneTrojkaty,
    Kwadrat,
    InneCzworokaty,
    OstroslupTrojkatnyPrawidlowy,
    OstroslupCzworokatnyPrawidlowy
};

class Konsola {
    Wezel aktualnyWezel = Wezel::FiguryGeometryczne;

    void zmienWezel();

    static void wypiszStrukture();

    void wypiszObiektyZAktualnegoWezla();

    void utworzObiektDlaAktualnegoLiscia();

    void wypiszSzczegolyDlaObiektuZLiscia();

    void modyfikujObiektZLiscia();

    void usunObiektZLiscia();

    void dodajOstroslupCzworokatnyPrawidlowy(std::string &nazwa);

    void dodajRownoboczny(std::string &nazwa);

    void dodajInneTrojkaty(std::string &nazwa);

    void dodajOstroslupTrojkatnyPrawidlowy(std::string &nazwa);

    void dodajInneCzworokaty(std::string &nazwa);

    void wypiszPunkty();

    void wypiszTrojkaty();

    void wypiszCzworokaty();

    void wypiszKwadraty();

    void wypiszWszystko();

    void wczytajFigury();

    void zapiszFigury();

    std::string aktualnyWezelJakoString();

    FiguryGeometryczne *znajdzFigure(std::string &nazwa);

    void odczytajZPliku(std::string &nazwaPliku);

    void zapiszDoPliku(std::string &nazwa);

    std::vector<FiguryGeometryczne *> *getLiscie();

    std::vector<Punkt<double> *> *getLisciePunkt();

    std::vector<Trojkat *> *getLiscieTrojkat();

    std::vector<Czworokat *> *getLiscieCzworokat();

    std::vector<Kwadrat *> *getLiscieKwadrat();


public:
    void start();

    virtual ~Konsola();
};


#endif //PROJEKT_KONSOLA_H
