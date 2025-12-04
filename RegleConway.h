#ifndef JEU_DE_LA_VIE_REGLECONWAY_H
#define JEU_DE_LA_VIE_REGLECONWAY_H
#include "Regle.h"


class RegleConway : Regle {
public:
    RegleConway(void);
    ~RegleConway();
    Etat Transition(Grille* g, Cellule* c) override;
    void setRegle();
};



#endif //JEU_DE_LA_VIE_REGLECONWAY_H