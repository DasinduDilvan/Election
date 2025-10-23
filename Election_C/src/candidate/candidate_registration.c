#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

struct candidate {
    int Candidate_ID;
    char First_Name[50];
    char Last_Name[50];
    char Username[50];
    char Password[20];
    char NIC[20];
    char Gender[10];
    char Party_Number[10];
} candidatedetails;

void showCandidateHeader();
int getCandidateData();

int main() {
    system("cls || clear");
    showCandidateHeader();

    getCandidateData();

    char confirm_save;
    printf("║\n");
    printf("╠═ Confirm Candidate Registration (y/n): ");
    scanf(" %c", &confirm_save);

    if (confirm_save != 'y' && confirm_save != 'Y') {
        printf("║\n");
        printf("╠═ Registration cancelled.\n");
        return 0;
    } else {
        printf("║\n");
        printf("╠═ Registration confirmed. Status set to PENDING for Admin Approval.\n");

        FILE *file = fopen("../../database/notifications/candidate_notifications.txt", "a");
        if (file == NULL) {
            printf("Error opening file for candidate data!\n");
            return 1;
        }

        fprintf(file, "¥%s¥%s¥%s¥%s¥%s¥%s¥%s\n%d", candidatedetails.First_Name, candidatedetails.Last_Name, candidatedetails.Username, candidatedetails.Password, candidatedetails.NIC, candidatedetails.Gender, candidatedetails.Party_Number, candidatedetails.Candidate_ID);

        fclose(file);

        printf("║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                       %sCandidate Registration saved%s                       ║\n", COLOR, CLRRM);
        printf("║                       Waiting on Administrator approval                  ║\n");
        printf("║                       %sCandidate Registration saved%s                       ║\n", COLOR, CLRRM);
        printf("║                       Waiting on Administrator approval                  ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
    }

    printf("\nPress Enter to return to the main menu...");
    getchar();
    getchar();
    system("..\\main\\main.exe");
    return 0;
}

void showCandidateHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", COLOR, CLRRM);
    printf("║                                                                          ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                          %sCandidate Registration%s                          ║\n", COLOR, CLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");  
    printf("║    Parties you can register from:                                        ║ \n");  //╝
    
    #ifdef _WIN32
        FILE *readParties = fopen("..\\..\\database\\source_data\\party.txt", "r");
    #else
        FILE *readParties = fopen("../../database/source_data/party.txt", "r");
    #endif

    if (!readParties) {printf("Error opening file to read parties!\n");   return;    }

    char line[512];
    const char *delimiter = "¥"; 

    while (fgets(line, sizeof(line), readParties)) {

        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, delimiter);
        int index = 0;

        while (token != NULL) {
            if (index == 0)
                printf("║\t%s : ", token);
            else if (index == 1)
                printf("%-20s                                           ║\n", token);

            token = strtok(NULL, delimiter);
            index++;
        }
    }
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n"); 
    fclose(readParties);
}

int getCandidateData() {
    #ifdef _WIN32
        FILE *file = fopen("..\\..\\database\\notifications\\candidate_notifications.txt", "r");
    #else
        FILE *file = fopen("../../database/notifications/candidate_notifications.txt", "r");
    #endif

    if (file == NULL) {
        printf("Error opening file!\n");
        candidatedetails.Candidate_ID = 1;
    } else {
        char line[512];
        char last_line[512] = "";

        while (fgets(line, sizeof(line), file)) {
            strcpy(last_line, line);
        }
        fclose(file);

        candidatedetails.Candidate_ID = 0;
        for (int i = 0; last_line[i] != '\0'; i++) {
            if (last_line[i] >= '0' && last_line[i] <= '9') {
                candidatedetails.Candidate_ID = candidatedetails.Candidate_ID * 10 + (last_line[i] - '0');
            }
        }
        ++candidatedetails.Candidate_ID;
    }

    printf("║\n");
    printf("╠═ Enter First Name: ");
    scanf("%49s", candidatedetails.First_Name);

    printf("║\n");
    printf("╠═ Enter Last Name: ");
    scanf("%49s", candidatedetails.Last_Name);

    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%49s", candidatedetails.Username);

    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", candidatedetails.Password);

    printf("║\n");
    printf("╠═ Enter NIC: ");
    scanf("%19s", candidatedetails.NIC);

    printf("║\n");
    printf("╠═ Enter Gender (m/f): ");
    scanf("%9s", candidatedetails.Gender);

    printf("║\n");
    printf("╠═ Enter Party Number: ");
    scanf("%9s", candidatedetails.Party_Number);

    return candidatedetails.Candidate_ID;
}