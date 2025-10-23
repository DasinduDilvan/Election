#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *COLORVR = "\033[1;33m";
const char *CLRRMVR = "\033[0m";

struct voterReg {
    char firstname[20];
    char lastname[20];
    char username[20];
    char password[20];
    char NIC[20];
    char gender[10];
    char dob[15];
    char area[30];
    int voterID;
};

void voter_register();
void showVoterRegHeader();
void getVoterDetails(struct voterReg voter);
int make_voter_ID();
void saveVoterToFile(struct voterReg voter);
void messageSuccess();
void messageCanceled();

void voter_register(){
    system("clear || cls");
    showVoterRegHeader();

    struct voterReg voter;
    
    getVoterDetails(voter);
    
    char confirm_save;
    printf("║\n");
    printf("╠═ Confirm Registration (y/n): ");
    scanf(" %c", &confirm_save);

    if (confirm_save == 'y' || confirm_save == 'Y') {
        voter.voterID = make_voter_ID();
        
        printf("║\n");
        printf("╠═ Registration confirmed.\n");
        
        saveVoterToFile(voter);
        messageSuccess();
    }
    else {
        printf("║\n");
        printf("╠═ Registration cancelled.\n");
        messageCanceled();
    }
    
    printf("Press Enter to return to the main menu...");
    getchar();
    getchar();
    voter_register();
}

void showVoterRegHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", COLORVR, CLRRMVR);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", COLORVR, CLRRMVR);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", COLORVR, CLRRMVR);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", COLORVR, CLRRMVR);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", COLORVR, CLRRMVR);
    printf("║                                                                          ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                            Voter Registration                            ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
}

void getVoterDetails(struct voterReg voter) {
    printf("║\n");
    printf("╠═ Enter First Name: ");
    scanf("%19s", voter.firstname);
    
    printf("║\n");
    printf("╠═ Enter Last Name: ");
    scanf("%19s", voter.lastname);
    
    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%19s", voter.username);
    
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", voter.password);
    
    printf("║\n");
    printf("╠═ Enter NIC: ");
    scanf("%19s", voter.NIC);
    
    printf("║\n");
    printf("╠═ Enter Gender (m/f): ");
    scanf("%9s", voter.gender);
    
    printf("║\n");
    printf("╠═ Enter Date of Birth (DD/MM/YYYY): ");
    scanf("%14s", voter.dob);
    
    printf("║\n");
    printf("╠═ Enter Area: ");
    scanf("%29s", voter.area);
}

int make_voter_ID() {
    #ifdef _WIN32
        FILE *file = fopen("..\\database\\source_data\\voters.txt", "r");
    #else
        FILE *file = fopen("../database/source_data/voters.txt", "r");
    #endif

    if (file == NULL) {
        return 1; // First voter
    }

    char line[512];
    char last_line[512] = "";

    while (fgets(line, sizeof(line), file)) {
        strcpy(last_line, line);
    }

    fclose(file);

    int voter_ID = 0;
    for (int i = 0; last_line[i] != '\0'; i++) {
        if (last_line[i] >= '0' && last_line[i] <= '9') {
            voter_ID = voter_ID * 10 + (last_line[i] - '0');
        }
    }

    return voter_ID + 1;
}

void saveVoterToFile(struct voterReg voter) {
    #ifdef _WIN32
        FILE *file = fopen("..\\database\\source_data\\voters.txt", "a");
    #else
        FILE *file = fopen("../database/source_data/voters.txt", "a");
    #endif

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%d¥%s¥%s¥%s¥%s¥%s¥%s¥%s¥%s\n", voter.voterID, voter.firstname, voter.lastname, voter.username, voter.password, voter.NIC, voter.gender, voter.dob, voter.area);
    
    fclose(file);
}

void messageSuccess() {
    printf("║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        %sRegistration Successful!%s                          ║\n", COLORVR, CLRRMVR);
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
}

void messageCanceled() {
    printf("║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         %sRegistration Canceled!%s                           ║\n", COLORVR, CLRRMVR);
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
}