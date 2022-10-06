
typedef struct sequence_s sequence;
typedef struct sequence_s {
    int ** matrice;
    int * message;
    int ligneSeq;

} sequence_t ;

sequence_t * sequenceCreer(int seq,int * messageTab);