#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void afficherMatrice(int ** matrice, int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(matrice[i][j] == 1)
                printf(" %i  ", matrice[i][j]);
            else
                printf("%i  ", matrice[i][j]);
        } 
        printf("\n");
    }
}

void freeMatrice(int ** matrice,int x){
    for (int i = 0;i<x;i++){
        free(matrice[i]);
    }
    free(matrice);
}

int ** hadamard(int taille){
    int ** matrice = malloc(taille * sizeof(int*));
    if( matrice == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    for (int i = 0;i<taille;i++){
        matrice[i] = malloc(taille * sizeof(int));
        if( matrice[i] == NULL ){
          fprintf(stderr,"Allocation impossible");
          exit(EXIT_FAILURE);
        }
    }

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

int getTailleMessage(char * message){
    int taille = 0;
    while (message[taille] != '\0'){
        taille++;
    }
    return taille;
}

int * messageToTab(char * message){
    int tailleMessage = getTailleMessage(message);
    int * messageTab = malloc(tailleMessage * sizeof(int));
    if( messageTab == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    for (int i = 0;i<tailleMessage;i++){
        messageTab[i] = (message[i] - '0');
    }  
    return messageTab;
}

int ** sequence(int ** matrice,int tailleMatrice){
    //TODO
    return 0;
}

int main(){
    int seqU1, seqU2, n;
    char * message = malloc(sizeof(char)*100);

    //TODO faire en sorte de demander le nombre d'utilisateur pour créer autant de séquence
    printf("Donnez le nombre d'utilisateur pour hadamard: ");
    scanf("%d", &n);
    //TODO fonction pour max utilisateur pour adapter la taille de la matrice
    int taille = pow(2,n);
    int ** matrice = hadamard(taille);

    printf("Donnez la séquence qu'émet l'utilisateur 1 : ");
    scanf("%i", &seqU1);
    printf("Donnez le message qu'émet l'utilisateur 1 : ");
    scanf("%s", message);
    messageToTab(message);
    //int ** seq1 = sequence(matrice, taille, sequenceU1, messageToTab(message));
    printf("Donnez la séquence U2 : ");
    scanf("%i", &utilisateur2);
    printf("Donnez le message pour U2 : ");
    scanf("%s", message2);
    freeMatrice(matrice,taille);
    return 0;
}