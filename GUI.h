#ifndef JEU_DE_LA_VIE_GUI_H
#define JEU_DE_LA_VIE_GUI_H
#include "Affichage.h"


class GUI : Affichage {
public:
    void AfficherGrille(Grille* grille) override;
};


#endif //JEU_DE_LA_VIE_GUI_H