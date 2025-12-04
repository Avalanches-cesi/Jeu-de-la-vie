#include "Fichier.h"
#include "Grille.h"
#include <fstream>
#include <stdexcept>
#include <filesystem>


//===================CONSTRUCTEUR=======================================================================================
Fichier::Fichier() : largeur(0), longueur(0), chemin("")
{
    dossierResultats="";
}
//======================================================================================================================


//=================DESTRUCTEUR==========================================================================================
Fichier::~Fichier()
{

}
//======================================================================================================================



//================VOID==================================================================================================
void Fichier::ChargerFichier(std::string& chemin)
{
    //ouvrir le fichier
    this->chemin = chemin;
    std::ifstream fichier(chemin);
    if (!fichier.is_open())
    {
        throw std::runtime_error ("Impossible d'ouvrir le fichier");
    }

    //récuper taille matrice
    std::string ligne;
    std::getline(fichier, ligne);

    if (ligne.empty())
    {
        throw std::runtime_error ("Fichier invalide");
    }
    if (ligne.length()>=2)
    {
        char longueurchar=ligne[0];
        char largeurchar=ligne[1];

        this->longueur = longueurchar - '0';
        this->largeur = largeurchar - '0';

        if (this->longueur<=0 || this->largeur<=0)
        {
            throw std::runtime_error ("Dimension invalide");
        }

    }
    else
    {
        throw std::runtime_error ("Format de dimension invalide");
    }
    matriceInitiale.clear();
    matriceInitiale.resize(longueur, std::vector<int>(longueur, 0));

    std::string ligneM;
    int indiceLigne=0;

    while (std::getline(fichier, ligneM) && indiceLigne<longueur)
    {
        if (ligneM.length()<static_cast<size_t>(largeur))
        {
            throw std::runtime_error ("ligne trop courte dans le fichier");
        }
        for (int j = 0; j < largeur; ++j)
        {
            if (ligneM[j] == '1') {
                matriceInitiale[indiceLigne][j] = 1;
            }
            else if (ligneM[j] == '0') {
                matriceInitiale[indiceLigne][j] = 0;
            }
            else{
               throw std::runtime_error ("Caractere invalide");
            }
        }
        ++indiceLigne;

    }

    if (indiceLigne < longueur)
    {
        throw std::runtime_error ("pas assez de lignes");
    }
    fichier.close();

}
void Fichier::SauvegarderGrille(std::string& cheminBase, const std::vector<std::vector<int>>& grille,int nbIterations) const {
    std::string cheminComplet;

    // Si le chemin contient une extension, l'insérer avant l'extension
    std::filesystem::path cheminPath(cheminBase);
    std::filesystem::path stem = cheminPath.stem(); // Nom sans extension
    std::filesystem::path ext = cheminPath.extension(); // Extension

    // Créer le nouveau chemin avec le numéro d'itération
    std::filesystem::path nouveauChemin = stem.string() + "_iter" + std::to_string(nbIterations) + ext.string();
    cheminComplet = nouveauChemin.string();




    // Ouvrir le fichier pour écriture
    std::ofstream fichier(cheminComplet);

    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier pour ecriture: " + cheminComplet);
    }


    fichier << longueur << largeur << std::endl;

    for (size_t i = 0; i < grille.size(); ++i) {
        for (size_t j = 0; j < grille[i].size(); ++j) {
            fichier << grille[i][j];
        }

        fichier << std::endl;
    }

    fichier.close();
    std::cout << "Etat de la grille à l'iteration " << nbIterations << " sauvegarde dans : " << cheminComplet << std::endl;
}
bool Fichier::CreerDossier(const std::string& nomDossier) {
    try {
        // Convertir le nom du dossier en chemin filesystem
        dossierResultats = std::filesystem::path(nomDossier);

        // Créer le dossier et tous les dossiers parents nécessaires
        std::filesystem::create_directories(dossierResultats);

        // Vérifier si le dossier existe maintenant
        if (std::filesystem::exists(dossierResultats) && std::filesystem::is_directory(dossierResultats)) {
            std::cout << "Dossier cree avec succes: " << dossierResultats << std::endl;
            return true;
        } else {
            std::cerr << "Echec de la creation du dossier: " << dossierResultats << std::endl;
            return false;
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Erreur filesystem lors de la creation du dossier: " << e.what() << std::endl;
        return false;
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur lors de la création du dossier: " << e.what() << std::endl;
        return false;
    }
}

void Fichier::SauvegarderGrilleDansDossier(const std::string& nomFichierBase, const std::vector<std::vector<int>>& grille, int nbIterations) const {
    if (dossierResultats.empty()) {
        throw std::runtime_error("Aucun dossier de resultats n'a ete cree. Utilisez CreerDossierResultats d'abord.");
    }

    // Construire le nom du fichier avec l'itération
    std::string nomFichierAvecIter;
    size_t pos = nomFichierBase.find_last_of('.');
    if (pos != std::string::npos) {
        nomFichierAvecIter = nomFichierBase.substr(0, pos) + "_iter" + std::to_string(nbIterations) + nomFichierBase.substr(pos);
    } else {
        nomFichierAvecIter = nomFichierBase + "_iter" + std::to_string(nbIterations) + ".txt";
    }

    // Construire le chemin complet dans le dossier de résultats
    std::filesystem::path cheminComplet = dossierResultats / std::filesystem::path(nomFichierAvecIter);
    std::string cheminStr = cheminComplet.string();

    // Ouvrir le fichier pour écriture
    std::ofstream fichier(cheminStr);

    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier pour ecriture: " + cheminStr);
    }

    // Écrire les dimensions sur la première ligne
    fichier << grille.size() << grille[0].size() << std::endl;

    // Écrire la matrice
    for (size_t i = 0; i < grille.size(); ++i) {
        for (size_t j = 0; j < grille[i].size(); ++j) {
            fichier << grille[i][j];
        }
        fichier << std::endl;
    }

    fichier.close();

    std::cout << "Etat de la grille à l'iteration " << nbIterations << " sauvegarde dans : " << cheminStr << std::endl;
}
//======================================================================================================================





//=================Getteurs==============================================================================================
int Fichier::GetLargeur() const
{
    return largeur;
}
int Fichier::GetLongueur() const
{
    return longueur;
}
const std::vector<std::vector<int>>& Fichier::GetMatrice() const
{
    return matriceInitiale;
}
std::string Fichier::GetDossierResultats() const
{
    return dossierResultats.string();
}
//=======================================================================================================================
