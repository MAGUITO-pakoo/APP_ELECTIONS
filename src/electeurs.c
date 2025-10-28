#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/electeurs.h"


// Fonction pour générer un ID automatique du type e001, e002...
void genererID(int *id) { 
    FILE *f = fopen("electeurs.csv", "r");
    int compteur = 0;
    char ligne[200];

    if (f != NULL) {
        while (fgets(ligne, sizeof(ligne), f)) {
            compteur++; // chaque ligne = un électeur
        }
        fclose(f);
    }

    *id = compteur + 1;
}

// Fonction pour enregistrer un électeur
void enregistrerElecteur() {
    Electeur e;

    printf("\n==== ENREGISTREMENT D'UN ELECTEUR ====\n");

    genererID(&e.id);
    printf("Nom : ");
    fgets(e.nom, sizeof(e.nom), stdin);
    e.nom[strcspn(e.nom, "\n")] = 0; 

    printf("Quartier : ");
    fgets(e.quartier, sizeof(e.quartier), stdin);
    e.quartier[strcspn(e.quartier, "\n")] = 0;

    printf("Age : ");
    scanf("%d", &e.age);
    getchar(); 

    if (e.age < 20) { 
        printf("Desole, un electeur doit avoir au moins 20 ans.\n");
        return;
    }

    printf("Nationalite : ");
    fgets(e.nationalite, sizeof(e.nationalite), stdin);
    e.nationalite[strcspn(e.nationalite, "\n")] = 0;

    for (int i = 0; e.nationalite[i]; i++)
        e.nationalite[i] = toupper(e.nationalite[i]);

    if (strcmp(e.nationalite, "CAMEROUNAISE") != 0) {
        printf("Desole, seuls les Camerounais peuvent voter.\n");
        return;
    }

    e.a_vote = 0;

    FILE *f = fopen("electeurs.csv", "a");
    if (!f) {
        printf("Erreur lors de l’ouverture du fichier electeurs.csv\n");
        return;
    }

    fprintf(f, "%s;%s;%s;%d;%s;%d\n" , e.id, e.nom, e.quartier, e.age, e.nationalite, e.a_vote);

    fclose(f);

    printf("Electeur enregistre avec succes !\n");
}


int main(){
enregistrerElecteur();

 return 0;
}