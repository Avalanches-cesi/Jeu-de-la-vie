#include "RegleConway.h"

RegleConway::RegleConway(void) : Transition(Transition) {}

RegleConway::~RegleConway() {

}

virtual Etat RegleConway::Transition(Grille* g, Cellule* c) {
    // Vérification des pointeurs
    if (g == nullptr || c == nullptr) {
        // En cas d'erreur, retourner un état par défaut
        return Etat();  // Supposons qu'Etat a un constructeur par défaut
    }

    // Obtenir l'état actuel de la cellule
    Etat etatActuel = c->getEtat();

    // Obtenir les coordonnées de la cellule
    int x = c->getX();
    int y = c->getY();

    // Compter les voisins vivants
    int voisinsVivants = 0;

    // Parcourir les 8 cellules voisines
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            // Ignorer la cellule elle-même
            if (dx == 0 && dy == 0) {
                continue;
            }

            // Calculer les coordonnées du voisin
            int nx = x + dx;
            int ny = y + dy;

            // Vérifier si les coordonnées sont valides (dans les limites de la grille)
            if (nx >= 0 && nx < g->getLongueur() && ny >= 0 && ny < g->getLargeur()) {
                // Obtenir la cellule voisine
                Cellule* voisin = g->GetCellule(nx, ny);

                // Vérifier si le voisin est vivant
                if (voisin != nullptr && voisin->getEtat().estVivant()) {
                    voisinsVivants++;
                }
            }
        }
    }

    // Appliquer les règles du jeu de la vie de Conway

    // Si la cellule est vivante
    if (etatActuel.estVivant()) {
        // Une cellule vivante avec moins de 2 voisins vivants meurt (sous-population)
        if (voisinsVivants < 2) {
            return Etat(false);  // Mort
        }
        // Une cellule vivante avec 2 ou 3 voisins vivants survit
        else if (voisinsVivants == 2 || voisinsVivants == 3) {
            return Etat(true);  // Survie
        }
        // Une cellule vivante avec plus de 3 voisins vivants meurt (surpopulation)
        else {
            return Etat(false);  // Mort
        }
    }
    // Si la cellule est morte
    else {
        // Une cellule morte avec exactement 3 voisins vivants devient vivante (reproduction)
        if (voisinsVivants == 3) {
            return Etat(true);  // Naissance
        }
        // Sinon, elle reste morte
        else {
            return Etat(false);  // Reste morte
        }
    }
}

void RegleConway::setRegle(Regle* r) {
    RegleConway = r;
}

