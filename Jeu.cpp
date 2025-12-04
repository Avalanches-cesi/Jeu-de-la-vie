#include "Jeu.h"
#include "Grille.h"
#include "Regle.h"
#include "Affichage.h"
#include "Fichier.h"
#include <iostream>
#include <ostream>

    int Jeu::nbIteration = 0;

    int Jeu::nbIterationCPT = 0;

    bool Jeu::enExecution = false;

    Jeu::Jeu(void) : nbIteration(0), grille(nullptr), regle(nullptr),
    affichage(nullptr), enExecution(false), grilleInitiale(nullptr) {}

    Jeu::~Jeu() {
        if (grille != nullptr) {delete grille;}
        if (regle != nullptr) {delete regle;}
        if (affichage != nullptr) {delete affichage;}
        if (grilleInitiale != nullptr) {delete grilleInitiale;}
    }

    void Jeu::setGrille(Grille* g) {
        grille = g;
    }

    void Jeu::setRegle(Regle* r) {
        regle = r;
    }

    void Jeu::setAffichage(Affichage* a) {
        affichage = a;
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

        affichage->AfficherGrille(*grille);

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


