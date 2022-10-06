#include "sequence.h"

typedef struct listSeq_s listSeq;
typedef struct listSeq_s {
    sequence_t * listeSeq;
    int nbSeq;
} listSeq_t;

listSeq * listSequenceCreer(int nbSeq);