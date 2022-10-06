#include "message.h"
#include <stdio.h>
#include <stdlib.h>

//Transforme en tableau d'entier une chaine de string
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

//Récupère la taille d'un message string
int getTailleMessage(char * message){
    int taille = 0;
    while (message[taille] != '\0'){
        taille++;
    }
    return taille;
}