#ifndef PROJEKT_INNECZWOROKATY_H
#define PROJEKT_INNECZWOROKATY_H


#include <vector>
#include <algorithm>
#include "Czworokat.h"

class InneCzworokaty : public Czworokat {
private:
    double sredniaDlugoscBoku;
protected:
    double iloczynDlugosciBokow;

    void obliczSredniaDlugoscBoku();

    void obliczIloczynDlugosciBokow();

public:
    void obliczObwod() override;

    InneCzworokaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC, double bokD);

    InneCzworokaty(int kolor, std::string &nazwa, double bokA, double bokB, double bokC, double bokD, int id);

    void modifykuj() override;

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;

    static std::vector<InneCzworokaty *> liscie;

    static bool usunZListy(std::string &nazwa);

    static InneCzworokaty *znajdzNaLiscie(std::string &nazwa);

    static void wypiszWszystkie();
};


#endif //PROJEKT_INNECZWOROKATY_H
