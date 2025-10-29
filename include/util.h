#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Codes de couleur ANSI
#define RESET   "\x1b[0m"
#define GRAS    "\x1b[1m"
#define BLEU    "\x1b[34m"
#define VERT    "\x1b[32m"
#define JAUNE   "\x1b[33m"
#define ROUGE   "\x1b[31m"
#define CYAN    "\x1b[36m"

void clearScreen ();
void pauseScreen();
void loadCandidat();
void loadElecteur();
void checkCandidat();
int menu();

#define MAX_TEXT_LENGTH 50
#define MAX_LINE_LENGTH 256
#define CANDIDATS_FILE "database/candidats.csv"
#define ELECTEURS_FILE "database/electeurs.csv"
#define DELIMITER ";" // Utilisation de ; comme séparateur
#define MAX_CANDIDATS_LENGTH 20
#define MAX_ELECTEURS_LENGTH 100

// Structure Candidat
typedef struct{
    int id;
    char nom[MAX_TEXT_LENGTH];
    char prenom[MAX_TEXT_LENGTH];
    char parti[MAX_TEXT_LENGTH];
    int age;
    int caution;
    int casier; // 0 pour non et 1 pour oui
    char nationalite[MAX_TEXT_LENGTH];
    int candidatureValide; // 0 pour non et 1 pour oui
}candidat;

// structure electeur
typedef struct{
    int id;
    char nom[MAX_TEXT_LENGTH];
    char prenom[MAX_TEXT_LENGTH];
    int age;
    char regionDeResidence[MAX_TEXT_LENGTH];
}electeur;




#endif