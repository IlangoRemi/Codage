#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "hadamard.h"
#include "message.h"
#include "listSeq.h"

//Lance le programme
int main(){
    int seqU = 0;
    int nbUti = 0;
    int tailleDesMessages = 0;
    char * message = malloc(sizeof(char)*100);
    // vrai main
    printf("Donnez le nombre d'utilisateur pour hadamard: ");
    scanf("%d", &nbUti);
    int tailleHadamard = getTailleHadamard(nbUti);

    /* Test calcul de désétalement depuis le cours
    nbUti = 2;
    int tailleHadamard = 8;
    */

    printf("\n----------------------------- ");
    printf("\n| Voici la matrice hadamard | ");
    printf("\n----------------------------- \n");
    int ** matriceHadamard = hadamard(tailleHadamard);
    listSeq_t * tabSeq = listSequenceCreer(nbUti);
    for(int i=0;i<nbUti;i++){
        printf("\nDonnez le numéro de la séquence qu'émet l'utilisateur n°%i : ",(i+1));
        scanf("%i", &seqU);
        while (seqU>tailleHadamard || seqU==0){
            printf("\nVeuillez donner un numéro de séquence entre 0 et %i pour l'utilisateur n°%i : ",tailleHadamard,(i+1));
            scanf("%i", &seqU);
        }
        printf("Donnez le message qu'émet l'utilisateur n°%i : ",(i+1));
        scanf("%s", message);
        if (tailleDesMessages == 0){
            tailleDesMessages = getTailleMessage(message);
        }
        while (tailleDesMessages != getTailleMessage(message)){
            printf("Veuillez donnez un message de taille %i pour l'utilisateur n°%i : ",tailleDesMessages,i);
            scanf("%s", message);
        }
        sequence_t * seq = sequenceCreerDepuisMessage(message,seqU,tailleDesMessages,tailleHadamard);
        traiterSequence(seq,matriceHadamard);
        ajouterSeq(tabSeq,seq);
    }
    afficherListSeq(tabSeq);
    sequence_t * codageFinal = calculCodage(tabSeq);
    printf("\nVoici le signal émis lorsque tous les utilisateurs émettent en même temps : \n");
    afficherSeq(codageFinal);
    printf("\n-------------------------");
    printf("\n| Début du désétalement |");
    printf("\n-------------------------\n");
    for(int i=0;i<nbUti;i++){
        printf("\nDésetalement de l'utilisateur n°%i : \n",(i+1));
        printf("Séquence hadamar de l'utilisateur n°%i : \n",(i+1));
        int * ligneHadamard = recupererLigneMatrice(matriceHadamard,tabSeq->listeSeq[i]->ligneSeq,tabSeq->listeSeq[i]->tailleX);
        afficherLigneMatrice(ligneHadamard,tabSeq->listeSeq[i]->tailleX);
        calculEtalement(codageFinal,ligneHadamard,tailleDesMessages);
        freeMessageTab(&ligneHadamard);
        printf("\n");
    }
    freeSequence(&codageFinal);
    freeMatrice(matriceHadamard,tailleHadamard);
    freeListSeq(&tabSeq);
    freeMessage(&message);
    return 0;
}