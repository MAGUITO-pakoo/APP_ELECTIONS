#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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


// Affiche la liste des partis triés par nombre de votes (ordre croissant)
// votes: tableau de nombres de votes par candidat (indice correspond au candidat dans la table `candidats`)
// n: nombre d'éléments dans le tableau votes (si n<=0, la fonction utilise countCandidat chargé par loadCandidat)
void afficherPartisParVotesCroissant(int votes[], int n);

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
    int casier; // 0 pour non et 1 pour ouis
    char nationalite[MAX_TEXT_LENGTH];
    int candidatureValide; // 0 pour non et 1 pour oui
}candidat;

// structure electeur
typedef struct{
    int id;
    char nom[MAX_TEXT_LENGTH];
    char prenom[MAX_TEXT_LENGTH];
    char regionDeResidence[MAX_TEXT_LENGTH];
    int age;
    char nationalite[MAX_TEXT_LENGTH];
    int choix;
}electeur;

typedef struct {
    int nbVote[100];
    int i; // indice du tableau
    candidat candidat[100];
    int j;// indice du tableau
    float pourcent[100];
    int k;
}ResultatVote;

typedef struct {
    electeur aVoter[100];
    int i;// indice du tableau
    electeur naPasVote[100];
    int j;// indice du tableau
} Votant;

ResultatVote compteVote(electeur tabE[], int tailleE, candidat tabC[], int tailleC);
Votant ontVote(electeur tab[], int taille);
int aVote(electeur tab[], int taille, char nom[], char prenom[]);
void simulerVote(electeur tab[], int taille, int nbCandidats);
void passerAuVote(electeur tab[], int taille, int nbCandidats);

extern electeur electeurs[MAX_ELECTEURS_LENGTH];
extern candidat candidats[MAX_CANDIDATS_LENGTH];
extern int countElecteur;
extern int countCandidat;





#endif