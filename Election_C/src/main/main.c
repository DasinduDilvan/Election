#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void showHeader();
void showContent();

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

int choice;
char * electionStartTime;
char * electionEndtTime; 

int main() {
    system("cls || clear");
    showHeader();
    showContent();

    printf("\033[1;37mEnter your choice:\033[0m ");
    scanf("%d", &choice);
    printf("\t\t\nPlease Wait....\n");
    switch (choice)    {
    case 1:
        system("..\\voter\\voter_login.exe");
        break;
    
    case 2:
        system("..\\candidate\\candidate_login.exe");
        break;
    
    case 3:
        system("..\\party\\party_login.exe");
        break;
    
    case 4:
        system("..\\voter\\voter_registration.exe");
        break;
    
    case 5:
        system("..\\candidate\\candidate_registration.exe");
        break;
    
    case 6:
        system("..\\party\\party_registration.exe");
        break;

    case 7:
        system("..\\admin\\admin_login.exe");
        break;

    case 8:
        system("..\\terms_conditions\\terms_conditions.exe");
        break;

    case 0:
        printf("\t\t\nThank you for using Election Management System\n");
        system("cls || clear");
        printf("\t\t\nThank you for using Election Management System\n");
        exit(0);
        break;
    
    default:
        system("cls || clear");
        printf("\t\t\nWrong selection\n");
        break;
    }
return 0;
}

void showHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", COLOR, CLRRM);
    printf("║                                                                          ║\n");
    printf("╠══════════════════════════════════╦═══════════════════════════════════════╣\n");
}

void showContent() {

    FILE *file = fopen("..//..//database//notifications//election_time.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    char line[2][100];
    while (fgets(line[0], sizeof(line), file)) {
        electionStartTime = line[0];
        electionStartTime[strcspn(electionStartTime, "\n")] = '\0';
        fgets(line[1], sizeof(line), file);
        electionEndtTime = line[1];
        electionEndtTime[strcspn(electionEndtTime, "\n")] = '\0';
    }  
    fclose(file);

char *voters;
char *candidates;
char *parties;

    FILE *file2 = fopen("..//..//database//notifications//request_count.txt", "r");
    if (!file2) {
        printf("Error opening file!\n");
        return;
    }
    char line2[8][100];
    while (fgets(line2[6], sizeof(line2) - 6, file2)) {
        voters = line2[6];
        voters[strcspn(voters, "\n")] = '\0';
        fgets(line2[4], sizeof(line2) - 6, file2);
        candidates = line2[4];
        candidates[strcspn(candidates, "\n")] = '\0';
        fgets(line2[5], sizeof(line2) - 6, file2);
        parties = line2[5];      
        parties[strcspn(parties, "\n")] = '\0';
    }

    printf("║                                  ║                                       ║\n");
    printf("║   \033[1;32mMAIN MENU:\033[0m                     ║  \033[1;33mELECTION NEWS:\033[0m                       ║\n");
    printf("║                                  ║                                       ║\n");
    printf("║     1. Voter Login               ║  Number of Registered Voters   : %-3s  ║\n", voters);
    printf("║     2. Candidate Login           ║  Number of Registered Candidates:%-2s   ║\n", candidates);
    printf("║     3. Party Login               ║  Number of Registered Parties  : %-2s   ║\n", parties);
    printf("║     4. Voter Registration        ║                                       ║\n");
    printf("║     5. Candidate Registration    ╠═══════════════════════════════════════╣\n");
    printf("║     6. Party Registration        ║                                       ║\n");
    printf("║     7. Admin Login               ║  \033[1;34mELECTION Schedule:\033[0m                   ║\n");
    printf("║     8. Terms and Conditions      ║                                       ║\n");
    printf("║     0. Exit                      ║     Start: %-7s & End: %-7s     ║\n", electionStartTime, electionEndtTime);
    printf("║                                  ║                                       ║\n");
    printf("╠══════════════════════════════════╩═══════════════════════════════════════╝\n");
    printf("║\n");
    printf("╚══ ");
}

