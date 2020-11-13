//
// Created by wojtek on 02.11.2020.
//

#ifndef PROJEKT_FIGURYGEOMETRYCZNE_H
#define PROJEKT_FIGURYGEOMETRYCZNE_H


class FiguryGeometryczne {
    //dodaj prywatne
    static int licznik;
    int id;
protected:
    int kolor;
public:
    int getKolor() const;

    void ustawKolor(int kolor);

    FiguryGeometryczne(int kolor);

    int getId() const;

    static void ustawLicznik(int licznik);
};


#endif //PROJEKT_FIGURYGEOMETRYCZNE_H
