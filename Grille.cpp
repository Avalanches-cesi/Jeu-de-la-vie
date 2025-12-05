#include "Grille.h"
#include <vector>
#include "Cellule.h"
#include "Fichier.h"
#include "Regle.h"
#include <iostream>

class Grille {  //La classe permet de représenter les grille du jeu
private:
    int largeur; //Largeur de notre grille
    int longueur; //Longueur de notre grille
    std :: vector<std :: vector<Cellule>> cellule; //Vecteur de vecteur, permet de contenir l'ensemble de nos cellules
    Fichier* fichierdeBase; //Poiteur fichierdeBase vers Fichier pour récupérer les informations nécessaires a la conception de notre grille

public:
    int nbIterationsCPT; //Compteur du nombre d'itérations
    Grille(int longueur, int largeur) : longueur(longueur), largeur(largeur){ //Constructeur, il permet d'initialiser notre grille
        cellule.resize(longueur); //Dimensionne le vecteur cellule pour qu'il est la taille de longueur, chaque élément est lui même un vecteur de cellules
        for (int i=0; i<longueur; i++){  //Parcours chaque vecteur
            cellule[i].resize(largeur); //Détermine la taille des vecteurs internes comment étant de la même taille que largeur
            for (int j=0; j<largeur; j++){ // Boucle imbriquée qui permet de parcourir chaque cellule
            cellule[i][j] = Cellule(i,j,false); //Instance chaque cellule avec pour coordonnées i,j et avec comme état par défaut false (mort)

        }
    }
}
    ~Grille(){ //Destructeur pour éviter les fuites de mémoire
    for (int i=0; i<longueur; i++){
        for (int j=0; j<largeur; j++){

        }
    }
}
    int Grille::GetLongueur() const {
        return longueur;
    }
    int Grille::GetLargeur() const{
        return largeur;
    }
    Cellule& GetCellule(int i, int j){

        return cellule[i][j];
    }

    int Grille::Voisins(int i, int j){
    for (int pi = -1 ; pi < pi-1 ; pi++){
        for (int pj = -1 ; pj < pj-1 ; pj++){
            if(pi == 0 && pj == 0) continue;
                int ni = i + pi;
                int nj = j + pj;
            int compteur = 0;
            if (cellule[i][j] == Cellule(i,j,true)){
                    compteur++;}

        }
    }
    return compteur;
}
    void Grille::InitialiserDepuisFichier (Fichier& fichier){ //Permet de récupérer toutes les informations nécessaire depuis fichier afin de pour déterminer la taille de notre grille ainsi que l'état initiale de nos cellules
        fichierdeBase = &fichier; //Crée fichierdeBase, qui permet de sotcker l'adresse mémoire de fichier
        longueur = fichier.GetLongueur(); //Récupération de la longueur de notre grille initiale
        largeur = fichier.GetLargeur(); //Récupération de la largeur de notre grille initiale
        if (longueur != fichier.GetLongueur()) || largeur != fichier.GetLargeur()){ //Vérifie que la longueur et la largeur sont bien égale à celle du fichier initiale
            std :: cout << ("Les dimensions ne sont pas les mêmes que depuis le fichier initiale") << std :: endl;
            return;
        }
        int matriceInitiale = fichier.GetMatriceInitiale(); //Entier stockant la matrice initiale
        for (int i=0; i<longueur; i++){
            for (int j=0; j<largeur; j++){ //Parcours chaque cellule
                if (matriceInitiale[i][j] == Cellule(i,j,true)){ //Vérifie l'état de nos cellule dans la matrice initiale
                    cellule[i][j].setEtat(new Vivant);
                } else {
                    cellule[i][j].setEtat(new Mort);
                }
            }
        }
    }



    }
    /*void Grille::Iteration (Regle& regle){
        Grille* grilleB = new Grille(longueur, largeur);
        for (int i=0; i<longueur; i++){
            for (int j=0; j<largeur; j++){
                Cellule& celluleactuelle = GetCellule(i,j);
                Cellule& celluleB = grilleB->GetCellule(i,j);
                Etat* nouveletat = regle.Transition(this, celluleactuelle=);
                celluleB.SetEtat(nouveletat);

            }
        }

    }*/
    void Grille::Copier(Grille* base){ //
    for (int i=0; i<longueur; i++){
        for (int j=0; j<largeur; j++){
            Etat* etatbase = base->GetCellule(i,j).getEtat();

        if (etatbase->Vivant ){
            cellule[i][j].setEtat(new Vivant);
        } else {
            cellule[i][j].setEtat(new Mort);
            }
        }
    }
}
    void Grille::pasDeSimulation(Regle* regle) {
    if (grille == nullptr || regle == nullptr) {
        std::cerr << "Erreur de simulation" << std::endl;
        return;
    }

    //Création de la copie de la grille actuelle
    Grille* grilleTemp = new Grille(longueur, largeur);
    grilletemp->Copier(grille);

    // Parcourir chaque cellule et appliquer la règle
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            Cellule* cellule = GetCellule(i, j);
            Etat* nouvelEtat = regle->Transition(this, &celluleactuelle);
            grilleTemp->GetCellule(i, j)->setEtat(nouvelEtat);
        }
    }
    this -> Copier(grilleTemp);


    // Remplacer l'ancienne grille par la nouvelle
    Grille* temp = grille;      //Sauvegarde temporaire de l'ancienne grille
    grille = grilleTemp;        //Remplacement par la nouvelle grille
    delete temp;                //Libération de la mémoire de l'ancienne grille

    nbIterationCPT++;

}
};
