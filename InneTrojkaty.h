#ifndef PROJEKT_INNETROJKATY_H
#define PROJEKT_INNETROJKATY_H


#include <vector>
#include <algorithm>
#include "Trojkat.h"

class InneTrojkaty : public Trojkat {
private:
    double sredniaDlugoscBoku;
protected:
    double najkrotszyBok;

    void obliczSredniaDlugoscBoku();

    void obliczNajkrotszyBok();

public:
    InneTrojkaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC);

    InneTrojkaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC, int id);

    void modifykuj() override;

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;

    static std::vector<InneTrojkaty *> liscie;

    static bool usunZListy(std::string &nazwa);

    static InneTrojkaty *znajdzNaLiscie(std::string &nazwa);

    static void wypiszWszystkie();
};


#endif //PROJEKT_INNETROJKATY_H
