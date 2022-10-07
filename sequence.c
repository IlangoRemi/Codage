#include "sequence.h"
#include "message.h"
#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

sequence_t * sequenceCreer(char * message,int ligneSeq,int sequenceTaille, int hadamardTaille){
    sequence_t * seq = malloc(sizeof(sequence_t));
    if( seq == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    seq->messageTab = messageToTab(message,sequenceTaille);
    seq->tailleX = hadamardTaille;
    seq->tailleY = sequenceTaille;
    seq->ligneSeq = ligneSeq;
    seq->matrice = matriceCreer(hadamardTaille,ligneSeq);
    return seq;
}

void freeSequence(sequence_t ** seq){
    freeMatrice((*seq)->matrice,(*seq)->tailleX);
    freeMessageTab((&(*seq)->messageTab));
    free((*seq));
}

void traiterSequence(sequence_t * seq,int ** matrice){
    for(int i=0;i<=seq->tailleY;i++){
        if (seq->messageTab[i] == 0){
            for(int j=0;j<seq->tailleX;j++){
                seq->matrice[i][j] = matrice[i][j] * -1;
            }
        }else{
            for(int j=0;j<seq->tailleX;j++){
                seq->matrice[i][j] = matrice[i][j];
            }
        }
    }
    afficherSeq(seq);
}

void afficherSeq(sequence_t * seq){
    for(int i = 0;i<seq->tailleY;i++){
        for(int j = 0;j<seq->tailleX;j++){
            printf("%i ", seq->matrice[i][j]);
        }
        printf(" | ");
    }
    printf("\n");
}