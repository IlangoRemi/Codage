#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

//Affiche les matrices
void afficherMatrice(int ** matrice, int tailleX, int tailleY){
    for(int i = 0; i < tailleX; i++){
        for(int j = 0; j < tailleY; j++){
            if(matrice[i][j] == 1)
                printf(" %i  ", matrice[i][j]);
            else
                printf("%i  ", matrice[i][j]);
        } 
        printf("\n");
    }
}

//Libère l'espace mémoire des matrice
void freeMatrice(int ** matrice,int tailleX){
    for (int i = 0; i< tailleX; i++){
        free(matrice[i]);
    }
    free(matrice);
}