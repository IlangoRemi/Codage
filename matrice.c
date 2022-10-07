#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

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

void freeMatrice(int ** matrice,int tailleX){
    for (int i = 0; i< tailleX; i++){
        free(matrice[i]);
    }
    free(matrice);
}

int ** matriceCreer(int tailleX, int tailleY){
    int ** matrice = malloc(tailleX * sizeof(int*));
    if( matrice == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    for (int i = 0;i<tailleX;i++){
        matrice[i] = malloc(tailleY * sizeof(int));
        if( matrice[i] == NULL ){
          fprintf(stderr,"Allocation impossible");
          exit(EXIT_FAILURE);
        }
    }
    return matrice;
}