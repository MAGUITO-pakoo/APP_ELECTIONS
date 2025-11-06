#ifndef CANDIDATS_H
#define CANDIDATS_H
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int jour, mois, annee;
} Date;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char parti[50];
    char photo[100];
    double caution;
} Candidats;

typedef struct {
    int nbVote[100];
    int i; // indice du tableau
    Candidat candidat[100];
    int j;// indice du tableau
    float pourcent[100];
    int k;
}ResultatVote;

// Prototypes des fonctions liées aux candidats
void annoncerCandidats();
ResultatVote compteVote(Electeur tabE[], int tailleE, Candidat tabC[], int tailleC);

#endif
