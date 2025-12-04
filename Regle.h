#ifndef JEU_DE_LA_VIE_REGLE_H
#define JEU_DE_LA_VIE_REGLE_H


class Regle {
public:
    virtual ~Regle();
    virtual Etat* Transition(Grille* grille, Cellule* cellule) = 0;
};


#endif //JEU_DE_LA_VIE_REGLE_H