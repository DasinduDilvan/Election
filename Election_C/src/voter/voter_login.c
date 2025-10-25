#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../main/main.h"

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

const char *COLORVL = "\033[1;33m";
const char *CLRRMVL = "\033[0m";

typedef struct {
    char firstName[50];
    char lastName[50];
    char username[20];
} VoterInfo;

typedef struct {
    char id[20];
    char name[100];
    char partyID[20];
} Candidate_VL;

typedef struct {
    char id[20];
    char name[100];
} Party_VL;

void voter_login();
void showVoterLogHeader();
void showContentofVL(VoterInfo *voter);
char *username();
char *password();
VoterInfo *voterauthenticate(char *username, char *password);
void viewPartiesAndCandidates();
void castVote(VoterInfo *voter);
void showElectionTime();
void displayMenu(VoterInfo *voter);

void voter_login() {
    system(CLEAR_CMD);
    showVoterLogHeader();
    char *user_name = username();
    char *pass_word = password();

    VoterInfo *voterInfo = voterauthenticate(user_name, pass_word);
    if(voterInfo != NULL) {
        printf("\n\t\tLogin Successful!\n");
        sleep(1);
        displayMenu(voterInfo);
        free(voterInfo);
    }
    else {
        printf("\n\t\tLogin Failed! Invalid username or password.\n");
        sleep(2);
        main_menu();
    }
}

void displayMenu(VoterInfo *voter) {
    int choice;
    do {
        system(CLEAR_CMD);
        showVoterLogHeader();
        printf("║     \033[1;32mLogged in as: Voter\033[0m                Welcome   %-10s %-10s   ║\n", voter->firstName, voter->lastName);
        showContentofVL(voter);
        
        scanf("%d", &choice);
        getchar(); // consume newline
        
        switch(choice) {
            case 1:
                viewPartiesAndCandidates();
                printf("\n\nPress Enter to continue...");
                getchar();
                break;
            case 2:
                castVote(voter);
                break;
            case 3:
                printf("\n\t\tLogging out...\n");
                sleep(1);
                return;
            case 4:
                printf("\n\t\tExiting...\n");
                sleep(1);
                exit(0);
            default:
                printf("\n\t\tInvalid choice! Please try again.\n");
                sleep(1);
        }
    } while(choice != 3 && choice != 4);
}

void showVoterLogHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", COLORVL, CLRRMVL);
    printf("║                                                                          ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                               %sVoter Login%s                                ║\n", COLORVL, CLRRMVL);
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
}

void showContentofVL(VoterInfo *voter) {

    char startTime[100] = "Not Set";
    char endTime[100] = "Not Set";
    
    #ifdef _WIN32
        FILE *fp = fopen("..\\database\\notifications\\election_time.txt", "r");
    #else
        FILE *fp = fopen("../database/notifications/election_time.txt", "r");
    #endif
    
    if(fp) {
        if(fgets(startTime, sizeof(startTime), fp)) {
            startTime[strcspn(startTime, "\n")] = '\0';
        }
        if(fgets(endTime, sizeof(endTime), fp)) {
            endTime[strcspn(endTime, "\n")] = '\0';
        }
        fclose(fp);
    }
    
    printf("╠════════════════════════════════════╦═════════════════════════════════════╣\n");
    printf("║                                    ║                                     ║\n");
    printf("║    1. Candidates and Parties       ║  \033[1;35mElection Schedule:\033[0m                 ║\n");
    printf("║    2. Cast Vote                    ║                                     ║\n");
    printf("║    3. Logout                       ║      Start: %-23s ║\n", startTime);
    printf("║    4. Exit                         ║      End:   %-23s ║\n", endTime);
    printf("║                                    ║                                     ║\n");
    printf("╠════════════════════════════════════╩═════════════════════════════════════╝\n");
    printf("║\n");
    printf("╠══ Enter your choice: ");
}

char *username() {
    static char username[20];
    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%19s", username);
    return username;
}

char *password() {
    static char password[20];
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", password);
    return password;
}

VoterInfo *voterauthenticate(char *username, char *password) {
    #ifdef _WIN32
        FILE *fp = fopen("..\\database\\source_data\\voters.txt", "r");
    #else
        FILE *fp = fopen("../database/source_data/voters.txt", "r");
    #endif
    
    if (!fp) {
        printf("Error: Could not open voters.txt\n");
        return NULL;
    }

    char line[512];
    const char *DELIM = "<@|@>";  
    VoterInfo *voter = NULL;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';  

        char *parts[10];
        int partCount = 0;
        char *token = strtok(line, DELIM);
        while (token != NULL && partCount < 10) {
            parts[partCount++] = token;
            token = strtok(NULL, DELIM);
        }

        if (partCount > 4) {
            if (strcmp(username, parts[3]) == 0 && strcmp(password, parts[4]) == 0) {
                voter = (VoterInfo *)malloc(sizeof(VoterInfo));
                if (!voter) {
                    fclose(fp);
                    return NULL;
                }

                strcpy(voter->firstName, parts[1]);
                strcpy(voter->lastName, parts[2]);
                strcpy(voter->username, parts[3]);

                fclose(fp);
                return voter;
            }
        }
    }

    fclose(fp);
    return NULL;  
}


void viewPartiesAndCandidates() {
    system(CLEAR_CMD);
    printf("\n╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                     Parties and Candidates                               ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n\n");

    Party_VL parties[50];
    int partyCount = 0;

    #ifdef _WIN32
        FILE *fp = fopen("..\\database\\source_data\\party.txt", "r");
    #else
        FILE *fp = fopen("../database/source_data/party.txt", "r");
    #endif

    if (fp) {
        char line[200];
        while (fgets(line, sizeof(line), fp) && partyCount < 50) {
            line[strcspn(line, "\n")] = '\0';
            if (strlen(line) == 0) continue; 

            char *token = strtok(line, "<@|@>");
            int idx = 0;

            while (token != NULL) {
                if (idx == 0)
                    strcpy(parties[partyCount].id, token);
                else if (idx == 1)
                    strcpy(parties[partyCount].name, token);

                token = strtok(NULL, "<@|@>");
                idx++;
            }
            partyCount++;
        }
        fclose(fp);
    }

    #ifdef _WIN32
        FILE *fc = fopen("..\\database\\source_data\\candidates.txt", "r");
    #else
        FILE *fc = fopen("../database/source_data/candidates.txt", "r");
    #endif

    if (fc) {
        char line[400];

        for (int i = 0; i < partyCount; i++) {
            printf("    %s%s (%s)%s\n", COLORVL, parties[i].name, parties[i].id, CLRRMVL);

            rewind(fc);
            int candidateFound = 0;

            while (fgets(line, sizeof(line), fc)) {
                line[strcspn(line, "\n")] = '\0';
                if (strlen(line) == 0) continue;

                char *parts[10];
                int count = 0;
                char *token = strtok(line, "<@|@>");
                while (token != NULL && count < 10) {
                    parts[count++] = token;
                    token = strtok(NULL, "<@|@>");
                }

                if (count >= 8) {
                    char *candID = parts[0];
                    char *firstName = parts[1];
                    char *lastName = parts[2];
                    char *candPartyID = parts[7];

                    if (strcmp(candPartyID, parties[i].id) == 0) {
                        if (!candidateFound) candidateFound = 1;
                        printf("         ├─ %s %s (%s) \n", firstName, lastName, candID);
                    }
                }
            }
            

            if (!candidateFound) {
                printf("      └─ (No candidates registered)\n");
            }

            printf("\n");
        }
        fclose(fc);
        printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    }
}



// maduka me thiyenne mn kiyapu function eka meka balapanko ------------------------


void castVote(VoterInfo *voter) {
    system(CLEAR_CMD);
    printf("\n╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                            Cast Your Vote                                ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n\n");

    char inputID[20];
    printf("Enter Voter ID to vote (or 0 to cancel): ");
    scanf("%19s", inputID);
    getchar();

    if(strcmp(inputID, "0") == 0) {
        printf("\n\tVote cancelled.\n");
        return;
    }


    #ifdef _WIN32
        FILE *fc = fopen("..\\database\\source_data\\voters.txt", "r");
    #else
        FILE *fc = fopen("../database/source_data/voters.txt", "r");
    #endif

    if(!fc) {
        printf("\nError: Cannot open voters file.\n");
        return;
    }

    char line[400];
    int found = 0;
    char voterID[20], fname[50], lname[50], username[50], password[50], nic[30], gender[10], partyID[20];

 
    while(fgets(line, sizeof(line), fc)) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, "<@|@>");
        if(!token) continue;
        strcpy(voterID, token);

        if(strcmp(voterID, inputID) == 0) {
            strcpy(fname, strtok(NULL, "<@|@>"));
            strcpy(lname, strtok(NULL, "<@|@>"));
            strcpy(username, strtok(NULL, "<@|@>"));
            strcpy(password, strtok(NULL, "<@|@>"));
            strcpy(nic, strtok(NULL, "<@|@>"));
            strcpy(gender, strtok(NULL, "<@|@>"));
            strcpy(partyID, strtok(NULL, "<@|@>"));
            found = 1;
            break;
        }
    }

    fclose(fc);

    if(!found) {
        printf("\nInvalid Voter ID!\n");
        return;
    }

    #ifdef _WIN32
        FILE *fr = fopen("..\\database\\election_result\\results.txt", "r");
    #else
        FILE *fr = fopen("../database/election_result/results.txt", "r");
    #endif

    FILE *temp = tmpfile();
    int updated = 0;

    if(fr) {
        char buffer[200];
        while(fgets(buffer, sizeof(buffer), fr)) {
            buffer[strcspn(buffer, "\n")] = '\0';

            char existingCand[20], existingParty[20];
            int votes;

            if(sscanf(buffer, "%[^¥]¥%[^¥]¥%d", existingCand, existingParty, &votes) == 3) {
                if(strcmp(existingCand, voterID) == 0) {
                    votes++;
                    fprintf(temp, "%s¥%s¥%d\n", existingCand, existingParty, votes);
                    updated = 1;
                } else {
                    fprintf(temp, "%s\n", buffer);
                }
            }
        }
        fclose(fr);
    }

    if(!updated) {
        fprintf(temp, "%s¥%s¥1\n", voterID, partyID);
    }

    #ifdef _WIN32
        FILE *fw = fopen("..\\database\\election_result\\results.txt", "w");
    #else
        FILE *fw = fopen("../database/election_result/results.txt", "w");
    #endif

    if(fw) {
        rewind(temp);
        char copy[200];
        while(fgets(copy, sizeof(copy), temp)) {
            fprintf(fw, "%s", copy);
        }
        fclose(fw);
    }

    fclose(temp);
    printf("\n✓ Vote successfully cast for Candidate ID: %s (Party ID: %s)\n", voterID, partyID);
}