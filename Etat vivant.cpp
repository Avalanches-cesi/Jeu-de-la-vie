#include "Etat.h"

class EtatVivant : public Etat {
public:
    bool EstVivant() override {
    return true;
}
};