#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation_matrice.h"




int** lireFichier(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }
    int **matrice_fichier;
    int test_nom;
    Element element;

    fscanf(fichier, "%s %d %s %d", element.nom_ligne, &nb_ligne, element.nom_colonne, &nb_colonne);

    

    matrice_fichier = (int**)malloc(nb_ligne * sizeof(int*));
    for (int i = 0; i < nb_ligne; i++) {
        matrice_fichier[i] = (int*)malloc(nb_colonne * sizeof(int));
    }

    for (int k = 0 ; k < nb_ligne ; k++)
    {
        for (int c = 0 ; c < nb_colonne ; c++)
            matrice_fichier[k][c] = 0;
    }

    while (fscanf(fichier, "%s %d %d",element.nom, &element.ligne, &element.colonne)==3) {
        test_nom = strcmp("CIBLE",element.nom);
        if (test_nom==0){
            matrice_fichier[element.ligne][element.colonne] = 1;
        }
        else matrice_fichier[element.ligne][element.colonne] = -1;
    }

    fclose(fichier);
    return matrice_fichier;
    
}

int** creation_matrice(const char* nom_fichier) {
    int** matrice;

    matrice = lireFichier(nom_fichier);

    // Afficher la matrice pour vérification
    for (int i = 0; i < nb_ligne; i++) {
        printf("\n");
        for (int j = 0; j < nb_colonne ; j++)
        printf(" %d ", matrice[i][j]);
    }

    return creation_matrice;
}
