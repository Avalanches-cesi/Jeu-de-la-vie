#include "Grille.h"
#include <vector>
#include "Cellule.h"
#include "Fichier.h"
#include "Regle.h"
#include <iostream>

class Grille {
private:
    int largeur;
    int longueur;
    std :: vector<std :: vector<Cellule>> cellule;

public:
    Grille(int longueur, int largeur) longueur(longueur), largeur(largeur){
        for (int i=0; i<longueur; i++){
            cellule.resize(longueur);
            for (int j=0; j<largeur; j++){
                cellule.resize(largeur);
            cellule[i][j] = Cellule(i,j,false);

        }
    }
}
    Grille :: ~Grille(){
    for (int i=0; i<longueur; i++){
        delete [] cellule[i];
    for (int j=0; j<largeur; j++){
        delete [] cellule[i][j];
        }
        }
    }
    int fichier.GetLongueur(){
        return longueur;
    }
    int GetLargeur(){
        return largeur;
    }
    Cellule& GetCellule(int i, int j){

        return cellule[i][j];
    }

    int Voisins(int i, int j){
    for (int pi = -1 ; pi < pi-1 ; pi++){
        for (int pj = -1 ; pj < pj-1 ; pj++){
            if(pi == 0 && pj == 0) continue;
            int compteur = 0;
            if (cellule[i][j] == Cellule(i,j,true)){
                    compteur++;}

        }
    }
    return compteur;
}
    void InitialiserDepuisFichier (Fichier& fichier){
        if (longueur != fichier.GetLongueur()) || largeur != fichier.GetLargeur()){
            std :: cout << ("Les dimensions ne sont pas les mêmes que depuis le fichier initiale") << std :: endl;
        }
        bool** matriceInitiale = fichier.GetMatriceInitiale();
        for (int i=0; i<longueur; i++){
            for (int j=0; j<largeur; j++){
                if (matriceInitiale[i][j])){
                    cellule[i][j].setEtat(new EtatVivant);
                } else {
                    cellule[i][j].setEtat(new EtatMort);
                }
            }
        }
    }



    }
    void Iteration (Regle& regle){
        Grille* grilleB = new Grille(longueur, largeur);
        for (int i=0; i<longueur; i++){
            for (int j=0; j<largeur; j++){
                Cellule& celluleactuelle = GetCellule(i,j);
                Cellule& celluleB = grilleB->GetCellule(i,j);
                Etat* nouveletat = regle.Transition(this, celluleactuelle=);
                celluleB.SetEtat(nouveletat);

            }
        }
        Copier(grilleB);
    }
    void Copier (Grille* nouvelle);
};