#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
int credentials();
void showContent();

int candidate_requests = 8;
int party_requests = 5;
int approved_candidates = 10;
int approved_parties = 4;
int rejected_candidates = 2;
int rejected_parties = 1;


int main(){

    system("clear || cls");
    showHeader();
    if (credentials()) {
        printf("\n\t\tLogin Successful!\n");
        sleep(1);
        system("clear || cls");
        showHeader();
        showContent();
    } 
    else {
        printf("\n\t\tInvalid Credentials! Enterd ...\n");
        sleep(1);
        system("..\\main\\main.exe");
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
    
    
    
}

int credentials() {
    char username[50];
    char password[50];

    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                               %sAdmin Login%s                                ║\n", COLOR, CLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
    printf("║\n");
    printf("╠═ Enter Admin Username: ");
    scanf("%s", username);
    printf("║\n");
    printf("╠═ Enter Admin Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
        return 1;
    } 
    else {
        return 0; 
    }
}

void showContent() {
    printf("╠════════════════════════════════════╦═════════════════════════════════════╣\n");
    printf("║                                    ║                                     ║\n");
    printf("║  \033[1;32mLogged in as: Admin\033[0m               ║  \033[1;35mDashboard:\033[0m                         ║\n");
    printf("║                                    ║                                     ║\n");
    printf("║    1.Party Register Requests       ║    Candidate Requests: %03d          ║\n", candidate_requests);
    printf("║    2.Candidate Register Requests   ║    Party Requests: %03d              ║\n", party_requests);
    printf("║    3.Set Election staring time     ║    Approved Candidates: %03d         ║\n", approved_candidates);
    printf("║    4.Set Election Ending time      ║    Approved Parties: %03d            ║\n", approved_parties);
    printf("║    5.Logout                        ║    Rejected Candidates: %03d         ║\n", rejected_candidates);
    printf("║    0.Exit                          ║    Rejected Parties: %03d            ║\n", rejected_parties);
    printf("║                                    ║                                     ║\n");
    printf("╚════════════════════════════════════╩═════════════════════════════════════╝\n");
}