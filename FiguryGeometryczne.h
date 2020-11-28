//
// Created by wojtek on 02.11.2020.
//

#ifndef PROJEKT_FIGURYGEOMETRYCZNE_H
#define PROJEKT_FIGURYGEOMETRYCZNE_H


#include <fstream>

class FiguryGeometryczne {
    static int licznik;
    int id;
protected:
    int kolor;
    std::string nazwa;
public:
    int getKolor() const;

    void ustawKolor(int kolor);

    FiguryGeometryczne(int kolor, std::string &nazwa);

    int getId() const;

    virtual void modifykuj() = 0;

    virtual void wypiszDane() = 0;

    virtual void zapiszDoPliku(std::ofstream &plik) = 0;

    void setId(int id);

    virtual ~FiguryGeometryczne() = default;

    static void ustawLicznik(int licznik);

    const std::string &getNazwa() const;
};


#endif //PROJEKT_FIGURYGEOMETRYCZNE_H
