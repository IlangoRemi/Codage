#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "hadamard.h"
#include "message.h"
#include "listSeq.h"

//Lance le programme
int main(){
    int seqU, nbUti;
    char * message = malloc(sizeof(char)*100);
    printf("Donnez le nombre d'utilisateur pour hadamard: ");
    scanf("%d", &nbUti);
    int tailleHadamard = getTailleHadamard(nbUti);
    int ** matriceHadamard = hadamard(tailleHadamard);
    listSeq_t * tabSeq = listSequenceCreer(nbUti);
    for(int i=0;i<nbUti;i++){
        printf("Donnez la séquence qu'émet l'utilisateur %i : ",(i+1));
        scanf("%i", &seqU);
        printf("Donnez le message qu'émet l'utilisateur %i : ",(i+1));
        scanf("%s", message);
        int tailleMessage = getTailleMessage(message);
        sequence_t * seq = sequenceCreer(message,seqU,tailleMessage,tailleHadamard);
        traiterSequence(seq,matriceHadamard);
        ajouterSeq(tabSeq,seq);
    }
    afficherListSeq(tabSeq);
    freeMatrice(matriceHadamard,tailleHadamard);
    freeListSeq(&(tabSeq));
    return 0;
}