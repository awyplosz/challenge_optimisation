#include <stdio.h>
#include <stdlib.h>

char poubelle[50];
int nb_ligne;

typedef struct {
    int nb_ligne;
    int nb_colonne;
    char nom[50];
    int donnee;
} Element;

float* lireFichier(const char* nomFichier) {
    
    Element element;
    int** matrice_fichier;

    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }
    

    fscanf(fichier, "%s %d", poubelle, element->nb_ligne);
    fscanf(fichier, "%s %d", poubelle, element->nb_colonne);


    matrice_fichier = (int**) malloc((element->nb_ligne)*sizeof(int*));
		for(int i = 0; i < *nb_sommets; i++) 
			 matrice_fichier[i] = (int*) malloc((element->nb_sommet)*sizeof(int)); 
		
		for (int i = 0; i < element->ligne; i++)
			for (int j = 0; j < element->nb_colonne; j++) 
				matrice_fichier[i][j] = 0;


    while (fscanf(fichier, "%s %d", elements[*nbLignes].nom, &elements[*nbLignes].donnee) == 2) {
        (*nbLignes)++;
    }

    fclose(fichier);

    for (int i = 0; i < *nbLignes; i++) {
        if (elements[i].donnee == -1) {
            matrice[i][0] = -1; // obstacle
        } else if (elements[i].donnee == 1) {
            matrice[i][0] = 1; // cible
        } else {
            matrice[i][0] = 0; // autre donnée
        }
    }
}

int creation_matrice(const char* fichier) {
    
    int** matrice;
    matrice = lireFichier(fichier, matrice);

    // Afficher la matrice pour vérification
    for (int i = 0; i < nbLignes; i++) {
        printf("%d\n", matrice[i][0]);
    }

    return 0;
}
