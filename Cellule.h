
class Cellule {
private:
    int i;
    int j;
    Etat* etat;

public:
    Cellule(int i, int j, Etat* etat);
    ~Cellule();
    Etat getEtat() const = 0;
    void setEtat(Etat* nouveletat);
    bool Estvivant() const = 0;
};
