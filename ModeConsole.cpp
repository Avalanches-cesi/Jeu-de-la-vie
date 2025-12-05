#include "Affichage.h"
#include "ModeConsole.h"
#include "Fichier.h"
#include <iostream>

//=================================CONSTRUCTEUR=========================================================================
ModeConsole::ModeConsole(char carVivant, char carMort, const std::string& espace):
carVivant(carVivant),
carMort(carMort),
espace(espace)
{

}

//==================================DESTRUCTEUR=========================================================================
ModeConsole::~ModeConsole()
{

}
//======================================================================================================================


//==================================VOID================================================================================

void ModeConsole::AfficherGrille(Grille& grille)
{
    AfficherMatrice(grille.GetEtatActuel());
}

void ModeConsole::AfficherMatriceInitiale(const std::vector<std::vector<int>>& matrice)
{
    std::cout << "\n=== Matrice initiale ===\n";
    AfficherMatrice(matrice);
    std::cout << "=======================\n";
}

void ModeConsole::AfficherDimensionsMatrice(int longueur, int largeur)
{
    std::cout << "Dimensions de la matrice: " << longueur << "x" << largeur << std::endl;
}

void ModeConsole::AfficherCreationDossier(const std::string& nomDossier, bool succes) {
    if (succes) {
        std::cout << "Dossier créé avec succès: " << nomDossier << std::endl;
    } else {
        std::cout << "Échec de la création du dossier: " << nomDossier << std::endl;
    }
}

void ModeConsole::AfficherSauvegardeIteration(int iteration, const std::string& cheminFichier) {
    std::cout << "État de la grille à l'iteration " << iteration << " sauvegardé dans: " << cheminFichier << std::endl;
}

void ModeConsole::AfficherFinSimulation(int nombreIterations, const std::string& dossierResultats) {
    std::cout << "Simulation terminee "<<std::endl;
    std::cout << "Nombre total d'iterations: " << nombreIterations << std::endl;
    std::cout << "Les resultats ont ete sauvegardes dans le dossier: " << dossierResultats << std::endl;
}

void ModeConsole::AfficherMatrice(const std::vector<std::vector<int>>& matrice) {
    for (const auto& ligne : matrice) {
        for (int cellule : ligne) {
            std::cout << (cellule ? carVivant : carMort) << espace;
        }
        std::cout << std::endl;
    }
}

void ModeConsole::AfficherErreur(const std::string& message) {
    std::cerr << "ERREUR: " << message << std::endl;
}
//======================================================================================================================


