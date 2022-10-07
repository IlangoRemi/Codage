#include "message.h"
#include <stdio.h>
#include <stdlib.h>

int * messageToTab(char * message,int tailleMessage){
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

int getTailleMessage(char * message){
    int taille = 0;
    while (message[taille] != '\0'){
        taille++;
    }
    return taille;
}

void freeMessage(char ** message){
    free((*message));
}

void freeMessageTab(int ** message){
    free((*message));
}