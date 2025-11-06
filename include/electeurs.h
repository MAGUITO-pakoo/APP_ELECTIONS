#ifndef ELECTEUR_H
#define ELECTEUR_H

#define MAX 100

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nom[50];
    char quartier[50];
    int age;
    char nationalite[50];
    int a_vote; // 0 = non, 1 = oui
} Electeur;

typedef struct {
    Electeur aVoter[100];
    int i;// indice du tableau
    Electeur naPasVote[100];
    int j;// indice du tableau
} Votant;

void genererID(int *id);
void enregistrerElecteur();
Votant ontVote(Electeur tab[], int taille);
int aVote(Electeur tab[], int taille, char nom[], char prenom[]);

#endif
