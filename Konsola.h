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

        bool found = false;
        std::vector<FiguryGeometryczne *> *liscie = menedzerFigur.getLiscie();
        for (auto &element : *liscie) {
            if (element->getNazwa() == nazwa) {
                element->wypiszDane();
                found = true;
            }
        }
        delete liscie;

        if (!found) {
            std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
        }

// Czy wyczytywanie po nazwie powinno zalezec od aktualnego wezla?
//
//        switch (aktualnyWezel) {
//            case Wezel::Rownoboczny: {
//                Rownoboczny *rownoboczny = menedzerFigur.znajdzRownoboczny(nazwa);
//                if (rownoboczny != nullptr) {
//                    rownoboczny->wypiszDane();
//                } else {
//                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
//                }
//                break;
//            }
//            case Wezel::InneTrojkaty: {
//                InneTrojkaty *inneTrojkaty = menedzerFigur.znajdzInneTrojkaty(nazwa);
//                if (inneTrojkaty != nullptr) {
//                    inneTrojkaty->wypiszDane();
//                } else {
//                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
//                }
//                break;
//            }
//            case Wezel::InneCzworokaty: {
//                InneCzworokaty *inneCzworokaty = menedzerFigur.znajdzInneCzworokaty(nazwa);
//                if (inneCzworokaty != nullptr) {
//                    inneCzworokaty->wypiszDane();
//                } else {
//                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
//                }
//                break;
//            }
//            case Wezel::OstroslupTrojkatnyPrawidlowy: {
//                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy = menedzerFigur.znajdzOstroslupTrojkatnyPrawidlowy(
//                        nazwa);
//                if (ostroslupTrojkatnyPrawidlowy != nullptr) {
//                    ostroslupTrojkatnyPrawidlowy->wypiszDane();
//                } else {
//                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
//                }
//                break;
//            }
//            case Wezel::OstroslupCzworokatnyPrawidlowy: {
//                OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy = menedzerFigur.znajdzOstroslupCzworokatnyPrawidlowy(
//                        nazwa);
//                if (ostroslupCzworokatnyPrawidlowy !=
//                    nullptr) {
//                    ostroslupCzworokatnyPrawidlowy->wypiszDane();
//                } else {
//                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
//                }
//                break;
//            }
//            default:
//                std::cout << "Dla aktualnego wezla nie moge pokazac obiektu. Prosze przejsc do liscia." << std::endl;
//        }
    }

    void modyfikujObiektZLiscia() {
        std::string nazwa;
        std::cin >> nazwa;
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                Rownoboczny *rownoboczny;
                if ((rownoboczny = menedzerFigur.znajdzRownoboczny(nazwa)) != nullptr) {
                    rownoboczny->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            case Wezel::InneTrojkaty:
                InneTrojkaty *inneTrojkaty;
                if ((inneTrojkaty = menedzerFigur.znajdzInneTrojkaty(nazwa)) != nullptr) {
                    inneTrojkaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            case Wezel::InneCzworokaty:
                InneCzworokaty *inneCzworokaty;
                if ((inneCzworokaty = menedzerFigur.znajdzInneCzworokaty(nazwa)) != nullptr) {
                    inneCzworokaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu o takiej nazwie." << std::endl;
                }
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy;
                if ((ostroslupTrojkatnyPrawidlowy = menedzerFigur.znajdzOstroslupTrojkatnyPrawidlowy(nazwa)) !=
                    nullptr) {
                    ostroslupTrojkatnyPrawidlowy->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektuo takiej nazwie." << std::endl;
                }
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy;
                if ((ostroslupCzworokatnyPrawidlowy = menedzerFigur.znajdzOstroslupCzworokatnyPrawidlowy(nazwa)) !=
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
                usunieto = menedzerFigur.usunRownoboczny(nazwa);
                break;
            case Wezel::InneTrojkaty:
                usunieto = menedzerFigur.usunInneTrojkaty(nazwa);
                break;
            case Wezel::InneCzworokaty:
                usunieto = menedzerFigur.usunInneCzworokaty(nazwa);
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                usunieto = menedzerFigur.usunOstroslupTrojkatnyPrawidlowy(nazwa);
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                usunieto = menedzerFigur.usunOstroslupCzworokatnyPrawidlowy(nazwa);
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

    void dodajOstroslupCzworokatnyPrawidlowy(std::string &nazwa) {
        if (menedzerFigur.znajdzOstroslupCzworokatnyPrawidlowy(nazwa) != nullptr) {
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

        menedzerFigur.dodajOstroslupCzworokatnyPrawidlowy(kolor, nazwa, bokPodstawy, wysokosc);
        std::cout << "Utworzono." << std::endl;

    }

    void dodajRownoboczny(std::string &nazwa) {
        if (menedzerFigur.znajdzRownoboczny(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        double bok;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długość boku" << std::endl;
        std::cin >> bok;

        menedzerFigur.dodajRownoboczny(kolor, nazwa, bok);
        std::cout << "Utworzono." << std::endl;
    }

    void dodajInneTrojkaty(std::string &nazwa) {
        if (menedzerFigur.znajdzInneTrojkaty(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        double bokA, bokB, bokC;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c" << std::endl;
        std::cin >> bokA >> bokB >> bokC;

        menedzerFigur.dodajInneTrojkaty(kolor, nazwa, bokA, bokB, bokC);
        std::cout << "Utworzono." << std::endl;
    }

    void dodajOstroslupTrojkatnyPrawidlowy(std::string &nazwa) {
        if (menedzerFigur.znajdzOstroslupTrojkatnyPrawidlowy(nazwa) != nullptr) {
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

        menedzerFigur.dodajOstroslupTrojkatnyPrawidlowy(kolor, nazwa, bokPodstawy, wysokosc);
        std::cout << "Utworzono." << std::endl;
    }

    void dodajInneCzworokaty(std::string &nazwa) {
        if (menedzerFigur.znajdzInneCzworokaty(nazwa) != nullptr) {
            std::cout << "Istnieje rownoboczny o tej nazwie" << std::endl;
            return;
        }
        double bokA, bokB, bokC, bokD;
        int kolor;

        std::cout << "Podaj kolor" << std::endl;
        std::cin >> kolor;
        std::cout << "Podaj długości bokow a b c d" << std::endl;
        std::cin >> bokA >> bokB >> bokC >> bokD;

        menedzerFigur.dodajInneCzworokaty(kolor, nazwa, bokA, bokB, bokC, bokD);
        std::cout << "Utworzono." << std::endl;
    }


    void wypiszTrojkatyRownoboczne() {
        std::cout << "Wszystkie trojkaty rownoboczne:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieRownoboczny()) {
            std::cout << "Trojkat Rownoboczny o nazwie: " << element->getNazwa() << std::endl;
        }
    }

    void wypiszInneTrojkaty() {
        std::cout << "Wszystkie inne trojkaty:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieInneTrojkaty()) {
            std::cout << "Inny trojkat o nazwie: " << element->getNazwa() << std::endl;
        }
    }

    void wypiszInneCzworokaty() {
        std::cout << "Wszystkie inne czworokaty:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieInneCzworokaty()) {
            std::cout << "Inny czworokat o nazwie: " << element->getNazwa() << std::endl;
        }
    }

    void wypiszOstroslupyTrojkatnePrawidlowe() {
        std::cout << "Wszystkie ostroslupy trojkatne prawidlowe:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieOstroslupTrojkatnyPrawidlowy()) {
            std::cout << "Ostroslup Trojkatny Rownoboczny o nazwie: " << element->getNazwa() << std::endl;
        }
    }

    void wypiszOstroslupyCzworokatnePrawidlowe() {
        std::cout << "Wszystkie ostroslupy czworokatne prawidlowe:" << std::endl;
        for (auto &element : menedzerFigur.getLiscieOstroslupCzworokatnyPrawidlowy()) {
            std::cout << "Ostroslup Czworokatny Rownoboczny o nazwie: " << element->getNazwa() << std::endl;
        }
    }

    void wypiszPunkty() {
        std::cout << "Wszystkie punkty:" << std::endl;
        std::vector<Punkt<double> *> *punkt = menedzerFigur.getLisciePunkt();
        for (auto &element : *punkt) {
            std::cout << "Punkt o nazwie: " << element->getNazwa() << std::endl;
        }
        delete punkt;
    }

    void wypiszTrojkaty() {
        std::cout << "Wszystkie trojkaty:" << std::endl;
        std::vector<Trojkat *> *liscieTrojkat = menedzerFigur.getLiscieTrojkat();
        for (auto &element : *liscieTrojkat) {
            std::cout << "Trojkat o nazwie: " << element->getNazwa() << std::endl;
        }
        delete liscieTrojkat;
    }

    void wypiszCzworokaty() {
        std::cout << "Wszystkie Czworokaty:" << std::endl;
        const std::vector<Czworokat *> *liscieCzworokat = menedzerFigur.getLiscieCzworokat();
        for (auto &element : *liscieCzworokat) {
            std::cout << "Czworokat o nazwie: " << element->getNazwa() << std::endl;
        }
        delete liscieCzworokat;
    }

    void wypiszKwadraty() {
        std::cout << "Wszystkie kwadraty:" << std::endl;
        const std::vector<Kwadrat *> *liscieKwadrat = menedzerFigur.getLiscieKwadrat();
        for (auto &element : *liscieKwadrat) {
            std::cout << "Kwadrat o nazwie: " << element->getNazwa() << std::endl;
        }
        delete liscieKwadrat;
    }

    void wypiszWszystko() {
        std::vector<FiguryGeometryczne *> *liscie = menedzerFigur.getLiscie();

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
        std::vector<FiguryGeometryczne *> *liscie = menedzerFigur.getLiscie();
        int liczba = liscie->size();
        delete liscie;
        if (liczba == 0) {
            std::string nazwaPliku;
            std::cout << "Podaj nazwe pliku" << std::endl;
            std::cin >> nazwaPliku;
            menedzerFigur.odczytajZPliku(nazwaPliku);
        } else std::cout << "Wczytanie obiektow jest mozliwe tylko gdy nie ma zadnego utworzonego." << std::endl;
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
