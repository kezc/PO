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

        std::cout << "Podaj kolor";
        std::cin >> kolor;
        std::cout << "Podaj długość boku";
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc";
        std::cin >> wysokosc;

        OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = new OstroslupCzworokatnyPrawidlowy(kolor,
                                                                                                            bokPodstawy,
                                                                                                            wysokosc);
        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        lisciePunkt.push_back(ostroslupCzworokatnyPrawidlowy);
        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
    }

    void dodajRownoboczny() {
        double bok;
        int kolor;

        std::cout << "Podaj kolor";
        std::cin >> kolor;
        std::cout << "Podaj długość boku";
        std::cin >> bok;

        Rownoboczny *rownoboczny = new Rownoboczny(kolor, bok);

        liscieRownoboczny.push_back(rownoboczny);
        liscieTrojkat.push_back(rownoboczny);
        liscie.push_back(rownoboczny);
    }

    void dodajInneTrojkaty() {
        double bokA, bokB, bokC;
        int kolor;

        std::cout << "Podaj kolor";
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c";
        std::cin >> bokA >> bokB >> bokC;

        InneTrojkaty *inneTrojkaty = new InneTrojkaty(kolor, bokA, bokB, bokC);
        liscieInneTrojkaty.push_back(inneTrojkaty);
        liscieTrojkat.push_back(inneTrojkaty);
        liscie.push_back(inneTrojkaty);
    }

    void dodajOstroslupTrojkatnyPrawidlowy() {
        int kolor;
        double bokPodstawy;
        double wysokosc;

        std::cout << "Podaj kolor";
        std::cin >> kolor;
        std::cout << "Podaj długość boku";
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc";
        std::cin >> wysokosc;

        OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy = new OstroslupTrojkatnyPrawidlowy(kolor,
                                                                                                      bokPodstawy,
                                                                                                      wysokosc);
        liscieOstroslupTrojkatnyPrawidlowy.push_back(ostroslupTrojkatnyPrawidlowy);
        lisciePunkt.push_back(ostroslupTrojkatnyPrawidlowy);
        liscieTrojkat.push_back(ostroslupTrojkatnyPrawidlowy);
    }

    void dodajInneCzworokaty() {
        double bokA, bokB, bokC, bokD;
        int kolor;

        std::cout << "Podaj kolor";
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c";
        std::cin >> bokA >> bokB >> bokC >> bokD;

        InneCzworokaty *inneCzworokaty = new InneCzworokaty(kolor, bokA, bokB, bokC, bokD);
        liscieInneCzworokaty.push_back(inneCzworokaty);
        liscieCzworokat.push_back(inneCzworokaty);
        liscie.push_back(inneCzworokaty);
    }

    void usunInneCzworokaty() {
        int id;
        InneCzworokaty *innyCzworokat;
        std::cout << "Podaj id";
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
        std::cout << "Podaj id";
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
        std::cout << "Podaj id";
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
        std::cout << "Podaj id";
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
        std::cout << "Podaj id";
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

};


#endif //PROJEKT_MENEDZERFIGUR_H
