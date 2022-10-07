typedef struct sequence_s sequence;
typedef struct sequence_s {
    int ** matrice;
    int * messageTab;
    int ligneSeq;
    int tailleY;
    int tailleX;
} sequence_t ;

//Créer une séquence et initialise ses variables
sequence_t * sequenceCreer(char * message,int ligneSeq,int sequenceTaille, int hadamardTaille);

//Libère une séquence et ses variables
void freeSequence(sequence_t ** seq);

//Traite une séquence en fonction de la matrice hadamard
void traiterSequence(sequence_t * seq,int ** matrice);

//Affiche une séquence
void afficherSeq(sequence_t * seq);