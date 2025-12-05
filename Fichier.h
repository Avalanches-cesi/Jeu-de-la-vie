#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

class Fichier
{
private :
    int largeur;
    int longueur;
    std::string chemin;
    std::vector<std::vector<int>> matriceInitiale;
    std::filesystem::path dossierResultats;

public :
    Fichier();
    ~Fichier();
    void ChargerFichier(std::string& chemin);
    void SauvegarderGrille(std::string& cheminBase, const std::vector<std::vector<int>>& grille,int nbIterations) const;
    bool CreerDossier(const std::string& nomDossier);
    void SauvegarderGrilleDansDossier(const std::string& nomFichierBase, const std::vector<std::vector<int>>& grille, int nbIterations) const;
    int GetLargeur() const;
    int GetLongueur() const;
    const std::vector<std::vector<int>>&GetMatrice() const;
    std::string GetDossierResultats() const;
};

#endif
