#ifndef PROJEKT_INNECZWOROKATY_H
#define PROJEKT_INNECZWOROKATY_H


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

    InneCzworokaty(int kolor,std::string &nazwa, double bokA, double bokB, double bokC, double bokD);

    void modifykuj() override;

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;
};


#endif //PROJEKT_INNECZWOROKATY_H
