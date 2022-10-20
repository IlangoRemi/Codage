#include "listSeq.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long int liste_cpt = 0 ;

listSeq_t * listSequenceCreer(int nbSeq){
    listSeq_t * listeSeq = malloc(sizeof(listSeq_t));
    if( listeSeq == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    listeSeq->nbSeq = nbSeq;
    listeSeq->listeSeq = malloc(nbSeq * sizeof(sequence_t));
    for (int i=0;i<nbSeq;i++){
        listeSeq->listeSeq[i] = malloc(sizeof(sequence_t));
        if( listeSeq->listeSeq[i] == NULL ){
          fprintf(stderr,"Allocation impossible");
          exit(EXIT_FAILURE);
        }
    }
    return listeSeq;
}

void freeListSeq(listSeq_t ** liste){
    for (int i=0;i<(*liste)->nbSeq;i++){
        freeSequence(&((*liste)->listeSeq[i]));
    }
    free((*liste)->listeSeq);
    free((*liste));
}

void ajouterSeq(listSeq_t * liste, sequence_t * seq){
    liste->listeSeq[liste_cpt] = seq;
    liste_cpt++;
}

void afficherListSeq(listSeq_t * liste){
    printf("\nVoici toutes les séquence émis par les utilisateurs : \n");
    for(int i = 0;i<liste->nbSeq;i++){
        afficherSeq(liste->listeSeq[i]);
    }
}

sequence_t * calculCodage(listSeq_t * liste){
    sequence_t * codage = sequenceCreerDepuisMessage("",(liste->listeSeq[0]->ligneSeq+1),liste->listeSeq[0]->tailleY,liste->listeSeq[0]->tailleX);
    for(int k=0;k<liste->nbSeq;k++)
        for(int i=0;i<codage->tailleY;i++)
            for(int j=0;j<codage->tailleX;j++){
                codage->matrice[i][j] += liste->listeSeq[k]->matrice[i][j];
            }
    return codage;
}