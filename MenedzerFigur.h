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
#include <set>
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
    std::vector<Rownoboczny *> liscieRownoboczny;
    std::vector<InneTrojkaty *> liscieInneTrojkaty;
    std::vector<OstroslupTrojkatnyPrawidlowy *> liscieOstroslupTrojkatnyPrawidlowy;
    std::vector<InneCzworokaty *> liscieInneCzworokaty;
    std::vector<OstroslupCzworokatnyPrawidlowy *> liscieOstroslupCzworokatnyPrawidlowy;

public:
    void dodajOstroslupCzworokatnyPrawidlowy(int kolor,
                                             std::string &nazwa,
                                             double bokPodstawy,
                                             double wysokosc,
                                             int id = -1) {
        auto *ostroslupCzworokatnyPrawidlowy =
                new OstroslupCzworokatnyPrawidlowy(kolor, nazwa, bokPodstawy, wysokosc);

        if (id > 0) ostroslupCzworokatnyPrawidlowy->setId(id);

        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
    }

    void dodajRownoboczny(int kolor, std::string &nazwa, double bok, int id = -1) {
        auto *rownoboczny = new Rownoboczny(kolor, nazwa, bok);

        if (id > 0) rownoboczny->setId(id);

        liscieRownoboczny.push_back(rownoboczny);
    }

    void dodajInneTrojkaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC,
                           int id = -1) {
        auto *inneTrojkaty = new InneTrojkaty(kolor, nazwa, bokA, bokB, bokC);

        if (id > 0) inneTrojkaty->setId(id);

        liscieInneTrojkaty.push_back(inneTrojkaty);
    }

    void dodajOstroslupTrojkatnyPrawidlowy(int kolor,
                                           std::string nazwa,
                                           double bokPodstawy,
                                           double wysokosc,
                                           int id = -1) {
        auto *ostroslupTrojkatnyPrawidlowy =
                new OstroslupTrojkatnyPrawidlowy(kolor, nazwa, bokPodstawy, wysokosc);

        if (id > 0) ostroslupTrojkatnyPrawidlowy->setId(id);

        liscieOstroslupTrojkatnyPrawidlowy.push_back(ostroslupTrojkatnyPrawidlowy);
    }

    void
    dodajInneCzworokaty(int kolor, std::string nazwa, double bokA, double bokB, double bokC, double bokD, int id = -1
    ) {
        auto *inneCzworokaty = new InneCzworokaty(kolor, nazwa, bokA, bokB, bokC, bokD);

        if (id > 0) inneCzworokaty->setId(id);

        liscieInneCzworokaty.push_back(inneCzworokaty);
    }

    bool usunInneCzworokaty(std::string &nazwa) {
        InneCzworokaty *innyCzworokat = znajdzCzworokat(nazwa);

        if (innyCzworokat == nullptr) return false;

        liscieInneCzworokaty.erase(std::remove(liscieInneCzworokaty.begin(), liscieInneCzworokaty.end(), innyCzworokat),
                                   liscieInneCzworokaty.end());
        return true;
    }

    InneCzworokaty *znajdzCzworokat(std::string &nazwa) const {
        InneCzworokaty *innyCzworokat = nullptr;
        for (auto &element : liscieInneCzworokaty) {
            if (element->getNazwa() == nazwa) {
                innyCzworokat = element;
            }
        }
        return innyCzworokat;
    }


    bool usunOstroslupTrojkatnyPrawidlowy(std::string &nazwa) {
        OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy = znajdzOstroslupTrojkatnyPrawidlowy(nazwa);
        if (ostroslupTrojkatnyPrawidlowy == nullptr) return false;

        liscieOstroslupTrojkatnyPrawidlowy.erase(
                std::remove(liscieOstroslupTrojkatnyPrawidlowy.begin(), liscieOstroslupTrojkatnyPrawidlowy.end(),
                            ostroslupTrojkatnyPrawidlowy),
                liscieOstroslupTrojkatnyPrawidlowy.end());
        return true;
    }

    OstroslupTrojkatnyPrawidlowy *znajdzOstroslupTrojkatnyPrawidlowy(std::string &nazwa) const {
        OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy = nullptr;
        for (auto &element : liscieOstroslupTrojkatnyPrawidlowy) {
            if (element->getNazwa() == nazwa) {
                ostroslupTrojkatnyPrawidlowy = element;
            }
        }
        return ostroslupTrojkatnyPrawidlowy;
    }

    bool usunInneTrojkaty(std::string &nazwa) {
        InneTrojkaty *inneTrojkaty = znajdzInneTrojkaty(nazwa);
        if (inneTrojkaty == nullptr) return false;

        liscieInneTrojkaty.erase(std::remove(liscieInneTrojkaty.begin(), liscieInneTrojkaty.end(), inneTrojkaty),
                                 liscieInneTrojkaty.end());
        return true;
    }

    InneTrojkaty *znajdzInneTrojkaty(std::string &nazwa) const {
        InneTrojkaty *inneTrojkaty = nullptr;
        for (auto &element : liscieInneTrojkaty) {
            if (element->getNazwa() == nazwa) {
                inneTrojkaty = element;
            }
        }
        return inneTrojkaty;
    }

    bool usunRownoboczny(std::string &nazwa) {
        Rownoboczny *rownoboczny = znajdzRownoboczny(nazwa);
        if (rownoboczny == nullptr) return false;

        liscieRownoboczny.erase(std::remove(liscieRownoboczny.begin(), liscieRownoboczny.end(), rownoboczny),
                                liscieRownoboczny.end());
        return true;
    }

    Rownoboczny *znajdzRownoboczny(std::string &nazwa) const {
        Rownoboczny *rownoboczny = nullptr;
        for (auto &element : liscieRownoboczny) {
            if (element->getNazwa() == nazwa) {
                rownoboczny = element;
            }
        }
        return rownoboczny;
    }

    bool usunOstroslupCzworokatnyPrawidlowy(std::string &nazwa) {
        OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = znajdzOstroslupCzworokatnyPrawidlowy(nazwa);
        if (ostroslupCzworokatnyPrawidlowy == nullptr) return false;

        liscieOstroslupCzworokatnyPrawidlowy.erase(
                std::remove(liscieOstroslupCzworokatnyPrawidlowy.begin(), liscieOstroslupCzworokatnyPrawidlowy.end(),
                            ostroslupCzworokatnyPrawidlowy),
                liscieOstroslupCzworokatnyPrawidlowy.end());
        return true;
    }

    OstroslupCzworokatnyPrawidlowy *znajdzOstroslupCzworokatnyPrawidlowy(std::string &nazwa) {
        OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = nullptr;
        for (auto &element : liscieOstroslupCzworokatnyPrawidlowy) {
            if (element->getNazwa() == nazwa) {
                ostroslupCzworokatnyPrawidlowy = element;
            }
        }
        return ostroslupCzworokatnyPrawidlowy;
    }

    FiguryGeometryczne *znajdzFigure(std::string &nazwa) {
        FiguryGeometryczne *figura = nullptr;
        std::vector<FiguryGeometryczne *> *liscie = getLiscie();
        for (auto &element : liscieInneCzworokaty) {
            if (element->getNazwa() == nazwa) {
                figura = element;
            }
        }
        delete liscie;
        return figura;
    }

    virtual ~MenedzerFigur() {
        std::vector<FiguryGeometryczne *> * liscie = getLiscie();
        for (auto &element : *liscie) {
            delete element;
        }
        delete liscie;
    }

    void odczytajZPliku(std::string &nazwaPliku) {
        std::ifstream plik;
        plik.open(nazwaPliku);
        std::string typ;
        int maxId = 0;
        int id, kolor;
        std::string nazwa;
        while (plik >> typ) {
            if (typ == "OstroslupTrojkatnyPrawidlowy") {
                double bok, wysokosc;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bok;
                plik >> wysokosc;
                if (id > maxId) maxId = id;
                dodajOstroslupTrojkatnyPrawidlowy(kolor, nazwa, bok, wysokosc, id);
            } else if (typ == "OstroslupCzworokatnyPrawidlowy") {
                double bok, wysokosc;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bok;
                plik >> wysokosc;
                if (id > maxId) maxId = id;
                dodajOstroslupCzworokatnyPrawidlowy(kolor, nazwa, bok, wysokosc, id);
            } else if (typ == "InneTrojkaty") {
                double bokA, bokB, bokC;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bokA;
                plik >> bokB;
                plik >> bokC;
                if (id > maxId) maxId = id;
                dodajInneTrojkaty(kolor, nazwa, bokA, bokB, bokC, id);
            } else if (typ == "InneCzworokaty") {
                double bokA, bokB, bokC, bokD;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bokA;
                plik >> bokB;
                plik >> bokC;
                plik >> bokD;
                if (id > maxId) maxId = id;
                dodajInneCzworokaty(kolor, nazwa, bokA, bokB, bokC, bokD, id);
            } else if (typ == "Rownoboczny") {
                double bok;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bok;
                if (id > maxId) maxId = id;
                dodajRownoboczny(kolor, nazwa, bok, id);
            }
        }
        FiguryGeometryczne::ustawLicznik(maxId + 1);
    }

    void zapiszDoPliku(std::string &nazwa) {
        std::ofstream plik;
        plik.open(nazwa);
        std::vector<FiguryGeometryczne *> * liscie = getLiscie();
        for (auto element : *liscie) {
            element->zapiszDoPliku(plik);
        }
        delete liscie;
        plik.close();
    }

    std::vector<FiguryGeometryczne *> *getLiscie() {
        std::set<FiguryGeometryczne *> set;
        for (auto element : liscieRownoboczny) set.insert(element);
        for (auto element : liscieInneTrojkaty) set.insert(element);
        for (auto element : liscieOstroslupTrojkatnyPrawidlowy) set.insert(element);
        for (auto element : liscieInneCzworokaty) set.insert(element);
        for (auto element : liscieOstroslupCzworokatnyPrawidlowy) set.insert(element);
        auto *liscie = new std::vector<FiguryGeometryczne*>(set.begin(), set.end());
        return liscie;
    }

    std::vector<Punkt<double> *> *getLisciePunkt() {
        std::set<Punkt<double> *> set;
        for (auto element : liscieOstroslupTrojkatnyPrawidlowy) set.insert(element);
        for (auto element : liscieOstroslupCzworokatnyPrawidlowy) set.insert(element);
        auto *liscie = new std::vector<Punkt<double> *>(set.begin(), set.end());
        return liscie;
    }

    std::vector<Trojkat *> *getLiscieTrojkat() {
        std::set<Trojkat *> set;
        for (auto element : liscieRownoboczny) set.insert(element);
        for (auto element : liscieInneTrojkaty) set.insert(element);
        for (auto element : liscieOstroslupTrojkatnyPrawidlowy) set.insert(element);
        auto *liscie = new std::vector<Trojkat*>(set.begin(), set.end());
        return liscie;
    }

    const std::vector<Czworokat *> *getLiscieCzworokat() {
        std::set<Czworokat *> set;
        for (auto element : liscieInneCzworokaty) set.insert(element);
        for (auto element : liscieOstroslupCzworokatnyPrawidlowy) set.insert(element);
        auto *liscie = new std::vector<Czworokat *>(set.begin(), set.end());
        return liscie;
    }

    const std::vector<Kwadrat *> *getLiscieKwadrat() {
        auto *liscie = new std::vector<Kwadrat *>();
        for (auto element : liscieOstroslupCzworokatnyPrawidlowy) liscie->push_back(element);
        return liscie;
    }

    const std::vector<Rownoboczny *> &getLiscieRownoboczny() const {
        return liscieRownoboczny;
    }

    const std::vector<InneTrojkaty *> &getLiscieInneTrojkaty() const {
        return liscieInneTrojkaty;
    }

    const std::vector<OstroslupTrojkatnyPrawidlowy *> &getLiscieOstroslupTrojkatnyPrawidlowy() const {
        return liscieOstroslupTrojkatnyPrawidlowy;
    }

    const std::vector<InneCzworokaty *> &getLiscieInneCzworokaty() const {
        return liscieInneCzworokaty;
    }

    const std::vector<OstroslupCzworokatnyPrawidlowy *> &getLiscieOstroslupCzworokatnyPrawidlowy() const {
        return liscieOstroslupCzworokatnyPrawidlowy;
    }
};


#endif //PROJEKT_MENEDZERFIGUR_H
