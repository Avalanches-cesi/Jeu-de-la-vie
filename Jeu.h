#ifndef JEU_DE_LA_VIE_JEU_H
#define JEU_DE_LA_VIE_JEU_H
#include <string>

class Jeu {
private:
    Grille* grilleInitiale;
public:
    int nbIteration;
    bool enExecution;
    int nbIterationCPT;
    Jeu(void);
    ~Jeu() {}
    void setGrille(Grille* g);
    void setRegle(Regle* r);
    void setAffichage(Affichage* a);
    void chargerDepuisFichier(std::string chemin);
    void Demarrer();
    void pasDeSimulation();
    void Arreter();
    void Reset();
};


#endif //JEU_DE_LA_VIE_JEU_H