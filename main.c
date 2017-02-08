#include <stdio.h>
#include <stdlib.h>
#define TAILLE 10
#define NBATEAU 3
#define TAILLEFLOTTE 2
// BUT : Cree un jeux de battaile navale
// ENTRER :
// SORTIE :
typedef struct Cellule{

    int lin,col;

}Cellule;

typedef struct Bateau{

    Cellule Cellule;

}Bateau;

typedef struct Flotte{

    Bateau Tabbateau[NBATEAU];

}Flotte;

enum BOOL{

    True,False,
};


void placement(int Joueur,Flotte Tabflotte[]);
enum BOOL verif(int Joueur, Flotte Tabflotte[], int col, int lin);



int main()
// BUT : Faire jouer la partie
// ENTRER :
// SORTIE :
{
    Flotte Tabflotte[TAILLEFLOTTE];

    placement(1,Tabflotte);


    return 0;
}

void placement(int Joueur,Flotte Tabflotte[]){
// BUT : Choisir 2 cellules pour placer un bateau
// ENTRER : Une valeurs joueurs et notre Tableau de Flotte
// SORTIE : 2 valeurs, une colone et une ligne
    int col =0;
    int lin = 0;
    int i = 1;

    for(i=1;i<=NBATEAU;i++){
        while(verif(Joueur, Tabflotte, col, lin) == True){
            while((col<=0) || (col>TAILLE)){
                printf("Joueur%i entrez la colonne du bateau num %i :     ( Entre 1 et %i ) \n",Joueur,i,TAILLE);
                scanf("%i",&col);
                fflush(stdin);
            }

            while((lin<=0) || (lin>TAILLE)){
                printf("Joueur%i entrez la ligne du bateau num %i :     ( Entre 1 et %i ) \n",Joueur,i,TAILLE);
                scanf("%i",&lin);
                fflush(stdin);
            }
        }
    }
}

enum BOOL verif(int Joueur, Flotte Tabflotte[], int col, int lin){
// BUT : Verifier la disponibilité de 2 cellules
// ENTRER : La valeur Joueurs, notre tableau flotte, la colonne et la ligne
// SORTIE : Une valeur True ou False
    int i = 1;
    int j = 0;

    for(i=1;i<=NBATEAU;i++){
        if((Tabflotte[Joueur].Tabbateau[i].Cellule.col == col) && (Tabflotte[Joueur].Tabbateau[i].Cellule.lin == lin)){
            break;
        }else j++;
    }
    if(j == NBATEAU){
        return True;
    }else return False;
};
