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

    double getSredniaDlugoscBoku() const;

    double getIloczynDlugosciBokow() const;

    InneCzworokaty(int kolor, double bokA, double bokB, double bokC, double bokD);
};


#endif //PROJEKT_INNECZWOROKATY_H
