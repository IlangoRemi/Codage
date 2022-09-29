#include<stdio.h>
#include<stdlib.h>
#include <math.h>


int ** hadamard(int n){
    int i, j, k;

    int ln = pow(2,n);
    int ** matrice;

    matrice[0][0] = 1; // H(0) = 1

    //Génération de la matrice d'Hadamard
    for(k = 1; k < ln; k +=k){
        for(i = 0; i < k; i++){
            for(j = 0; j < k; j++){
                matrice[i+k][j] = matrice[i][j];
                matrice[i][j+k] = matrice[i][j];
                matrice[i+k][j+k] = -matrice[i][j];
            }
        }
    }

    //Affichage
    for(i = 0; i < ln; i++){
        for(j = 0; j < ln; j++){
            if(matrice[i][j] == 1)
                printf(" %i  ", matrice[i][j]);
            else
                printf("%i  ", matrice[i][j]);
        } 
        printf("\n");
    }
    
    return matrice;
}

int sequence(int *matrice, int seq, int message[m]){
    matrice[][]
}



int main(){
    int u1, u2;
    //int m1[]=sizeof(int);
    //int m2[]=sizeof(int);

    printf("Donnez un nombre d'utilisateur : ");
    scanf("%d", &n);

    
    int matrice[n][n];
    matrice = hadamard(n);


    printf("Donnez la séquence U1 : ");
    scanf("%i", &u1);
    printf("Donnez le message pour U1 : ");
    scanf("%i", &m1);
    sequence(matrice, u1, m1);

    printf("Donnez la séquence U2 : ");
    scanf("%i", &u2);
    printf("Donnez le message pour U2 : ");
    scanf("%i", &m2);


}