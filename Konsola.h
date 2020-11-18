//
// Created by wojtek on 18.11.2020.
//

#ifndef PROJEKT_KONSOLA_H
#define PROJEKT_KONSOLA_H


#include "MenedzerFigur.h"

class Konsola {
    MenedzerFigur menedzerFigur;
    std::string aktualnyWezel = "FiguryGeometryczne";

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

        std::cout << "Podaj etykiete wierzcholka";
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

    bool usunOstroslupTrojkatnyPrawidlowy() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunOstroslupTrojkatnyPrawidlowy(id);
    }

    bool usunInneTrojkaty() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunInneCzworokaty(id);
    }

    bool usunRownoboczny() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunRownoboczny(id);
    }

    bool usunOstroslupCzworokatnyPrawidlowy() {
        int id;
        std::cout << "Podaj id" << std::endl;
        std::cin >> id;
        menedzerFigur.usunOstroslupCzworokatnyPrawidlowy(id);
    }


    void wypiszTrojkatyRownoboczne() {
        for (auto &element : menedzerFigur.getLiscieRownoboczny()) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszInneTrojkaty() {
        for (auto &element : menedzerFigur.getLiscieInneTrojkaty()) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszInneCzworokaty() {
        for (auto &element : menedzerFigur.getLiscieInneCzworokaty()) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszOstroslupyTrojkatnePrawidlowe() {
        for (auto &element : menedzerFigur.getLiscieOstroslupTrojkatnyPrawidlowy()) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }

    void wypiszOstroslupyCzworokatnePrawidlowe() {
        for (auto &element : menedzerFigur.getLiscieOstroslupCzworokatnyPrawidlowy()) {
            element->wypiszDane();
            std::cout << std::endl;
        }
    }


};


#endif //PROJEKT_KONSOLA_H
