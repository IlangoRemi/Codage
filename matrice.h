//Affiche les matrices
void afficherMatrice(int ** matrice, int tailleX, int tailleY);

//Libère l'espace mémoire des matrice
void freeMatrice(int ** matrice,int tailleX);

//Creer une matrice et aloue la mémoire pour elle
int ** matriceCreer(int tailleX, int tailleY);

//recupère la ligne d'une matrice
int * recupererLigneMatrice(int ** matrice,int ligne,int tailleY);

//Affiche la ligne d'une matrice
void afficherLigneMatrice(int * ligneMatrice,int tailleY);