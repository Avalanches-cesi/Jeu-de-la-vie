#include "Jeu.h"
#include "Grille.h"
#include "Regle.h"
#include "Affichage.h"
#include "Fichier.h"
#include <iostream>
#include <ostream>

    int Jeu::nbIteration = 0;

    bool Jeu::enExecution = false;

    Jeu::Jeu(void) : nbIteration(0), enExecution(false), grilleInitiale(nullptr) {}

    Jeu::~Jeu() {
        if (Grille != nullptr) {delete Grille;}
        if (Regle != nullptr) {delete Regle;}
        if (Affichage != nullptr) {delete Affichage;}
        if (grilleInitiale != nullptr) {delete grilleInitiale;}
        if (nbIteration != 0) {delete nbIteration;}
    }

    void Jeu::setGrille(Grille* g) {
        Grille = g;
    }

    void Jeu::setRegle(Regle* r) {
        Regle = r;
    }

    void Jeu::setAffichage(Affichage* a) {
        Affichage = a;
    }

    void Jeu::chargerDepuisFichier(std::string chemin) {
        Fichier fichier;
        if (fichier.ChargerFichier(chemin)) {
            if (grille != nullptr) {
                delete grille;
            }

            grille = new Grille(fichier.GetLongueur(), fichier.GetLargeur());
            grille->DepuisMatrice(fichier.GetMatriceInitiale());
        }
        else {
            std::cerr << "Erreur lors du chargement du fichier" << chemin << std::endl;
        }
    }

    void Jeu::Demarrer() {
        if (grille == nullptr || regle == nullptr || affichage == nullptr) {
            std::cerr << "Erreur lors du démarrage : grille, règle ou affichage manquant" << std::endl;
            return;
        }

        enExecution = true;

        nbIterationCPT = 0;

        // Exécuter le nombre d'itérations spécifié par l'utilisateur
        for (int i = 0; i < nbIteration; i++) {
            pasDeSimulation();
            affichage->AfficherGrille(*grille);
        }

        //Arret de simulation lorsque le nombre d'itérations demandé a été atteint
        while (enExecution == true) {
            if (nbIteration >= nbIterationCPT) {
                enExecution = false;
            }
        }

    }

    void Jeu::Arreter(){
        if (enExecution == true) {
            enExecution = false;
            std::cout << "Simulation arretée" << std::endl;
        }
        else {std::cout << "Aucune simulation en cours" << std::endl;}
    }

    void Jeu::Reset() {
        if (enExecution == true) {
            Arreter();
        }

        nbIteration = 0;

        //Reset la grille avec l'initale
        if (grille != nullptr && Fichier != nullptr) {
            grille->DepuisMatrice(Fichier->GetMatriceInitiale());
        }

        std::cout << "Simulation réinitialisée" << std::endl;

        //Reset affichage
        if (affichage != nullptr && grille != nullptr) {
            affichage -> AfficherGrille(*grille);
        }
    }


