#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
int credentials();
int *count_of_requests();
int numbers[6];
int choice;

void showContent();

int main(){

    system("clear || cls");
    showHeader();
    if (credentials()) {
        printf("\n\t\tLogin Successful!\n");
        sleep(1);
        system("clear || cls");
        showHeader();

        int *requests = count_of_requests();

        showContent();
        printf("\033[1;37mEnter your choice:\033[0m ");
        scanf("%d", &choice);
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
    printf("║\n");
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
    printf("║    1.Party Register Requests       ║    Candidate Requests: %03d          ║\n", numbers[0]);
    printf("║    2.Candidate Register Requests   ║    Party Requests: %03d              ║\n", numbers[1]);
    printf("║    3.Set Election staring time     ║    Approved Candidates: %03d         ║\n", numbers[2]);
    printf("║    4.Set Election Ending time      ║    Approved Parties: %03d            ║\n", numbers[3]);
    printf("║    5.Logout                        ║    Rejected Candidates: %03d         ║\n", numbers[4]);
    printf("║    0.Exit                          ║    Rejected Parties: %03d            ║\n", numbers[5]);
    printf("║                                    ║                                     ║\n");
    printf("╠════════════════════════════════════╩═════════════════════════════════════╝\n");
    printf("║\n");
    printf("╚══ ");
}

int *count_of_requests() {
    FILE *file = fopen("..//..//database//notifications//request_count.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return NULL;
    }
    int i = 0;
    while (i < 6 && fscanf(file, "%d", &numbers[i]) == 1) {
        i++;
    }
    fclose(file);
    return numbers;
}




