#include "Affichage.h"
#include <iostream>
#include <string>
#include <vector>
#ifndef MODECONSOLE_H
#define MODECONSOLE_H

class ModeConsole : public Affichage
{
private:
    char carVivant;
    char carMort;
    std::string espace;

public:
    ModeConsole(char carVivant=1, char carMort=0, const std::string& espace ="");
    virtual ~ModeConsole() override;
    virtual void AfficherGrille(Grille& grille) override;
    void AfficherMatriceInitiale(const std::vector<std::vector<int>>& matrice);
    void AfficherDimensionsMatrice(int longueur, int largeur);
    void AfficherCreationDossier(const std::string& nomDossier, bool succes);
    void AfficherSauvegardeIteration(int iteration, const std::string& cheminFichier);
    void AfficherFinSimulation(int nombreIterations, const std::string& dossierResultats);
    void AfficherMatrice(const std::vector<std::vector<int>>& matrice);
    void AfficherErreur(const std::string& message);

};

#endif //MODECONSOLE_H