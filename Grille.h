
class Grille {
private:
    int largeur;
    int longueur;

public:
    Grille(int largeur, int longueur);
    ~Grille();
    Cellule& GetCellule(int i, int j);
    int GetLongueur();
    int GetLargeur();
    int Voisins(int i, int j);
    void InitialiserDepuisFichier (Fichier& fichier);
    void Iteration (Regle& regle);
    void PasDeSimulation();


};
