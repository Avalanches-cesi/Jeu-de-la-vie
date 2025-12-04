#ifndef Affichage_H
#define Affichage_H

class Affichage
{

public:

    virtual ~Affichage();
    virtual void AfficherGrille(Grille& grille)=0;

};

#endif //Affichage_H
