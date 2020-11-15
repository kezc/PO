//
// Created by wojtek on 14.11.2020.
//

#ifndef PROJEKT_MENEDZERFIGUR_H
#define PROJEKT_MENEDZERFIGUR_H

#include <type_traits>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Punkt.h"
#include "Trojkat.h"
#include "Czworokat.h"
#include "OstroslupCzworokatnyPrawidlowy.h"
#include "OstroslupTrojkatnyPrawidlowy.h"
#include "Rownoboczny.h"
#include "InneTrojkaty.h"
#include "InneCzworokaty.h"

class MenedzerFigur {
private:
    std::string aktualnyWezel = "FiguryGeometryczne";
    std::vector<FiguryGeometryczne *> liscie;
    std::vector<Punkt<double> *> lisciePunkt;
    std::vector<Trojkat *> liscieTrojkat;
    std::vector<Czworokat *> liscieCzworokat;
    std::vector<Rownoboczny *> liscieRownoboczny;
    std::vector<InneTrojkaty *> liscieInneTrojkaty;
    std::vector<OstroslupTrojkatnyPrawidlowy *> liscieOstroslupTrojkatnyPrawidlowy;
    std::vector<Kwadrat *> liscieKwadrat;
    std::vector<InneCzworokaty *> liscieInneCzworokaty;
    std::vector<OstroslupCzworokatnyPrawidlowy *> liscieOstroslupCzworokatnyPrawidlowy;

public:
    void dodajOstroslupCzworokatnyPrawidlowy() {
        int kolor;
        double bokPodstawy;
        double wysokosc;
        std::string etykietaWierzcholka;

        std::cout << "Podaj etykiete wierzcholka";
        std::cin >> etykietaWierzcholka;
        std::cout << "Podaj kolor";
        std::cin >> kolor;
        std::cout << "Podaj długość boku";
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc";
        std::cin >> wysokosc;

        auto *ostroslupCzworokatnyPrawidlowy =
                new OstroslupCzworokatnyPrawidlowy(kolor, etykietaWierzcholka, bokPodstawy, wysokosc);
        dodajOstroslupCzworokatnyPrawidlowyDoList(ostroslupCzworokatnyPrawidlowy);
    }

    void dodajRownoboczny() {
        double bok;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bok;

        auto *rownoboczny = new Rownoboczny(kolor, bok);

        dodajRownobocznyDoList(rownoboczny);
    }

    void dodajInneTrojkaty() {
        double bokA, bokB, bokC;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c" << std::endl;
        std::cin >> bokA >> bokB >> bokC;

        auto *inneTrojkaty = new InneTrojkaty(kolor, bokA, bokB, bokC);
        dodajInneTrojkatyDoList(inneTrojkaty);
    }

    void dodajOstroslupTrojkatnyPrawidlowy() {
        int kolor;
        double bokPodstawy;
        double wysokosc;
        std::string etykietaWierzcholka;

        std::cout << "Podaj etykiete wierzcholka";
        std::cin >> etykietaWierzcholka;
        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc" << std::endl;
        std::cin >> wysokosc;

        auto *ostroslupTrojkatnyPrawidlowy =
                new OstroslupTrojkatnyPrawidlowy(kolor, etykietaWierzcholka, bokPodstawy, wysokosc);
        dodajOstroslupTrojkatnyPrawidlowyDoList(ostroslupTrojkatnyPrawidlowy);
    }

    void dodajInneCzworokaty() {
        double bokA, bokB, bokC, bokD;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c d" << std::endl;
        std::cin >> bokA >> bokB >> bokC >> bokD;

        auto *inneCzworokaty = new InneCzworokaty(kolor, bokA, bokB, bokC, bokD);
        dodajInneCzworokatyDoList(inneCzworokaty);
    }

    void dodajOstroslupCzworokatnyPrawidlowyDoList(OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy) {
        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        lisciePunkt.push_back(ostroslupCzworokatnyPrawidlowy);
        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        liscie.push_back(ostroslupCzworokatnyPrawidlowy);
    }

    void dodajRownobocznyDoList(Rownoboczny *rownoboczny) {
        liscieRownoboczny.push_back(rownoboczny);
        liscieTrojkat.push_back(rownoboczny);
        liscie.push_back(rownoboczny);
    }

    void dodajInneTrojkatyDoList(InneTrojkaty *inneTrojkaty) {
        liscieInneTrojkaty.push_back(inneTrojkaty);
        liscieTrojkat.push_back(inneTrojkaty);
        liscie.push_back(inneTrojkaty);
    }

    void dodajOstroslupTrojkatnyPrawidlowyDoList(OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy) {
        liscieOstroslupTrojkatnyPrawidlowy.push_back(ostroslupTrojkatnyPrawidlowy);
        lisciePunkt.push_back(ostroslupTrojkatnyPrawidlowy);
        liscieTrojkat.push_back(ostroslupTrojkatnyPrawidlowy);
        liscie.push_back(ostroslupTrojkatnyPrawidlowy);
    }

    void dodajInneCzworokatyDoList(InneCzworokaty *inneCzworokaty) {
        liscieInneCzworokaty.push_back(inneCzworokaty);
        liscieCzworokat.push_back(inneCzworokaty);
        liscie.push_back(inneCzworokaty);
    }

    void usunInneCzworokaty() {
        int id;
        InneCzworokaty *innyCzworokat;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        for (auto &element : liscieInneCzworokaty) {
            if (element->getId() == id) {
                innyCzworokat = element;
            }
        }
        liscieInneCzworokaty.erase(std::remove(liscieInneCzworokaty.begin(), liscieInneCzworokaty.end(), innyCzworokat),
                                   liscieInneCzworokaty.end());
        liscieCzworokat.erase(
                std::remove(liscieCzworokat.begin(), liscieCzworokat.end(), innyCzworokat),
                liscieCzworokat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), innyCzworokat),
                     liscie.end());
    }


    void usunOstroslupTrojkatnyPrawidlowy() {
        int id;
        OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        for (auto &element : liscieOstroslupTrojkatnyPrawidlowy) {
            if (element->getId() == id) {
                ostroslupTrojkatnyPrawidlowy = element;
            }
        }
        liscieOstroslupTrojkatnyPrawidlowy.erase(
                std::remove(liscieOstroslupTrojkatnyPrawidlowy.begin(), liscieOstroslupTrojkatnyPrawidlowy.end(),
                            ostroslupTrojkatnyPrawidlowy),
                liscieOstroslupTrojkatnyPrawidlowy.end());
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), ostroslupTrojkatnyPrawidlowy),
                            liscieTrojkat.end());
        lisciePunkt.erase(std::remove(lisciePunkt.begin(), lisciePunkt.end(), ostroslupTrojkatnyPrawidlowy),
                          lisciePunkt.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), ostroslupTrojkatnyPrawidlowy),
                     liscie.end());
    }

    void usunInneTrojkaty() {
        int id;
        InneTrojkaty *inneTrojkaty;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        for (auto &element : liscieInneTrojkaty) {
            if (element->getId() == id) {
                inneTrojkaty = element;
            }
        }
        liscieInneTrojkaty.erase(std::remove(liscieInneTrojkaty.begin(), liscieInneTrojkaty.end(), inneTrojkaty),
                                 liscieInneTrojkaty.end());
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), inneTrojkaty),
                            liscieTrojkat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), inneTrojkaty),
                     liscie.end());
    }

    void usunRownoboczny() {
        int id;
        Rownoboczny *rownoboczny;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        for (auto &element : liscieRownoboczny) {
            if (element->getId() == id) {
                rownoboczny = element;
            }
        }
        liscieRownoboczny.erase(std::remove(liscieRownoboczny.begin(), liscieRownoboczny.end(), rownoboczny),
                                liscieRownoboczny.end());
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), rownoboczny),
                            liscieTrojkat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), rownoboczny),
                     liscie.end());
    }

    void usunOstroslupCzworokatnyPrawidlowy() {
        int id;
        OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        for (auto &element : liscieOstroslupCzworokatnyPrawidlowy) {
            if (element->getId() == id) {
                ostroslupCzworokatnyPrawidlowy = element;
            }
        }
        liscieOstroslupCzworokatnyPrawidlowy.erase(
                std::remove(liscieOstroslupCzworokatnyPrawidlowy.begin(), liscieOstroslupCzworokatnyPrawidlowy.end(),
                            ostroslupCzworokatnyPrawidlowy),
                liscieOstroslupCzworokatnyPrawidlowy.end());
        liscieKwadrat.erase(std::remove(liscieKwadrat.begin(), liscieKwadrat.end(), ostroslupCzworokatnyPrawidlowy),
                            liscieKwadrat.end());
        liscieCzworokat.erase(
                std::remove(liscieCzworokat.begin(), liscieCzworokat.end(), ostroslupCzworokatnyPrawidlowy),
                liscieCzworokat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), ostroslupCzworokatnyPrawidlowy),
                     liscie.end());
    }

    void wypiszTrojkatyRownoboczne() {
        for (auto &element : liscieRownoboczny) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszInneTrojkaty() {
        for (auto &element : liscieInneTrojkaty) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszInneCzworokaty() {
        for (auto &element : liscieInneCzworokaty) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszOstroslupyTrojkatnePrawidlowe() {
        for (auto &element : liscieOstroslupTrojkatnyPrawidlowy) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszOstroslupyCzworokatnePrawidlowe() {
        for (auto &element : liscieOstroslupCzworokatnyPrawidlowy) {
            std::cout << std::endl;
        }
    }

    virtual ~MenedzerFigur() {
        for (auto &element : liscie) {
            delete element;
        }
    }

    void odczytajZPliku() {
        std::ifstream plik;
        plik.open("baza");
        std::string typ;
        int maxId = 0;
        while (plik >> typ) {
            if (typ == "OstroslupTrojkatnyPrawidlowy") {
                int id, kolor;
                double bok, wysokosc;
                std::string etykietaWierzcholka;
                plik >> id;
                plik >> etykietaWierzcholka;
                plik >> kolor;
                plik >> bok;
                plik >> wysokosc;
                if (id > maxId) maxId = id;
                auto *ostroslupTrojkatnyPrawidlowy =
                        new OstroslupTrojkatnyPrawidlowy(kolor, etykietaWierzcholka, bok, wysokosc);
                ostroslupTrojkatnyPrawidlowy->setId(id);
                dodajOstroslupTrojkatnyPrawidlowyDoList(ostroslupTrojkatnyPrawidlowy);
            } else if (typ == "OstroslupCzworokatnyPrawidlowy") {
                int id, kolor;
                double bok, wysokosc;
                std::string etykietaWierzcholka;
                plik >> id;
                plik >> etykietaWierzcholka;
                plik >> kolor;
                plik >> bok;
                plik >> wysokosc;
                if (id > maxId) maxId = id;
                auto *ostroslupCzworokatnyPrawidlowy =
                        new OstroslupCzworokatnyPrawidlowy(kolor, etykietaWierzcholka, bok, wysokosc);
                ostroslupCzworokatnyPrawidlowy->setId(id);
                dodajOstroslupCzworokatnyPrawidlowyDoList(ostroslupCzworokatnyPrawidlowy);
            } else if (typ == "InneTrojkaty") {
                int id, kolor;
                double bokA, bokB, bokC;
                plik >> id;
                plik >> kolor;
                plik >> bokA;
                plik >> bokB;
                plik >> bokC;
                if (id > maxId) maxId = id;
                auto *innyTrojkat =
                        new InneTrojkaty(kolor, bokA, bokB, bokC);
                innyTrojkat->setId(id);
                dodajInneTrojkatyDoList(innyTrojkat);
            } else if (typ == "InneCzworokaty") {
                int id, kolor;
                double bokA, bokB, bokC, bokD;
                plik >> id;
                plik >> kolor;
                plik >> bokA;
                plik >> bokB;
                plik >> bokC;
                plik >> bokD;
                if (id > maxId) maxId = id;
                auto *innyCzworokat =
                        new InneCzworokaty(kolor, bokA, bokB, bokC, bokD);
                innyCzworokat->setId(id);
                dodajInneCzworokatyDoList(innyCzworokat);
            } else if (typ == "Rownoboczny") {
                int id, kolor;
                double bok;
                plik >> id;
                plik >> kolor;
                plik >> bok;
                if (id > maxId) maxId = id;
                auto *rownoboczny =
                        new Rownoboczny(kolor, bok);
                rownoboczny->setId(id);
                dodajRownobocznyDoList(rownoboczny);
            }
        }
    }

    void zapiszDoPliku() {
        std::ofstream plik;
        plik.open("baza");
        for (auto element : liscie) {
            element->zapiszDoPliku(plik);
        }
        plik.close();
    }
};


#endif //PROJEKT_MENEDZERFIGUR_H
