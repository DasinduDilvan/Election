#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../admin/admin_login.h"
#include "../candidate/candidate_login.h"
#include "../candidate/candidate_registration.h"
#include "../party/party_login.h"
#include "../party/party_registration.h"
#include "../voter/voter_login.h"
#include "../voter/voter_registration.h"

const char *COLORYLO = "\033[1;33m";
const char *MAINCLRRM = "\033[0m";
#define MAX_LINE_RESULT 256
#define MAX_NAME_RESULT 100

int firstFunction();
void main_menu();
int view_results();
int showResultContent();
void showMainHeader();
int userCount(int location);
void showContent();
void terms_conditions();


int choice;
int linecounts[3];
char electionStartTime[12];
char electionEndTime[12];


int main() {
    #ifdef _WIN32
        system("chcp 65001");
    #endif
    system("cls || clear");
    firstFunction();
    return 0;
}

int firstFunction() {
    system("cls || clear");

    FILE *file = fopen("../database/notifications/election_time.txt", "r");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        char line[100];
        int lineCount = 0;
        int check_true = 5;

        while (fgets(line, sizeof(line), file)) {
            lineCount++;
            if (lineCount == 3) {
                line[strcspn(line, "\n")] = '\0';

                if (strcmp(line, "FALSE") == 0){
                    //view_results();
                    check_true = showResultContent();
                    switch (check_true){
                    case 1:
                        admin_login();
                        break;
                    case 2:
                        view_results();
                        break;
                    case 3:
                        terms_conditions();
                        break;
                    case 0:
                        #ifdef _WIN32
                            system("cls");
                        #else
                            system("clear");
                        #endif
                        printf("\n\tThank you for using Election Management System\n");
                        exit(0);
                        break;
                    default:
                        firstFunction();
                        break;
                    }
                }
                else if (strcmp(line, "TRUE") == 0){
                    main_menu();
                }
                else{
                    main_menu();
                }
                break;
            }
        }

        if (lineCount < 3)
            printf("File has less than 3 lines.\n");

    fclose(file);
        sleep(2);
    return 0;
}

void main_menu() {
    system("cls || clear");
    showMainHeader();
    showContent();

    printf("\033[1;37mEnter your choice:\033[0m ");
    scanf("%d", &choice);
    printf("\t\t\nPlease Wait....\n");
    switch (choice) {
    case 1:
        voter_login();
        break;
    case 2:
        candidate_login();
        break;
    case 3:
        party_login();
        break;
    case 4:
        registerVoters();
        break;

    case 5:
        candidate_register();
        break;

    case 6:
        party_register();
        break;

    case 7:
        admin_login();
        break;

    case 8:
        terms_conditions();
        break;

    case 0:
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("\n\t\tThank you for using Election Management System\n");
        exit(0);
        break;

    default:
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("\n\t\tWrong selection\n");
        break;
}

}

void showMainHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", COLORYLO, MAINCLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", COLORYLO, MAINCLRRM);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", COLORYLO, MAINCLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", COLORYLO, MAINCLRRM);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", COLORYLO, MAINCLRRM);
    printf("║                                                                          ║\n");
    
}



void showContent() {

        for(int i=0; i<3; i++){
            linecounts[i] = userCount(i);
        }
        #ifdef _WIN32
        FILE *file = fopen("..\\database\\notifications\\election_time.txt", "r");
        #else
        FILE *file = fopen("../database/notifications/election_time.txt", "r");
        #endif
        if (file == NULL) {
            printf("Error: Could not open time file\n");
        return;
        }
        fgets(electionStartTime,12,file);
        fgets(electionEndTime,12,file);
        fclose(file);
        electionStartTime[strcspn(electionStartTime, "\n")] = '\0';
        electionEndTime[strcspn(electionEndTime, "\n")] = '\0';

    printf("╠══════════════════════════════════╦═══════════════════════════════════════╣\n");
    printf("║                                  ║                                       ║\n");
    printf("║   \033[1;32mMAIN MENU:\033[0m                     ║  \033[1;34mELECTION NEWS:\033[0m                       ║\n");
    printf("║                                  ║                                       ║\n");
    printf("║     1. Voter Login               ║    No of Registered Voters    : %-2d    ║\n", linecounts[0]);
    printf("║     2. Candidate Login           ║    No of Registered Candidates: %-2d    ║\n", linecounts[1]);
    printf("║     3. Party Login               ║    No of Registered Parties   : %-2d    ║\n", linecounts[2]);
    printf("║     4. Voter Registration        ║                                       ║\n");
    printf("║     5. Candidate Registration    ╠═══════════════════════════════════════╣\n");
    printf("║     6. Party Registration        ║                                       ║\n");
    printf("║     7. Admin Login               ║  \033[1;31mELECTION Schedule:\033[0m                   ║\n");
    printf("║     8. Terms and Conditions      ║                                       ║\n");
    printf("║     0. Exit                      ║     Start: %-7s & End: %-7s     ║\n",electionStartTime, electionEndTime);
    printf("║                                  ║                                       ║\n");
    printf("╠══════════════════════════════════╩═══════════════════════════════════════╝\n");
    printf("║\n");
    printf("╚══ ");
}


int showResultContent() {
    system("cls || clear");
    showAdminHeader();
    printf("╠══════════════════════════════════╦═══════════════════════════════════════╣\n");
    printf("║                                  ║                                       ║\n");
    printf("║   \033[1;32mMAIN MENU:\033[0m                     ║  \033[1;34mELECTION NEWS:\033[0m                       ║\n");
    printf("║                                  ║                                       ║\n");
    printf("║     1. Admin Login               ║    Election Ended -                   ║\n");
    printf("║     2. View Results              ║                                       ║\n");
    printf("║     3. Terms and Conditions      ║         - Your able to view results   ║\n");
    printf("║     0. Exit                      ║                                       ║\n");
    printf("║                                  ║                                       ║\n");
    printf("╠══════════════════════════════════╩═══════════════════════════════════════╝\n");
    printf("║\n");
    printf("╚══ ");
    int choice2;
    printf("\033[1;37mEnter your choice:\033[0m ");
    scanf("%d", &choice2);

    switch (choice2)
    {
    case 1:
        admin_login();
        break;
    case 2:
        view_results();
        break;
    case 3:
        terms_conditions();
        break;
    case 4:
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("\n\tThank you for using Election Management System\n");
        exit(0);
        break;
    default:
        break;
    }
    return 0;
}


int userCount(int location){
    char *fileDir; 
    if (location==0){fileDir = "..//database//source_data//voters.txt";}
    else if(location==1){fileDir = "..//database//source_data//candidates.txt";}
    else if(location==2){fileDir = "..//database//source_data//party.txt";}
    else {return 0;}
    
    int number=0;
    char line[1024];
    FILE *readfile = fopen(fileDir, "r");
    if (!readfile) {
        printf("Error opening file! %d\n", location);
        return 0;
    }
    while (fgets(line, sizeof(line), readfile)) {
        number++;
    }   
    fclose(readfile);
    return number;
}

void terms_conditions(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    showMainHeader();
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                          %sTERMS AND CONDITIONS%s                            ║\n", COLORYLO, MAINCLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                          ║\n");
    printf("║  1. Users must provide valid and truthful information during             ║\n");
    printf("║     registration as a voter, candidate, or party.                        ║\n");
    printf("║                                                                          ║\n");
    printf("║  2. Any attempt to fake, alter, or misuse election data may result       ║\n");
    printf("║     in the account being *rejected by the admin*.                        ║\n");
    printf("║                                                                          ║\n");
    printf("║  3. Only authorized administrators have permission to modify or          ║\n");
    printf("║     manage system configurations and election settings.                  ║\n");
    printf("║                                                                          ║\n");
    printf("║  4. Passwords are securely stored and not visible in plain text.         ║\n");
    printf("║     Each user is responsible for maintaining their login credentials.    ║\n");
    printf("║                                                                          ║\n");
    printf("║  5. By using this system, users agree to act responsibly and follow      ║\n");
    printf("║     the rules of fair participation throughout the election process.     ║\n");
    printf("║                                                                          ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n  Press ENTER to return to the menu...");

    getchar(); 
    getchar(); 
    firstFunction();
}

int view_results(){
    system("cls || clear");
    showAdminHeader();
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                          %sElection Results%s                                ║\n", COLORYLO, MAINCLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");

    FILE *fp = fopen("../database/election_result/results.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file '../election_result/results.txt'\n");
        return 1;
    }

    printf("║   Party                     Candidate                  Vote Count        ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");

    char line[MAX_LINE_RESULT];
    while (fgets(line, sizeof(line), fp)) {
        char candidate_id[MAX_NAME_RESULT];
        char party_id[MAX_NAME_RESULT];
        int vote_count;

        // Tokenize result line
        char *token = strtok(line, "<@|@>");
        if (token == NULL) continue;
        strcpy(candidate_id, token);

        token = strtok(NULL, "<@|@>");
        if (token == NULL) continue;
        strcpy(party_id, token);

        token = strtok(NULL, "<@|@>");
        if (token == NULL) continue;
        vote_count = atoi(token);

        // ----- Find party name -----
        FILE *partyFile = fopen("../database/source_data/party.txt", "r");
        if (partyFile == NULL) {
            printf("Error: Cannot open party.txt\n");
            fclose(fp);
            return 1;
        }

        char pLine[MAX_LINE_RESULT];
        char partyName[MAX_NAME_RESULT] = "Unknown";
        while (fgets(pLine, sizeof(pLine), partyFile)) {
            char pid[MAX_NAME_RESULT], pname[MAX_NAME_RESULT];

            char *pTok = strtok(pLine, "<@|@>");
            if (pTok == NULL) continue;
            strcpy(pid, pTok);

            pTok = strtok(NULL, "<@|@>");
            if (pTok == NULL) continue;
            pTok[strcspn(pTok, "\n")] = '\0'; 
            strcpy(pname, pTok);

            if (strcmp(pid, party_id) == 0) {
                strcpy(partyName, pname);
                break;
            }
        }
        fclose(partyFile);

        FILE *candFile = fopen("../database/source_data/candidates.txt", "r");
        if (candFile == NULL) {
            printf("Error: Cannot open candidates.txt\n");
            fclose(fp);
            return 1;
        }

        char cLine[MAX_LINE_RESULT];
        char candidateName[MAX_NAME_RESULT] = "Unknown";
        while (fgets(cLine, sizeof(cLine), candFile)) {
            char cid[MAX_NAME_RESULT], fname[MAX_NAME_RESULT], lname[MAX_NAME_RESULT];

            char *cTok = strtok(cLine, "<@|@>");
            if (cTok == NULL) continue;
            strcpy(cid, cTok);

            cTok = strtok(NULL, "<@|@>");
            if (cTok == NULL) continue;
            strcpy(fname, cTok);

            cTok = strtok(NULL, "<@|@>");
            if (cTok == NULL) continue;
            cTok[strcspn(cTok, "\n")] = '\0';
            strcpy(lname, cTok);

            if (strcmp(cid, candidate_id) == 0) {
                snprintf(candidateName, sizeof(candidateName), "%s %s", fname, lname);
                break;
            }
        }
        fclose(candFile);

        printf("║    %-20s %-30s    %-4d           ║\n", partyName, candidateName, vote_count);
        printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
        
    }

    fclose(fp);

printf("\n  Press ENTER to return to the menu...");
    getchar(); 
    getchar(); 
    firstFunction();
    return 0;

}