#include <Cellule.h>

class Cellule {
private:
    int i; //Coordonnées de notre cellule pour la grille
    int j;
    Etat* etat;

public:
    Cellule(int i = 0 , int j = 0 , Etat* etat = nullptr) int i(i), j(j), etat(etat);{ //Initialise notre cellule
    /*this->i = i;
    this->j = j;
    this->etat = etat; */

    }
    ~Cellule(){  //Destructeur : permet de libérer la mémoire allouée
    if ( etat != nullptr ){
        delete etat;
        }
    }
    Etat* getEtat() const {  //Retourne l'état actuel de la cellule
        return etat;
    }

    void setEtat(Etat* nouveletat){  //Modifie l'état de la cellule
        if (etat == nullptr ){
            delete etat;
        }
            etat = nouveletat;
        }

    }
    bool Estvivant() const {  //Détermine si la cellule est vivante ou morte
        if ( etat != nullptr ) const {
            return etat->Estvivant();
        } else if ( etat == nullptr ){
            return etat->Estmort;
        }
    }
};