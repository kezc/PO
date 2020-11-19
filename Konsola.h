#ifndef PROJEKT_KONSOLA_H
#define PROJEKT_KONSOLA_H


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
    void zmienWezel() {
        std::cout << "Podaj NUMER wezla." << std::endl;
        std::cout << "1. Figury Geometryczne" << std::endl;
        std::cout << "2. Punkt" << std::endl;
        std::cout << "3. Trojkat" << std::endl;
        std::cout << "4. Czworokat" << std::endl;
        std::cout << "5. Rownoboczny" << std::endl;
        std::cout << "6. Inne Trojkaty" << std::endl;
        std::cout << "7. Kwadrat" << std::endl;
        std::cout << "8. InneCzworokaty" << std::endl;
        std::cout << "9. Ostroslup Trojkatny_prawidlowy" << std::endl;
        std::cout << "10. Ostroslup Czworokatny_Prawidlowy" << std::endl;
        int odpowiedz;
        std::cin >> odpowiedz;
        switch (odpowiedz) {
            case 1:
                aktualnyWezel = Wezel::FiguryGeometryczne;
                break;
            case 2:
                aktualnyWezel = Wezel::Punkt;
                break;
            case 3:
                aktualnyWezel = Wezel::Trojkat;
                break;
            case 4:
                aktualnyWezel = Wezel::Czworokat;
                break;
            case 5:
                aktualnyWezel = Wezel::Rownoboczny;
                break;
            case 6:
                aktualnyWezel = Wezel::InneTrojkaty;
                break;
            case 7:
                aktualnyWezel = Wezel::Kwadrat;
                break;
            case 8:
                aktualnyWezel = Wezel::InneCzworokaty;
                break;
            case 9:
                aktualnyWezel = Wezel::OstroslupTrojkatnyPrawidlowy;
                break;
            case 10:
                aktualnyWezel = Wezel::OstroslupCzworokatnyPrawidlowy;
                break;
            default:
                std::cout << "Brak takiego węzła." << std::endl;
        }
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

    void wypiszSzczegolyDlaObiektuZLisciaPoId() {
        int id;
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                Rownoboczny *rownoboczny;
                if ((rownoboczny = menedzerFigur.znajdzRownobocznyPoId(id)) != nullptr) {
                    rownoboczny->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneTrojkaty:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                InneTrojkaty *inneTrojkaty;
                if ((inneTrojkaty = menedzerFigur.znajdzInneTrojkatyPoId(id)) != nullptr) {
                    inneTrojkaty->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneCzworokaty:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                InneCzworokaty *inneCzworokaty;
                if ((inneCzworokaty = menedzerFigur.znajdzCzworokatPoId(id)) != nullptr) {
                    inneCzworokaty->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy;
                if ((ostroslupTrojkatnyPrawidlowy = menedzerFigur.znajdzOstroslupTrojkatnyPrawidlowyPoId(id)) !=
                    nullptr) {
                    ostroslupTrojkatnyPrawidlowy->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                OstroslupCzworokatnyPrawidlowy *ostroslupCzworokatnyPrawidlowy;
                if ((ostroslupCzworokatnyPrawidlowy = menedzerFigur.znajdzOstroslupCzworokatnyPrawidlowyPoId(id)) !=
                    nullptr) {
                    ostroslupCzworokatnyPrawidlowy->wypiszDane();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            default:
                std::cout << "Dla aktualnego wezla nie moge utworzyc obiektu. Prosze przejsc do liscia." << std::endl;
        }
    }

    void modyfikujObiektZLisciaPoId() {
        int id;
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                Rownoboczny *rownoboczny;
                if ((rownoboczny = menedzerFigur.znajdzRownobocznyPoId(id)) != nullptr) {
                    rownoboczny->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneTrojkaty:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                InneTrojkaty *inneTrojkaty;
                if ((inneTrojkaty = menedzerFigur.znajdzInneTrojkatyPoId(id)) != nullptr) {
                    inneTrojkaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::InneCzworokaty:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                InneCzworokaty *inneCzworokaty;
                if ((inneCzworokaty = menedzerFigur.znajdzCzworokatPoId(id)) != nullptr) {
                    inneCzworokaty->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                OstroslupTrojkatnyPrawidlowy *ostroslupTrojkatnyPrawidlowy;
                if ((ostroslupTrojkatnyPrawidlowy = menedzerFigur.znajdzOstroslupTrojkatnyPrawidlowyPoId(id)) !=
                    nullptr) {
                    ostroslupTrojkatnyPrawidlowy->modifykuj();
                } else {
                    std::cout << "Nie znaleziono obiektu z takim id." << std::endl;
                }
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
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

    void usunObiektZLisciaPoId() {
        int id;
        switch (aktualnyWezel) {
            case Wezel::Rownoboczny:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                menedzerFigur.usunRownoboczny(id);
                break;
            case Wezel::InneTrojkaty:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                menedzerFigur.usunInneTrojkaty(id);
                break;
            case Wezel::InneCzworokaty:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                menedzerFigur.usunInneCzworokaty(id);
                break;
            case Wezel::OstroslupTrojkatnyPrawidlowy:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
                menedzerFigur.usunOstroslupTrojkatnyPrawidlowy(id);
                break;
            case Wezel::OstroslupCzworokatnyPrawidlowy:
                std::cout << "Podaj id obiektu." << std::endl;
                std::cin >> id;
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

};


#endif //PROJEKT_KONSOLA_H
