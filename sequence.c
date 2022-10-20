#include "sequence.h"
#include "message.h"
#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

sequence_t * sequenceCreerDepuisMessage(char * message,int ligneSeq,int sequenceTaille, int hadamardTaille){
    sequence_t * seq = malloc(sizeof(sequence_t));
    if( seq == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    seq->messageTab = messageToTab(message,sequenceTaille);
    seq->tailleX = hadamardTaille;
    seq->tailleY = sequenceTaille;
    seq->ligneSeq = ligneSeq-1;
    seq->matrice = matriceCreer(sequenceTaille,hadamardTaille);
    return seq;
}

void freeSequence(sequence_t ** seq){
    freeMatrice((*seq)->matrice,(*seq)->tailleY);
    freeMessageTab((&(*seq)->messageTab));
    free((*seq));
}

void traiterSequence(sequence_t * seq,int ** matrice){
    for(int i=0;i<seq->tailleY;i++){
        if (seq->messageTab[i] == 0){
            for(int j=0;j<seq->tailleX;j++){
                seq->matrice[i][j] = matrice[seq->ligneSeq][j] * -1;
            }
        }else{
            for(int j=0;j<seq->tailleX;j++){
                seq->matrice[i][j] = matrice[seq->ligneSeq][j];
            }
        }
    }
    afficherSeq(seq);
}

void afficherSeq(sequence_t * seq){
    for(int i = 0;i<seq->tailleY;i++){
        for(int j = 0;j<seq->tailleX;j++){
            printf("%2i ", seq->matrice[i][j]);
        }
        printf(" | ");
    }
    printf("\n");
}

sequence_t * sequenceCreerDepuisSequence(sequence_t * codageFinal,int * ligneHadamard,int tailleDesMessages){
    sequence_t * seq = malloc(sizeof(sequence_t));
    if( seq == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    seq->tailleX = codageFinal->tailleX;
    seq->tailleY = tailleDesMessages;
    seq->matrice = matriceCreer(seq->tailleY,seq->tailleX);
    seq->messageTab = malloc(seq->tailleY * sizeof(int));
    for(int i=0;i<seq->tailleY;i++){
        seq->messageTab[i] = 0;
        for(int j=0;j<seq->tailleX;j++){
            seq->matrice[i][j] = (codageFinal->matrice[i][j])*(ligneHadamard[j]);
        }
    }
    for(int i=0;i<seq->tailleY;i++){
        for(int j=0;j<seq->tailleX;j++){
            seq->messageTab[i] += seq->matrice[i][j];
        }
    }
    return seq;
}

void calculEtalement(sequence_t * codageFinal,int * ligneHadamard,int tailleDesMessages){
    sequence_t * codageUtilisateur = sequenceCreerDepuisSequence(codageFinal,ligneHadamard,tailleDesMessages);
    printf("\nAddition des 3 parties du message : ");
    for(int i=0;i<tailleDesMessages;i++){
        printf("%2i ",codageUtilisateur->messageTab[i]);
    }
    printf("\nMessage reçus : ");
    for(int i=0;i<tailleDesMessages;i++){
        printf("%i",codageUtilisateur->messageTab[i] > 0 ? 1 : 0);
    }
    freeSequence(&codageUtilisateur);
}