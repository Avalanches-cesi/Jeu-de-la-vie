#include "Etat.h"

class EtatMort : public Etat {
public:
    bool EstVivant () override{
    return false;
}
};