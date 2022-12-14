#include "hadamard.h"
#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int getTailleHadamard(int nbUti){
    int i = 1;
    while(nbUti>pow(2,i))
        i++;
    return pow(2,i);
}


int ** hadamard(int taille){

    int ** matrice = matriceCreer(taille,taille);

    matrice[0][0] = 1; // H(0) = 1
    
    //Génération de la matrice d'Hadamard
    for(int i = 1; i < taille; i+=i){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++){
                matrice[j+i][k] = matrice[j][k];
                matrice[j][k+i] = matrice[j][k];
                matrice[i+j][i+k] = -matrice[j][k];
            }
        }
    }

    afficherMatrice(matrice,taille,taille);
    
    return matrice;
}

