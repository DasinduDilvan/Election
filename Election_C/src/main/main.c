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

void main_menu();
void showMainHeader();
int userCount(int location);
void showContent();
void terms_conditions();

int choice;
int linecounts[3];
char electionStartTime[12];
char electionEndTime[12];


int main() {
        main_menu();
        sleep(2);
    return 0;
}

void main_menu() {
    #ifdef _WIN32
        system("chcp 65001");
    #endif

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
    main_menu();
}

