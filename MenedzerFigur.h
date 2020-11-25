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
    void dodajOstroslupCzworokatnyPrawidlowy(int kolor,
                                             std::string &nazwa,
                                             double bokPodstawy,
                                             double wysokosc,
                                             int id = -1) {
        auto *ostroslupCzworokatnyPrawidlowy =
                new OstroslupCzworokatnyPrawidlowy(kolor, nazwa, bokPodstawy, wysokosc);

        if (id > 0) ostroslupCzworokatnyPrawidlowy->setId(id);

        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        lisciePunkt.push_back(ostroslupCzworokatnyPrawidlowy);
        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        liscie.push_back(ostroslupCzworokatnyPrawidlowy);
    }

    void dodajRownoboczny(int kolor, std::string &nazwa, double bok, int id = -1) {
        auto *rownoboczny = new Rownoboczny(kolor, nazwa, bok);

        if (id > 0) rownoboczny->setId(id);

        liscieRownoboczny.push_back(rownoboczny);
        liscieTrojkat.push_back(rownoboczny);
        liscie.push_back(rownoboczny);
    }

    void dodajInneTrojkaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC,
                           int id = -1) {
        auto *inneTrojkaty = new InneTrojkaty(kolor, nazwa, bokA, bokB, bokC);

        if (id > 0) inneTrojkaty->setId(id);

        liscieInneTrojkaty.push_back(inneTrojkaty);
        liscieTrojkat.push_back(inneTrojkaty);
        liscie.push_back(inneTrojkaty);
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
        lisciePunkt.push_back(ostroslupTrojkatnyPrawidlowy);
        liscieTrojkat.push_back(ostroslupTrojkatnyPrawidlowy);
        liscie.push_back(ostroslupTrojkatnyPrawidlowy);
    }

    void
    dodajInneCzworokaty(int kolor, std::string nazwa, double bokA, double bokB, double bokC, double bokD, int id = -1
    ) {
        auto *inneCzworokaty = new InneCzworokaty(kolor, nazwa, bokA, bokB, bokC, bokD);

        if (id > 0) inneCzworokaty->setId(id);

        liscieInneCzworokaty.push_back(inneCzworokaty);
        liscieCzworokat.push_back(inneCzworokaty);
        liscie.push_back(inneCzworokaty);
    }

    bool usunInneCzworokaty(std::string &nazwa) {
        InneCzworokaty *innyCzworokat = znajdzCzworokat(nazwa);

        if (innyCzworokat == nullptr) return false;

        liscieInneCzworokaty.erase(std::remove(liscieInneCzworokaty.begin(), liscieInneCzworokaty.end(), innyCzworokat),
                                   liscieInneCzworokaty.end());
        liscieCzworokat.erase(
                std::remove(liscieCzworokat.begin(), liscieCzworokat.end(), innyCzworokat),
                liscieCzworokat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), innyCzworokat),
                     liscie.end());
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
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), ostroslupTrojkatnyPrawidlowy),
                            liscieTrojkat.end());
        lisciePunkt.erase(std::remove(lisciePunkt.begin(), lisciePunkt.end(), ostroslupTrojkatnyPrawidlowy),
                          lisciePunkt.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), ostroslupTrojkatnyPrawidlowy),
                     liscie.end());
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
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), inneTrojkaty),
                            liscieTrojkat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), inneTrojkaty),
                     liscie.end());
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
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), rownoboczny),
                            liscieTrojkat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), rownoboczny),
                     liscie.end());
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
        liscieKwadrat.erase(std::remove(liscieKwadrat.begin(), liscieKwadrat.end(), ostroslupCzworokatnyPrawidlowy),
                            liscieKwadrat.end());
        liscieCzworokat.erase(
                std::remove(liscieCzworokat.begin(), liscieCzworokat.end(), ostroslupCzworokatnyPrawidlowy),
                liscieCzworokat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), ostroslupCzworokatnyPrawidlowy),
                     liscie.end());
        return true;
    }

    OstroslupCzworokatnyPrawidlowy *znajdzOstroslupCzworokatnyPrawidlowy(std::string &nazwa) const {
        OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = nullptr;
        for (auto &element : liscieOstroslupCzworokatnyPrawidlowy) {
            if (element->getNazwa() == nazwa) {
                ostroslupCzworokatnyPrawidlowy = element;
            }
        }
        return ostroslupCzworokatnyPrawidlowy;
    }

    virtual ~MenedzerFigur() {
        for (auto &element : liscie) {
            delete element;
        }
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
                std::string etykietaWierzcholka;
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
                plik >> kolor;
                plik >> nazwa;
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
        for (auto element : liscie) {
            element->zapiszDoPliku(plik);
        }
        plik.close();
    }

    const std::vector<FiguryGeometryczne *> &getLiscie() const {
        return liscie;
    }

    const std::vector<Punkt<double> *> &getLisciePunkt() const {
        return lisciePunkt;
    }

    const std::vector<Trojkat *> &getLiscieTrojkat() const {
        return liscieTrojkat;
    }

    const std::vector<Czworokat *> &getLiscieCzworokat() const {
        return liscieCzworokat;
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

    const std::vector<Kwadrat *> &getLiscieKwadrat() const {
        return liscieKwadrat;
    }

    const std::vector<InneCzworokaty *> &getLiscieInneCzworokaty() const {
        return liscieInneCzworokaty;
    }

    const std::vector<OstroslupCzworokatnyPrawidlowy *> &getLiscieOstroslupCzworokatnyPrawidlowy() const {
        return liscieOstroslupCzworokatnyPrawidlowy;
    }
};


#endif //PROJEKT_MENEDZERFIGUR_H
