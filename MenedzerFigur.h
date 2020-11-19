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
                                             double bokPodstawy,
                                             double wysokosc,
                                             std::string etykietaWierzcholka,
                                             int id = -1) {
        auto *ostroslupCzworokatnyPrawidlowy =
                new OstroslupCzworokatnyPrawidlowy(kolor, etykietaWierzcholka, bokPodstawy, wysokosc);

        if (id > 0) ostroslupCzworokatnyPrawidlowy->setId(id);

        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        lisciePunkt.push_back(ostroslupCzworokatnyPrawidlowy);
        liscieOstroslupCzworokatnyPrawidlowy.push_back(ostroslupCzworokatnyPrawidlowy);
        liscie.push_back(ostroslupCzworokatnyPrawidlowy);
    }

    void dodajRownoboczny(int kolor, double bok, int id = -1) {
        auto *rownoboczny = new Rownoboczny(kolor, bok);

        if (id > 0) rownoboczny->setId(id);

        liscieRownoboczny.push_back(rownoboczny);
        liscieTrojkat.push_back(rownoboczny);
        liscie.push_back(rownoboczny);
    }

    void dodajInneTrojkaty(int kolor, double bokA, double bokB, double bokC,
                           int id = -1) {
        auto *inneTrojkaty = new InneTrojkaty(kolor, bokA, bokB, bokC);

        if (id > 0) inneTrojkaty->setId(id);

        liscieInneTrojkaty.push_back(inneTrojkaty);
        liscieTrojkat.push_back(inneTrojkaty);
        liscie.push_back(inneTrojkaty);
    }

    void dodajOstroslupTrojkatnyPrawidlowy(int kolor,
                                           double bokPodstawy,
                                           double wysokosc,
                                           std::string etykietaWierzcholka, int id = -1) {
        auto *ostroslupTrojkatnyPrawidlowy =
                new OstroslupTrojkatnyPrawidlowy(kolor, etykietaWierzcholka, bokPodstawy, wysokosc);

        if (id > 0) ostroslupTrojkatnyPrawidlowy->setId(id);

        liscieOstroslupTrojkatnyPrawidlowy.push_back(ostroslupTrojkatnyPrawidlowy);
        lisciePunkt.push_back(ostroslupTrojkatnyPrawidlowy);
        liscieTrojkat.push_back(ostroslupTrojkatnyPrawidlowy);
        liscie.push_back(ostroslupTrojkatnyPrawidlowy);
    }

    void dodajInneCzworokaty(int kolor, double bokA, double bokB, double bokC, double bokD, int id = -1
    ) {
        auto *inneCzworokaty = new InneCzworokaty(kolor, bokA, bokB, bokC, bokD);

        if (id > 0) inneCzworokaty->setId(id);

        liscieInneCzworokaty.push_back(inneCzworokaty);
        liscieCzworokat.push_back(inneCzworokaty);
        liscie.push_back(inneCzworokaty);
    }

    bool usunInneCzworokaty(int id) {
        InneCzworokaty *innyCzworokat = znajdzCzworokatPoId(id);

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

    InneCzworokaty *znajdzCzworokatPoId(int id) const {
        InneCzworokaty *innyCzworokat = nullptr;
        for (auto &element : liscieInneCzworokaty) {
            if (element->getId() == id) {
                innyCzworokat = element;
            }
        }
        return innyCzworokat;
    }


    bool usunOstroslupTrojkatnyPrawidlowy(int id) {
        OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy = znajdzOstroslupTrojkatnyPrawidlowyPoId(id);
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

    OstroslupTrojkatnyPrawidlowy *znajdzOstroslupTrojkatnyPrawidlowyPoId(int id) const {
        OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy = nullptr;
        for (auto &element : liscieOstroslupTrojkatnyPrawidlowy) {
            if (element->getId() == id) {
                ostroslupTrojkatnyPrawidlowy = element;
            }
        }
        return ostroslupTrojkatnyPrawidlowy;
    }

    bool usunInneTrojkaty(int id) {
        InneTrojkaty *inneTrojkaty = znajdzInneTrojkatyPoId(id);
        if (inneTrojkaty == nullptr) return false;

        liscieInneTrojkaty.erase(std::remove(liscieInneTrojkaty.begin(), liscieInneTrojkaty.end(), inneTrojkaty),
                                 liscieInneTrojkaty.end());
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), inneTrojkaty),
                            liscieTrojkat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), inneTrojkaty),
                     liscie.end());
        return true;
    }

    InneTrojkaty *znajdzInneTrojkatyPoId(int id) const {
        InneTrojkaty *inneTrojkaty = nullptr;
        for (auto &element : liscieInneTrojkaty) {
            if (element->getId() == id) {
                inneTrojkaty = element;
            }
        }
        return inneTrojkaty;
    }

    bool usunRownoboczny(int id) {
        Rownoboczny *rownoboczny = znajdzRownobocznyPoId(id);
        if (rownoboczny == nullptr) return false;

        liscieRownoboczny.erase(std::remove(liscieRownoboczny.begin(), liscieRownoboczny.end(), rownoboczny),
                                liscieRownoboczny.end());
        liscieTrojkat.erase(std::remove(liscieTrojkat.begin(), liscieTrojkat.end(), rownoboczny),
                            liscieTrojkat.end());
        liscie.erase(std::remove(liscie.begin(), liscie.end(), rownoboczny),
                     liscie.end());
        return true;
    }

    Rownoboczny *znajdzRownobocznyPoId(int id) const {
        Rownoboczny *rownoboczny = nullptr;
        for (auto &element : liscieRownoboczny) {
            if (element->getId() == id) {
                rownoboczny = element;
            }
        }
        return rownoboczny;
    }

    bool usunOstroslupCzworokatnyPrawidlowy(int id) {
        OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = znajdzOstroslupCzworokatnyPrawidlowyPoId(id);
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

    OstroslupCzworokatnyPrawidlowy *znajdzOstroslupCzworokatnyPrawidlowyPoId(int id) const {
        OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = nullptr;
        for (auto &element : liscieOstroslupCzworokatnyPrawidlowy) {
            if (element->getId() == id) {
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

    void odczytajZPliku(std::string &nazwa) {
        std::ifstream plik;
        plik.open(nazwa);
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
                dodajOstroslupTrojkatnyPrawidlowy(kolor, bok, wysokosc, etykietaWierzcholka, id);
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
                dodajOstroslupCzworokatnyPrawidlowy(kolor, bok, wysokosc, etykietaWierzcholka, id);
            } else if (typ == "InneTrojkaty") {
                int id, kolor;
                double bokA, bokB, bokC;
                plik >> id;
                plik >> kolor;
                plik >> bokA;
                plik >> bokB;
                plik >> bokC;
                if (id > maxId) maxId = id;
                dodajInneTrojkaty(kolor, bokA, bokB, bokC, id);
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
                dodajInneCzworokaty(kolor, bokA, bokB, bokC, bokD, id);
            } else if (typ == "Rownoboczny") {
                int id, kolor;
                double bok;
                plik >> id;
                plik >> kolor;
                plik >> bok;
                if (id > maxId) maxId = id;
                dodajRownoboczny(kolor, bok, id);
            }
        }
        FiguryGeometryczne::ustawLicznik(maxId);
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
