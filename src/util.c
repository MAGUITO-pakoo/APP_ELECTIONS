
#include "..\include\util.h"

void clearScreen () {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    printf ("\nAppuyer sur entrer pour continuer...");
    getchar();

}

int menu(){
    // int run = 1;
    int choix;

    clearScreen();
    printf(GRAS CYAN "===APPLICATION ELECTION===\n" RESET);
    printf(GRAS "\nBienvenue dans notre simulateur electoral\nVeiller faire votre choix\n\n");
    printf("1) Afficher les candidats\n");
    printf("2) Ajouter un Candidat\n");
    printf("3) Liste d'electeur\n");
    printf("4) Ajouter un electeur\n");
    printf("5) Lancer le vote\n");
    printf("6) Verifier les candidatures\n");
    printf("99) Quitter\n" VERT">> " RESET);
    scanf("%d", &choix);

    return choix;
}

candidat candidats[MAX_CANDIDATS_LENGTH];
electeur electeurs[MAX_ELECTEURS_LENGTH];

int countCandidat;
int countElecteur;

void loadCandidat()
{
    FILE *file = fopen(CANDIDATS_FILE, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier candidats.csv");
        return;
    }

    char line[MAX_LINE_LENGTH];
    
    // Lire la ligne d'en-tête (pour l'ignorer)
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fclose(file);
        return;
    }

    // Lire les lignes de données suivantes
    countCandidat = 0;
    while(fgets(line, MAX_LINE_LENGTH, file) != NULL && countCandidat < MAX_CANDIDATS_LENGTH)
    {
        if (sscanf(line, "%d%*c%[^;]%*c%[^;]%*c%[^;]%*c%d%*c%d%*c%d%*c%[^;]", 
                   &candidats[countCandidat].id,
                   candidats[countCandidat].nom,
                   candidats[countCandidat].prenom,
                   candidats[countCandidat].parti,
                   &candidats[countCandidat].age,
                   &candidats[countCandidat].caution,
                   &candidats[countCandidat].casier,
                   candidats[countCandidat].nationalite) >= 0) 
        {
            // Les champs ont été lus avec succès
            countCandidat++;
        }
        // Sinon, la ligne est ignorée ou une erreur est loguée
    }

    fclose(file);
    printf(CYAN "%d candidats charges.\n" RESET, countCandidat);

}

void loadElecteur()
{
    FILE *file = fopen(ELECTEURS_FILE, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier electeur.csv");
        return;
    }

    char line[MAX_LINE_LENGTH];
    
    // Lire la ligne d'en-tête (pour l'ignorer)
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fclose(file);
        return;
    }

    // Lire les lignes de données suivantes
    countElecteur = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && countElecteur < MAX_ELECTEURS_LENGTH) {

        if (sscanf(line, "%d%*c%[^;]%*c%[^;]%*c%d%*c%[^;]", 
                   &electeurs[countElecteur].id,
                   electeurs[countElecteur].nom,
                   electeurs[countElecteur].prenom,
                   &electeurs[countElecteur].age,
                   electeurs[countElecteur].regionDeResidence) == 5) 
        {
            // Les 4 champs ont été lus avec succès
            countElecteur++;
        }
        // Sinon, la ligne est ignorée ou une erreur est loguée
    }

    fclose(file);
    printf(CYAN "%d electeurs charges.\n" RESET, countElecteur);
}

void checkCandidat()
{
    for (int i = 0; i < countCandidat; i++)
    {
        if(candidats[i].caution != 30000000  ||
            strcmp(candidats[i].parti, "") == 0 ||
            candidats[i].casier == 1 ||
            candidats[i].age < 35
            //candidats[i].nationalite != "camerounaise"
            )
        {
            candidats[i].candidatureValide = 0;
            printf(ROUGE "Candidature invalide pour: %s\n" RESET, candidats[i].nom);
        }
        else{
            candidats[i].candidatureValide = 1;
            printf(VERT "Candidature valide pour: %s\n" RESET, candidats[i].nom);
        }
    }
}