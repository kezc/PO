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

public:
    void start() {
        std::cout << "Dostepne komendy:\n"
                     " - CD [nazwa wezla] - zmiana wezla\n"
                     " - MO [nazwa] - utworzenie obiektu dla obecnego liscia\n"
                     " - DO [nazwa] - usuniecie obiektu z obecnego liscia\n"
                     " - MDO [nazwa] - modyfikacja obiektu z obecnego liscia\n"
                     " - SHOW [nazwa] - wyswietla szczegolowe informacje dla obiektu o podanej nazwie\n"
                     " - DIR - wypisuje wszystkie elementy\n"
                     " - SAVE - zapisywanie danych do pliku\n"
                     " - READ - wczytywanie danych z pliku\n"
                     " - TREE - wyswietlanei struktury drzewa\n"
                     " - EXIT  - wyjscie z programu" << std::endl;
        std::string option;

        while (option != "end") {
            std::cout << "Aktualny wezel: " << aktualnyWezelJakoString() << std::endl;
            std::cout << "co chcesz zrobic?" << std::endl;
            std::cin >> option;
            std::transform(option.begin(), option.end(), option.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            if (option == "cd") {
                zmienWezel();
            } else if (option == "tree") {
                wypiszStrukture();
            } else if (option == "mo") {
                utworzObiektDlaAktualnegoLiscia();
            } else if (option == "do") {
                usunObiektZLiscia();
            } else if (option == "mdo") {
                modyfikujObiektZLiscia();
            } else if (option == "dir") {
                wypiszObiektyZAktualnegoWezla();
            } else if (option == "show") {
                wypiszSzczegolyDlaObiektuZLiscia();
            } else if (option == "save") {
                zapiszFigury();
            } else if (option == "read") {
                wczytajFigury();
            } else if (!option.empty()) {
                std::cout << "Nieznana komenda." << std::endl;
            };
        }
    }

    void zmienWezel() {
        std::string wezel;
        std::cin >> wezel;
        std::transform(wezel.begin(), wezel.end(), wezel.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (wezel == "figury_geometryczne") {
            aktualnyWezel = Wezel::FiguryGeometryczne;
        } else if (wezel == "punkt") {
            aktualnyWezel = Wezel::Punkt;
        } else if (wezel == "trojkat") {
            aktualnyWezel = Wezel::Trojkat;
        } else if (wezel == "czworokat") {
            aktualnyWezel = Wezel::Czworokat;
        } else if (wezel == "rownoboczny") {
            aktualnyWezel = Wezel::Rownoboczny;
        } else if (wezel == "inne_trojkaty") {
            aktualnyWezel = Wezel::InneTrojkaty;
        } else if (wezel == "kwadrat") {
            aktualnyWezel = Wezel::Kwadrat;
        } else if (wezel == "inne_czworokaty") {
            aktualnyWezel = Wezel::InneCzworokaty;
        } else if (wezel == "ostroslup_trojkatny_prawidlowy") {
            aktualnyWezel = Wezel::OstroslupTrojkatnyPrawidlowy;
        } else if (wezel == "ostroslup_czworokatny_prawidlowy") {
            aktualnyWezel = Wezel::OstroslupCzworokatnyPrawidlowy;
        } else {
            std::cout << "Brak takiego węzła." << std::endl;
        }
    }


    static void wypiszStrukture() {
        std::cout << "                            FIGURY_GEOMETRYCZNE\n"
                     "                     _______/         /         \\\n"
                     "                    /              TROJKAT        CZWOROKAT\n"
                     "                 PUNKT            /    |   \\             |   \\\n"
                     "                   \\   \\   ROWNOBOCZNY | INNE_TROJKATY   |     INNE_CZWOROKATY\n"
                     "                    \\   \\              |               KWADRAT\n"
                     "                     \\   \\____         |                 |      \n"
                     "                      \\       \\________|_________        |\n"
                     "                       \\___            |         \\       |\n"
                     "                            \\______    |          \\ __   |\n"
                     "                                   \\   |              \\  |\n"
                     "                   OSTROSLUP_TROJKATNY_PRAWIDLOWY  OSTROSLUP_CZWOROKATNY_PRAWIDLOWY\n\n";
    }

    void wypiszObiektyZAktualnegoWezla() {
        switch (aktualnyWezel) {
            case Wezel::FiguryGeometryczne:
                wypiszWszystko();
                break;
            case Wezel::Punkt:
                wypiszPunkty();
                break;
            case Wezel::Trojkat:
                wypiszTrojkaty();
                break;
            case Wezel::Czworokat:
                wypiszCzworokaty();
                break;
            case Wezel::Rownoboczny:
                Rownoboczny::wypiszWszystkie();
                break;
            case Wezel::InneTrojkaty:
                InneTrojkaty::wypiszWszystkie();
                break;
            case Wezel::Kwadrat:
                wypiszKwadraty();
                break;
            case Wezel::InneCzworokaty:
                InneCzworokaty::wypiszWszystkie();
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                OstroslupTrojkatnyPrawidlowy::wypiszWszystkie();
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                OstroslupCzworokatnyPrawidlowy::wypiszWszystkie();
                break;
        }
    }

    void utworzObiektDlaAktualnegoLiscia() {
        std::string nazwa;
        std::cin >> nazwa;

        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                dodajRownoboczny(nazwa);
                break;
            case Wezel::InneTrojkaty:
                dodajInneTrojkaty(nazwa);
                break;
            case Wezel::InneCzworokaty:
                dodajInneCzworokaty(nazwa);
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                dodajOstroslupTrojkatnyPrawidlowy(nazwa);
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                dodajOstroslupCzworokatnyPrawidlowy(nazwa);
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge utworzyc obiektu. Prosze przejsc do liscia." << std::endl;
        }
    }

    void wypiszSzczegolyDlaObiektuZLiscia() {
        std::string nazwa;
        std::cin >> nazwa;
//
//        bool found = false;
//        std::vector<FiguryGeometryczne *> *liscie = getLiscie();
//        for (auto &element : *liscie) {
//            if (element->getNazwa() == nazwa) {
//                element->wypiszDane();
//                found = true;
//            }
//        }
//        delete liscie;
//
//        if (!found) {
//            std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
//        }

// Czy wyczytywanie po nazwie powinno zalezec od aktualnego wezla?
//
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny: {
                Rownoboczny *rownoboczny = Rownoboczny::znajdzNaLiscie(nazwa);
                if (rownoboczny != nullptr) {
                    rownoboczny->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            }
            case Wezel::InneTrojkaty: {
                InneTrojkaty *inneTrojkaty = InneTrojkaty::znajdzNaLiscie(nazwa);
                if (inneTrojkaty != nullptr) {
                    inneTrojkaty->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            }
            case Wezel::InneCzworokaty: {
                InneCzworokaty *inneCzworokaty = InneCzworokaty::znajdzNaLiscie(nazwa);
                if (inneCzworokaty != nullptr) {
                    inneCzworokaty->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            }
            case Wezel::OstroslupTrojkatnyPrawidlowy: {
                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy = OstroslupTrojkatnyPrawidlowy::znajdzNaLiscie(
                        nazwa);
                if (ostroslupTrojkatnyPrawidlowy != nullptr) {
                    ostroslupTrojkatnyPrawidlowy->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            }
            case Wezel::OstroslupCzworokatnyPrawidlowy: {
                OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = OstroslupCzworokatnyPrawidlowy::znajdzNaLiscie(
                        nazwa);
                if (ostroslupCzworokatnyPrawidlowy !=
                    nullptr) {
                    ostroslupCzworokatnyPrawidlowy->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Dla aktualnego wezla nie moge pokazac obiektu. Prosze przejsc do liscia." << std::endl;
        }
    }

    void modyfikujObiektZLiscia() {
        std::string nazwa;
        std::cin >> nazwa;
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                Rownoboczny *rownoboczny;
                if ((rownoboczny = Rownoboczny::znajdzNaLiscie(nazwa)) != nullptr) {
                    rownoboczny->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            case Wezel::InneTrojkaty:
                InneTrojkaty *inneTrojkaty;
                if ((inneTrojkaty = InneTrojkaty::znajdzNaLiscie(nazwa)) != nullptr) {
                    inneTrojkaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            case Wezel::InneCzworokaty:
                InneCzworokaty *inneCzworokaty;
                if ((inneCzworokaty = InneCzworokaty::znajdzNaLiscie(nazwa)) != nullptr) {
                    inneCzworokaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy;
                if ((ostroslupTrojkatnyPrawidlowy = OstroslupTrojkatnyPrawidlowy::znajdzNaLiscie(nazwa)) !=
                    nullptr) {
                    ostroslupTrojkatnyPrawidlowy->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektuo takiej nazwie." << std::endl;
                }
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy;
                if ((ostroslupCzworokatnyPrawidlowy = OstroslupCzworokatnyPrawidlowy::znajdzNaLiscie(nazwa)) !=
                    nullptr) {
                    ostroslupCzworokatnyPrawidlowy->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge zmodyfikowac obiektu. Prosze przejsc do liscia."
                          << std::endl;
        }
    }

    void usunObiektZLiscia() {
        std::string nazwa;
        std::cin >> nazwa;
        bool usunieto;
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                usunieto = Rownoboczny::usunZListy(nazwa);
                break;
            case Wezel::InneTrojkaty:
                usunieto = InneTrojkaty::usunZListy(nazwa);
                break;
            case Wezel::InneCzworokaty:
                usunieto = InneCzworokaty::usunZListy(nazwa);
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                usunieto = OstroslupTrojkatnyPrawidlowy::usunZListy(nazwa);
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                usunieto = OstroslupCzworokatnyPrawidlowy::usunZListy(nazwa);
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge zmodyfikowac obiektu. Prosze przejsc do liscia."
                          << std::endl;
                return;
        }
        if (usunieto) {
            std::cout << "Usunieto" << std::endl;
        } else {
            std::cout << "Nie udalo sie usunac" << std::endl;
        }
    }

    static void dodajOstroslupCzworokatnyPrawidlowy(std::string &nazwa) {
        if (OstroslupCzworokatnyPrawidlowy::znajdzNaLiscie(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        int kolor;
        double bokPodstawy;
        double wysokosc;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc" << std::endl;
        std::cin >> wysokosc;

        new OstroslupCzworokatnyPrawidlowy(kolor, nazwa, bokPodstawy, wysokosc);
        std::cout << "Utworzono." << std::endl;

    }

    static void dodajRownoboczny(std::string &nazwa) {
        if (Rownoboczny::znajdzNaLiscie(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        double bok;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bok;

        new Rownoboczny(kolor, nazwa, bok);
        std::cout << "Utworzono." << std::endl;
    }

    static void dodajInneTrojkaty(std::string &nazwa) {
        if (InneTrojkaty::znajdzNaLiscie(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        double bokA, bokB, bokC;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c" << std::endl;
        std::cin >> bokA >> bokB >> bokC;

        new InneTrojkaty(kolor, nazwa, bokA, bokB, bokC);
        std::cout << "Utworzono." << std::endl;
    }

    static void dodajOstroslupTrojkatnyPrawidlowy(std::string &nazwa) {
        if (OstroslupTrojkatnyPrawidlowy::znajdzNaLiscie(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        int kolor;
        double bokPodstawy;
        double wysokosc;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc" << std::endl;
        std::cin >> wysokosc;

        new OstroslupTrojkatnyPrawidlowy(kolor, nazwa, bokPodstawy, wysokosc);
        std::cout << "Utworzono." << std::endl;
    }

    static void dodajInneCzworokaty(std::string &nazwa) {
        if (InneCzworokaty::znajdzNaLiscie(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        double bokA, bokB, bokC, bokD;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c d" << std::endl;
        std::cin >> bokA >> bokB >> bokC >> bokD;

        new InneCzworokaty(kolor, nazwa, bokA, bokB, bokC, bokD);
        std::cout << "Utworzono." << std::endl;
    }

    static void wypiszPunkty() {
        std::cout << "Wszystkie punkty:" << std::endl;
        std::vector<Punkt < double> *> *punkt = getLisciePunkt();
        for (auto &element : *punkt) {
            std::cout << "Punkt o nazwie: " << element->getNazwa() << std::endl;
        }
        if (punkt->empty())         std::cout << "Brak elementow do wyswietlenia" << std::endl;

        delete punkt;
    }

    static void wypiszTrojkaty() {
        std::cout << "Wszystkie trojkaty:" << std::endl;
        std::vector<Trojkat *> *liscieTrojkat = getLiscieTrojkat();
        for (auto &element : *liscieTrojkat) {
            std::cout << "Trojkat o nazwie: " << element->getNazwa() << std::endl;
        }
        if (liscieTrojkat->empty())         std::cout << "Brak elementow do wyswietlenia" << std::endl;
        delete liscieTrojkat;
    }

    static void wypiszCzworokaty() {
        std::cout << "Wszystkie Czworokaty:" << std::endl;
        const std::vector<Czworokat *> *liscieCzworokat = getLiscieCzworokat();
        for (auto &element : *liscieCzworokat) {
            std::cout << "Czworokat o nazwie: " << element->getNazwa() << std::endl;
        }
        if (liscieCzworokat->empty())         std::cout << "Brak elementow do wyswietlenia" << std::endl;

        delete liscieCzworokat;
    }

    static void wypiszKwadraty() {
        std::cout << "Wszystkie kwadraty:" << std::endl;
        const std::vector<Kwadrat *> *liscieKwadrat = getLiscieKwadrat();
        for (auto &element : *liscieKwadrat) {
            std::cout << "Kwadrat o nazwie: " << element->getNazwa() << std::endl;
        }
        if (liscieKwadrat->empty())         std::cout << "Brak elementow do wyswietlenia" << std::endl;

        delete liscieKwadrat;
    }

    static void wypiszWszystko() {
        std::vector<FiguryGeometryczne *> *liscie = getLiscie();

        if (liscie->empty()) std::cout << "Brak figur." << std::endl;
        else {
            std::cout << "Wszystkie figury:" << std::endl;
            for (auto &element : *liscie) {
                std::cout << "Figura o nazwie: " << element->getNazwa() << std::endl;
            }
        }
        delete liscie;
    }

    void wczytajFigury() {
        std::vector<FiguryGeometryczne *> *liscie = getLiscie();
        int liczba = liscie->size();
        delete liscie;
        if (liczba == 0) {
            std::string nazwaPliku;
            std::cout << "Podaj nazwe pliku" << std::endl;
            std::cin >> nazwaPliku;
            odczytajZPliku(nazwaPliku);
        } else std::cout << "Wczytanie obiektow jest mozliwe tylko gdy nie ma zadnego utworzonego." << std::endl;
    }

    void zapiszFigury() {
        std::string nazwaPliku;
        std::cout << "Podaj nazwe pliku" << std::endl;
        std::cin >> nazwaPliku;
        zapiszDoPliku(nazwaPliku);
    }

    std::string aktualnyWezelJakoString() {
        switch (aktualnyWezel) {
            case Wezel::FiguryGeometryczne:
                return "Figury_Geometryczne";
            case Wezel::Punkt:
                return "Punkt";
            case Wezel::Trojkat:
                return "Trójkąt";
            case Wezel::Czworokat:
                return "Czworokąt";
            case Wezel::Rownoboczny:
                return "Rownoboczny";
            case Wezel::InneTrojkaty:
                return "Inne_Trojkaty";
            case Wezel::Kwadrat:
                return "Kwadrat";
            case Wezel::InneCzworokaty:
                return "Inne_Czworokaty";
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                return "Ostroslup_Trojkatny_Prawidlowy";
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                return "Ostroslup_Czworokatny_Prawidlowy";
        }
        return "";
    }


    static FiguryGeometryczne *znajdzFigure(std::string &nazwa) {
        FiguryGeometryczne *figura = nullptr;
        std::vector<FiguryGeometryczne *> *liscie = getLiscie();
        for (auto &element : *liscie) {
            if (element->getNazwa() == nazwa) {
                figura = element;
            }
        }
        delete liscie;
        return figura;
    }

    static void odczytajZPliku(std::string &nazwaPliku) {
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
                new OstroslupTrojkatnyPrawidlowy(kolor, nazwa, bok, wysokosc, id);
            } else if (typ == "OstroslupCzworokatnyPrawidlowy") {
                double bok, wysokosc;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bok;
                plik >> wysokosc;
                if (id > maxId) maxId = id;
                new OstroslupCzworokatnyPrawidlowy(kolor, nazwa, bok, wysokosc, id);
            } else if (typ == "InneTrojkaty") {
                double bokA, bokB, bokC;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bokA;
                plik >> bokB;
                plik >> bokC;
                if (id > maxId) maxId = id;
                new InneTrojkaty(kolor, nazwa, bokA, bokB, bokC, id);
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
                new InneCzworokaty(kolor, nazwa, bokA, bokB, bokC, bokD, id);
            } else if (typ == "Rownoboczny") {
                double bok;
                plik >> id;
                plik >> nazwa;
                plik >> kolor;
                plik >> bok;
                if (id > maxId) maxId = id;
                new Rownoboczny(kolor, nazwa, bok, id);
            }
        }
        FiguryGeometryczne::ustawLicznik(maxId + 1);
    }

    static void zapiszDoPliku(std::string &nazwa) {
        std::ofstream plik;
        plik.open(nazwa);
        std::vector<FiguryGeometryczne *> *liscie = getLiscie();
        for (auto element : *liscie) {
            element->zapiszDoPliku(plik);
        }
        delete liscie;
        plik.close();
    }

    static std::vector<FiguryGeometryczne *> *getLiscie() {
        std::set<FiguryGeometryczne *> set;
        for (auto element : Rownoboczny::liscie) set.insert(element);
        for (auto element : InneTrojkaty::liscie) set.insert(element);
        for (auto element : OstroslupTrojkatnyPrawidlowy::liscie) set.insert(element);
        for (auto element : InneCzworokaty::liscie) set.insert(element);
        for (auto element : OstroslupCzworokatnyPrawidlowy::liscie) set.insert(element);
        auto *liscie = new std::vector<FiguryGeometryczne *>(set.begin(), set.end());
        return liscie;
    }

    static std::vector<Punkt < double> *> *

    getLisciePunkt() {
        std::set<Punkt < double> *> set;
        for (auto element : OstroslupTrojkatnyPrawidlowy::liscie) set.insert(element);
        for (auto element : OstroslupCzworokatnyPrawidlowy::liscie) set.insert(element);
        auto *liscie = new std::vector<Punkt < double> * > (set.begin(), set.end());
        return liscie;
    }

    static std::vector<Trojkat *> *getLiscieTrojkat() {
        std::set<Trojkat *> set;
        for (auto element : Rownoboczny::liscie) set.insert(element);
        for (auto element : InneTrojkaty::liscie) set.insert(element);
        for (auto element : OstroslupTrojkatnyPrawidlowy::liscie) set.insert(element);
        auto *liscie = new std::vector<Trojkat *>(set.begin(), set.end());
        return liscie;
    }

    static std::vector<Czworokat *> *getLiscieCzworokat() {
        std::set<Czworokat *> set;
        for (auto element : InneCzworokaty::liscie) set.insert(element);
        for (auto element : OstroslupCzworokatnyPrawidlowy::liscie) set.insert(element);
        auto *liscie = new std::vector<Czworokat *>(set.begin(), set.end());
        return liscie;
    }

    static std::vector<Kwadrat *> *getLiscieKwadrat() {
        auto *liscie = new std::vector<Kwadrat *>();
        for (auto element : OstroslupCzworokatnyPrawidlowy::liscie) liscie->push_back(element);
        return liscie;
    }

    virtual ~Konsola() {
        std::vector<FiguryGeometryczne *> *liscie = getLiscie();
        for (auto &element : *liscie) {
            delete element;
        }
        delete liscie;
    }
};


#endif //PROJEKT_KONSOLA_H
