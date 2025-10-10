#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void showHeader();
void showContent(int voters, int candidates, int parties);

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

int choice;
int voters = 120;
int candidates = 10;
int parties = 4;
char * electionStartTime = "8.00 AM";
char * electionEndtTime = "5.00 PM";

int main() {
    system("cls || clear");
    showHeader();
    showContent(voters, candidates, parties);

    printf("\033[1;37mEnter your choice:\033[0m ");
    scanf("%d", &choice);
    printf("\t\t\nPlease Wait....\n");
    system("cls || clear");
switch (choice) {
    case 1:
        #ifdef _WIN32
            system("..\\voter\\voter_login.exe");
        #else
            system("../voter/voter_login");
        #endif
        break;

    case 2:
        #ifdef _WIN32
            system("..\\candidate\\candidate_login.exe");
        #else
            system("../candidate/candidate_login");
        #endif
        break;

    case 3:
        #ifdef _WIN32
            system("..\\party\\party_login.exe");
        #else
            system("../party/party_login");
        #endif
        break;

    case 4:
        #ifdef _WIN32
            system("..\\voter\\voter_registration.exe");
        #else
            system("../voter/voter_registration");
        #endif
        break;

    case 5:
        #ifdef _WIN32
            system("..\\candidate\\candidate_registration.exe");
        #else
            system("../candidate/candidate_registration");
        #endif
        break;

    case 6:
        #ifdef _WIN32
            system("..\\party\\party_registration.exe");
        #else
            system("../party/party_registration");
        #endif
        break;

    case 7:
        #ifdef _WIN32
            system("..\\admin\\admin_login.exe");
        #else
            system("../admin/admin_login");
        #endif
        break;

    case 8:
        #ifdef _WIN32
            system("..\\terms_conditions\\terms_conditions.exe");
        #else
            system("../terms_conditions/terms_conditions");
        #endif
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

void showContent(int voters, int candidates, int parties) {
    printf("║                                  ║                                       ║\n");
    printf("║   \033[1;32mMAIN MENU:\033[0m                     ║  \033[1;33mELECTION NEWS:\033[0m                       ║\n");
    printf("║                                  ║                                       ║\n");
    printf("║     1. Voter Login               ║  Number of Registered Voters   : %d  ║\n", voters);
    printf("║     2. Candidate Login           ║  Number of Registered Candidates: %d  ║\n", candidates);
    printf("║     3. Party Login               ║  Number of Registered Parties  : %d    ║\n", parties);
    printf("║     4. Voter Registration        ║                                       ║\n");
    printf("║     5. Candidate Registration    ╠═══════════════════════════════════════╣\n");
    printf("║     6. Party Registration        ║                                       ║\n");
    printf("║     7. Admin Login               ║  \033[1;34mELECTION Schedule:\033[0m                   ║\n");
    printf("║     8. Terms and Conditions      ║                                       ║\n");
    printf("║     0. Exit                      ║     Start: %s & End: %s     ║\n", electionStartTime, electionEndtTime);
    printf("║                                  ║                                       ║\n");
    printf("╠══════════════════════════════════╩═══════════════════════════════════════╝\n");
    printf("║\n");
    printf("╚══ ");
}

