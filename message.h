//Transforme en tableau d'entier une chaine de string
int * messageToTab(char * message,int tailleMessage);

//Récupère la taille d'un message string
int getTailleMessage(char * message);

//Libère l'espace mémoire d'un message char
void freeMessage(char ** message);

//Libère l'espace mémoire d'un messageTab int
void freeMessageTab(int ** message);