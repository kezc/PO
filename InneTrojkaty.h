//
// Created by wojtek on 13.11.2020.
//

#ifndef PROJEKT_INNETROJKATY_H
#define PROJEKT_INNETROJKATY_H


#include "Trojkat.h"

class InneTrojkaty : public Trojkat {
private:
    double sredniaDlugoscBoku;
protected:
    double najkrotszyBok;

    void obliczSredniaDlugoscBoku();

    void obliczNajkrotszyBok();

public:
    InneTrojkaty(int kolor, double bokA, double bokB, double bokC);


public:

    double getSredniaDlugoscBoku() const;

    double getNajkrotszyBok() const;

    void modifykuj() override;

    void wypiszDane() override;

    void zapiszDoPliku(std::ofstream &plik) override;

};


#endif //PROJEKT_INNETROJKATY_H
