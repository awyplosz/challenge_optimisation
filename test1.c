#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation_matrice.h"

int main (){

    const char* fichier = "gr6.txt";
    int** matrice;

        matrice = lireFichier(fichier);

        affichage_matrice(matrice);

    return 0;
}