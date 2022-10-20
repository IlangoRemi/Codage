#include "sequence.h"

typedef struct listSeq_s listSeq;
typedef struct listSeq_s {
    sequence_t * (*listeSeq);
    int nbSeq;
} listSeq_t;

//Créer une liste de séquence et initialise ses variables
listSeq_t * listSequenceCreer(int nbSeq);

//Libère une liste de séquence et ses variables
void freeListSeq(listSeq_t ** liste);

//Ajoute une séquence à la liste de séquence
void ajouterSeq(listSeq_t * liste, sequence_t * Seq);

//Affiche toutes les séquences
void afficherListSeq(listSeq_t * liste);

//Calcul le codage final de toutes les séquences
sequence_t * calculCodage(listSeq_t * liste);