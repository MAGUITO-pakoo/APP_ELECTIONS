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

    printf(GRAS CYAN "=== APPLICATION ELECTION ===\n" RESET);
    printf(GRAS "\nBienvenue dans notre simulateur electoral\nVeiller faire votre choix\n\n");
    printf("1) Afficher les candidats\n");
    printf("2) Ajouter un Candidat\n");
    printf("3) Verifier les candidatures \n");
    printf("4) Ajouter un electeur\n");
    printf("5) Liste d'electeurs \n");
    printf("6) Lancer le vote\n");
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
        else printf(ROUGE "Erreur lors du chargement de candidats\n" RESET);
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
            countElecteur++;
        }
       else printf(ROUGE "Erreur lors du chargement des electeurs\n" RESET);
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
            printf(ROUGE "Candidature invalide pour: %s  " RESET, candidats[i].nom);
            if(candidats[i].caution != 30000000) printf( JAUNE   " la Caution est differente de 30 000 000frs. " RESET);
            if(strcmp(candidats[i].parti, "") == 0) printf( JAUNE   " parti invalide. " RESET);
            if(candidats[i].casier == 1) printf( JAUNE   " ce candidats a deja eu des contencieux avec la justice " RESET);
            if(candidats[i].age < 35) printf( JAUNE   " age minimum requis est 35 ans. " RESET);
            printf("\n");
        }
        else{
            candidats[i].candidatureValide = 1;
            printf(VERT "Candidature valide pour: %s\n" RESET, candidats[i].nom);
        }
    }
}

// Affiche les partis triés par nombre de votes (ordre croissant)
// votes: tableau de nombres de votes par candidat (indice correspond au candidat dans la table `candidats`)
// n: nombre d'éléments dans le tableau votes (si <=0, la fonction utilise countCandidat chargé par loadCandidat)
void afficherPartisParVotesCroissant(int votes[], int n)
{
    if (votes == NULL) {
        printf(ROUGE "Aucun tableau de votes fourni.\n" RESET);
        return;
    }

    int nC = (n > 0) ? n : countCandidat;
    if (nC <= 0) {
        printf(ROUGE "Aucun candidat charge.\n" RESET);
        return;
    }

    // Table temporaire pour agréger les votes par parti
    typedef struct {
        char parti[MAX_TEXT_LENGTH];
        int votes;
    } PartyCount;

    PartyCount parties[MAX_CANDIDATS_LENGTH];
    int partyCount = 0;

    for (int i = 0; i < nC && i < countCandidat; i++) {
        // Ignorer candidats sans parti
        if (strcmp(candidats[i].parti, "") == 0) continue;

        // chercher si le parti est déjà présent
        int found = -1;
        for (int j = 0; j < partyCount; j++) {
            if (strcmp(parties[j].parti, candidats[i].parti) == 0) {
                found = j;
                break;
            }
        }

        if (found >= 0) {
            parties[found].votes += votes[i];
        } else {
            // ajouter nouveau parti
            strncpy(parties[partyCount].parti, candidats[i].parti, MAX_TEXT_LENGTH - 1);
            parties[partyCount].parti[MAX_TEXT_LENGTH - 1] = '\0';
            parties[partyCount].votes = votes[i];
            partyCount++;
            if (partyCount >= MAX_CANDIDATS_LENGTH) break; // sécurité
        }
    }

    // Trier par votes (ordre croissant) - tri par selection
    for (int i = 0; i < partyCount - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < partyCount; j++) {
            if (parties[j].votes < parties[minIdx].votes ||
               (parties[j].votes == parties[minIdx].votes && strcmp(parties[j].parti, parties[minIdx].parti) < 0)) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            PartyCount tmp = parties[i];
            parties[i] = parties[minIdx];
            parties[minIdx] = tmp;
        }
    }

    // Affichage
    printf(GRAS CYAN "\nPartis triés par nombre de votes (croissant):\n" RESET);
    if (partyCount == 0) {
        printf(JAUNE "Aucun parti trouve (ou votes nuls).\n" RESET);
        return;
    }
    for (int i = 0; i < partyCount; i++) {
        printf(VERT "%2d) " RESET "%s : " GRAS "%d" RESET " votes\n", i + 1, parties[i].parti, parties[i].votes);
    }
}