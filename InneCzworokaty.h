#ifndef PROJEKT_INNECZWOROKATY_H
#define PROJEKT_INNECZWOROKATY_H


#include "Czworokat.h"

class InneCzworokaty : public Czworokat {
private:
    double sredniaDlugoscBoku;
protected:
    double iloczynDlugosciBokow;

    void obliczSredniaDluscBoku();

    void obliczIloczynDlugosciBokow();

public:
    void obliczObwod() override;
};


#endif //PROJEKT_INNECZWOROKATY_H
