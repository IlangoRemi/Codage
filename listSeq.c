#include "listSeq.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long int liste_cpt = 0 ;

listSeq_t * listSequenceCreer(int nbSeq){
    listSeq_t * liste = malloc(sizeof(listSeq_t));
    if( liste == NULL ){
     fprintf(stderr,"Allocation impossible");
     exit(EXIT_FAILURE);
    }
    liste->nbSeq = nbSeq;
    liste->listeSeq = malloc(nbSeq * sizeof(sequence_t));
    liste_cpt++;
    return liste;
}

void freeListSeq(listSeq_t ** liste){
    for (int i = 0;i<(*liste)->nbSeq;i++){
        //cassé fonctionne pas...
        //freeSequence(&((*liste)->listeSeq[i]));
    }
    //peut pas faire car le "for" au dessus fonctionne pas
    //free((*liste)->listeSeq);
    free((*liste));
}

void ajouterSeq(listSeq_t * liste, sequence_t * seq){
    liste->listeSeq[liste_cpt] = (*seq);
}

void afficherListSeq(listSeq_t * liste){
    for(int i = 0;i<liste_cpt;i++){
        afficherSeq(&(liste->listeSeq[i]));
    }
}