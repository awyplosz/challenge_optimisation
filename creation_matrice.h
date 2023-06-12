typedef struct {
    char nom[50];
    char nom_colonne[10];
    char nom_ligne[10];
    int ligne;
    int colonne;
} Element;

extern volatile int nb_ligne, nb_colonne;


int** lireFichier(const char* nomFichier);

void affichage_matrice(int** matrice);