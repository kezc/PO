//
// Created by wojtek on 13.11.2020.
//

#include "InneCzworokaty.h"

void InneCzworokaty::obliczObwod() {
    ustawObwod(bokA + bokB + bokC + bokD);
}

void InneCzworokaty::obliczSredniaDluscBoku() {
    sredniaDlugoscBoku = getObwod() / 4.0;
}

void InneCzworokaty::obliczIloczynDlugosciBokow() {
    iloczynDlugosciBokow = bokA * bokB * bokC * bokD;
}
