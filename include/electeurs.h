#ifndef ELECTEUR_H
#define ELECTEUR_H

#define MAX 100

#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char regionDeResidence[50];
    int age;
    char nationalite[50];
    int choix; // =0 si n'a pas voté!
} Electeur;


void genererID(int *id);
void enregistrerElecteur();

#endif