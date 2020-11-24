#ifndef PROJEKT_KONSOLA_H
#define PROJEKT_KONSOLA_H

#include <algorithm>
#include <cctype>
#include <string>

#include "MenedzerFigur.h"

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
    MenedzerFigur menedzerFigur;
    Wezel aktualnyWezel = Wezel::FiguryGeometryczne;

public:
    void start() {
        std::string option;
        std::cout << "Czy wczytac zapisane obiekty?" << std::endl;
        std::cout << "TAK / NIE" << std::endl;
        std::cin >> option;
        if (option == "TAK") {
            wczytajFigury();
        }

        while (option != "END") {
            std::cout << "Aktualny wezel: " << aktualnyWezelJakoString() << std::endl;
            std::cout << "co chcesz zrobic?" << std::endl;
            std::cin >> option;
            if (option.substr(0, 2) == "CD") {
                std::string wezel;
                std::cin >> wezel;
                zmienWezel(wezel);
            } else if (option == "TREE") {
                wypiszStrukture();
            } else if (option == "MO") {
                utworzObiektDlaAktualnegoLiscia();
            } else if (option == "DO") {
                int id;
                std::cin >> id;
                usunObiektZLisciaPoId(id);
            } else if (option == "MDO") {
                int id;
                std::cin >> id;
                modyfikujObiektZLisciaPoId(id);
            } else if (option == "DIR") {
                wypiszObiektyZAktualnegoWezla();
            } else if (option == "SHOW") {
                int id;
                std::cin >> id;
                wypiszSzczegolyDlaObiektuZLisciaPoId(id);
            } else if (option == "SAVE") {
                zapiszFigury();
            } else {
                std::cout << "Nieznana komenda." << std::endl;
            };
        }


    }

    void zmienWezel(std::string wezel) {
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


    void wypiszStrukture() {
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
                wypiszTrojkatyRownoboczne();
                break;
            case Wezel::InneTrojkaty:
                wypiszInneTrojkaty();
                break;
            case Wezel::Kwadrat:
                wypiszKwadraty();
                break;
            case Wezel::InneCzworokaty:
                wypiszInneCzworokaty();
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                wypiszOstroslupyTrojkatnePrawidlowe();
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                wypiszOstroslupyCzworokatnePrawidlowe();
                break;
        }
    }

    void utworzObiektDlaAktualnegoLiscia() {
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                dodajRownoboczny();
                break;
            case Wezel::InneTrojkaty:
                dodajInneTrojkaty();
                break;
            case Wezel::InneCzworokaty:
                dodajInneCzworokaty();
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                dodajOstroslupTrojkatnyPrawidlowy();
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                dodajOstroslupCzworokatnyPrawidlowy();
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge utworzyc obiektu. Prosze przejsc do liscia." << std::endl;
        }
    }

    void wypiszSzczegolyDlaObiektuZLisciaPoId(int id) {
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                Rownoboczny *rownoboczny;
                if ((rownoboczny = menedzerFigur.znajdzRownobocznyPoId(id)) != nullptr) {
                    rownoboczny->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneTrojkaty:
                InneTrojkaty *inneTrojkaty;
                if ((inneTrojkaty = menedzerFigur.znajdzInneTrojkatyPoId(id)) != nullptr) {
                    inneTrojkaty->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneCzworokaty:
                InneCzworokaty *inneCzworokaty;
                if ((inneCzworokaty = menedzerFigur.znajdzCzworokatPoId(id)) != nullptr) {
                    inneCzworokaty->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy;
                if ((ostroslupTrojkatnyPrawidlowy = menedzerFigur.znajdzOstroslupTrojkatnyPrawidlowyPoId(id)) !=
                    nullptr) {
                    ostroslupTrojkatnyPrawidlowy->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy;
                if ((ostroslupCzworokatnyPrawidlowy = menedzerFigur.znajdzOstroslupCzworokatnyPrawidlowyPoId(id)) !=
                    nullptr) {
                    ostroslupCzworokatnyPrawidlowy->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge pokazac obiektu. Prosze przejsc do liscia." << std::endl;
        }
    }

    void modyfikujObiektZLisciaPoId(int id) {
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                Rownoboczny *rownoboczny;
                if ((rownoboczny = menedzerFigur.znajdzRownobocznyPoId(id)) != nullptr) {
                    rownoboczny->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneTrojkaty:
                InneTrojkaty *inneTrojkaty;
                if ((inneTrojkaty = menedzerFigur.znajdzInneTrojkatyPoId(id)) != nullptr) {
                    inneTrojkaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneCzworokaty:
                InneCzworokaty *inneCzworokaty;
                if ((inneCzworokaty = menedzerFigur.znajdzCzworokatPoId(id)) != nullptr) {
                    inneCzworokaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy;
                if ((ostroslupTrojkatnyPrawidlowy = menedzerFigur.znajdzOstroslupTrojkatnyPrawidlowyPoId(id)) !=
                    nullptr) {
                    ostroslupTrojkatnyPrawidlowy->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy;
                if ((ostroslupCzworokatnyPrawidlowy = menedzerFigur.znajdzOstroslupCzworokatnyPrawidlowyPoId(id)) !=
                    nullptr) {
                    ostroslupCzworokatnyPrawidlowy->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge zmodyfikowac obiektu. Prosze przejsc do liscia."
                          << std::endl;
        }
    }

    void usunObiektZLisciaPoId(int id) {
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                menedzerFigur.usunRownoboczny(id);
                break;
            case Wezel::InneTrojkaty:
                menedzerFigur.usunInneTrojkaty(id);
                break;
            case Wezel::InneCzworokaty:
                menedzerFigur.usunInneCzworokaty(id);
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                menedzerFigur.usunOstroslupTrojkatnyPrawidlowy(id);
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                menedzerFigur.usunOstroslupCzworokatnyPrawidlowy(id);
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge zmodyfikowac obiektu. Prosze przejsc do liscia."
                          << std::endl;
        }
    }

    void dodajOstroslupCzworokatnyPrawidlowy() {
        int kolor;
        double bokPodstawy;
        double wysokosc;
        std::string etykietaWierzcholka;

        std::cout << "Podaj etykiete wierzcholka" << std::endl;
        std::cin >> etykietaWierzcholka;
        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc" << std::endl;
        std::cin >> wysokosc;

        menedzerFigur.dodajOstroslupCzworokatnyPrawidlowy(kolor, bokPodstawy, wysokosc, etykietaWierzcholka);
    }

    void dodajRownoboczny() {
        double bok;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bok;

        menedzerFigur.dodajRownoboczny(kolor, bok);
    }

    void dodajInneTrojkaty() {
        double bokA, bokB, bokC;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c" << std::endl;
        std::cin >> bokA >> bokB >> bokC;


        menedzerFigur.dodajInneTrojkaty(kolor, bokA, bokB, bokC);
    }

    void dodajOstroslupTrojkatnyPrawidlowy() {
        int kolor;
        double bokPodstawy;
        double wysokosc;
        std::string etykietaWierzcholka;

        std::cout << "Podaj etykiete wierzcholka" << std::endl;
        std::cin >> etykietaWierzcholka;
        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bokPodstawy;
        std::cout << "Podaj wysokosc" << std::endl;
        std::cin >> wysokosc;


        menedzerFigur.dodajOstroslupTrojkatnyPrawidlowy(kolor, bokPodstawy, wysokosc, etykietaWierzcholka);
    }

    void dodajInneCzworokaty() {
        double bokA, bokB, bokC, bokD;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c d" << std::endl;
        std::cin >> bokA >> bokB >> bokC >> bokD;

        menedzerFigur.dodajInneCzworokaty(kolor, bokA, bokB, bokC, bokD);
    }

    void usunInneCzworokaty() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunInneCzworokaty(id);
    }

    void usunOstroslupTrojkatnyPrawidlowy() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunOstroslupTrojkatnyPrawidlowy(id);
    }

    void usunInneTrojkaty() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunInneCzworokaty(id);
    }

    void usunRownoboczny() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunRownoboczny(id);
    }

    void usunOstroslupCzworokatnyPrawidlowy() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunOstroslupCzworokatnyPrawidlowy(id);
    }


    void wypiszTrojkatyRownoboczne() {
        std::cout << "Wszystkie trojkaty rownoboczne:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieRownoboczny()) {
            std::cout << "Trojkat Rownoboczny o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszInneTrojkaty() {
        std::cout << "Wszystkie inne trojkaty:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieInneTrojkaty()) {
            std::cout << "Inny trojkat o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszInneCzworokaty() {
        std::cout << "Wszystkie inne czworokaty:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieInneCzworokaty()) {
            std::cout << "Inny czworokat o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszOstroslupyTrojkatnePrawidlowe() {
        std::cout << "Wszystkie ostroslupy trojkatne prawidlowe:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieOstroslupTrojkatnyPrawidlowy()) {
            std::cout << "Ostroslup Trojkatny Rownoboczny o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszOstroslupyCzworokatnePrawidlowe() {
        std::cout << "Wszystkie ostroslupy czworokatne prawidlowe:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieOstroslupCzworokatnyPrawidlowy()) {
            std::cout << "Ostroslup Czworokatny Rownoboczny o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszPunkty() {
        std::cout << "Wszystkie punkty:" << std::endl;
        for (auto &element : menedzerFigur.getLisciePunkt()) {
            std::cout << "Punkt o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszTrojkaty() {
        std::cout << "Wszystkie trojkaty:" << std::endl;
        for (auto &element : menedzerFigur.getLisciePunkt()) {
            std::cout << "Trojkat o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszCzworokaty() {
        std::cout << "Wszystkie Czworokaty:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieCzworokat()) {
            std::cout << "Czworokat o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszKwadraty() {
        std::cout << "Wszystkie kwadraty:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieKwadrat()) {
            std::cout << "Kwadrat o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wypiszWszystko() {
        std::cout << "Wszystkie figury:" << std::endl;
        for (auto &element : menedzerFigur.getLiscie()) {
            std::cout << "Figura o id: " << element->getId() << std::endl;
        }
        std::cout << std::endl;
    }

    void wczytajFigury() {
        std::string nazwaPliku;
        std::cout << "Podaj nazwe pliku" << std::endl;
        std::cin >> nazwaPliku;
        menedzerFigur.odczytajZPliku(nazwaPliku);
    }

    void zapiszFigury() {
        std::string nazwaPliku;
        std::cout << "Podaj nazwe pliku" << std::endl;
        std::cin >> nazwaPliku;
        menedzerFigur.zapiszDoPliku(nazwaPliku);
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

};


#endif //PROJEKT_KONSOLA_H
