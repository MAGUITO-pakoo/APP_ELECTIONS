#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/electeurs.h"


/* 
void enregistrerElecteur() {
    FILE *f = fopen("electeurs.csv", "a");
    if (!f) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    char nom[50], quartier[50], nationalite[50];
    int age;
    char id[10];

    printf("ID : ");
    scanf("%s", id);
    printf("Nom : ");
    scanf("%s", nom);
    printf("Quartier : ");
    scanf("%s", quartier);
    printf("Âge : ");
    scanf("%d", &age);
    printf("Nationalité : ");
    scanf("%s", nationalite);

    // Vérification des conditions d’éligibilité
    if (age >= 20 && strcmp(nationalite, "CAMEROUNAISE") == 0) {
        fprintf(f, "%s,%s,%s,%d,%s\n", id, nom, quartier, age, nationalite);
        printf("✅ Électeur enregistré avec succès !\n");
    } else {
        printf("❌ Électeur non éligible (moins de 20 ans ou non Camerounais).\n");
    }

    fclose(f);
}
 */

// Fonction pour générer un ID automatique du type e001, e002...
void genererID(char *id) { 
    FILE *f = fopen("electeurs.csv", "r");
    int compteur = 0;
    char ligne[200];

    if (f != NULL) {
        while (fgets(ligne, sizeof(ligne), f)) {
            compteur++; // chaque ligne = un électeur
        }
        fclose(f);
    }

    sprintf(id, "e%d", compteur + 1);
}

// Fonction pour enregistrer un électeur
void enregistrerElecteur() {
    Electeur e;

    printf("\n==== ENREGISTREMENT D'UN ELECTEUR ====\n");

    genererID(e.id);
    printf("Nom : ");
    fgets(e.nom, sizeof(e.nom), stdin);
    e.nom[strcspn(e.nom, "\n")] = 0; 

    printf("Quartier : ");
    fgets(e.quartier, sizeof(e.quartier), stdin);
    e.quartier[strcspn(e.quartier, "\n")] = 0;

    printf("Âge : ");
    scanf("%d", &e.age);
    getchar(); 

    if (e.age < 20) { 
        printf("Désolé, un électeur doit avoir au moins 20 ans.\n");
        return;
    }

    printf("Nationalité : ");
    fgets(e.nationalite, sizeof(e.nationalite), stdin);
    e.nationalite[strcspn(e.nationalite, "\n")] = 0;

    for (int i = 0; e.nationalite[i]; i++)
        e.nationalite[i] = toupper(e.nationalite[i]);

    if (strcmp(e.nationalite, "CAMEROUNAISE") != 0) {
        printf("Désolé, seuls les Camerounais peuvent voter.\n");
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

    printf("Électeur enregistré avec succès !\n");
}

/* int main() {
    enregistrerElecteur();
    return 0;
} */