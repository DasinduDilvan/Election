#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    system("clear");
    showHeader();
    showContent(voters, candidates, parties);

    do {
        printf("\033[1;37mEnter your choice:\033[0m ");
        scanf("%d", &choice);
        printf("You selcted %d\n", choice);
        break;
    } while (choice != 0);

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

