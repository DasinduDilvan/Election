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
void party_requests();
void candidate_requests();
void set_election_start_time();
void set_election_end_time();

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

        switch (choice)    {
        case 1:
            party_requests();
            break;
        
        case 2:
            candidate_requests();
            break;
        
        case 3:
            set_election_start_time();
            break;

        case 4:
            set_election_end_time();
            break;
        
        case 5:
            system("..\\main\\main.exe");
            break;

        case 0:
            printf("\t\t\nThank you for using Election Management System\n");
            exit(0);
            break;
        } 
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

//------------------------------------------------------------------------------------------

void party_requests() {
    system("clear || cls");
    printf("\n%sParty Registration Requests%s\n", COLOR, CLRRM);
    FILE *file = fopen("..//..//database//notifications//party_notifications.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("\nPress Enter to return to the admin menu...");
    getchar(); // To consume the newline character left by previous input
    getchar(); // Wait for user to press Enter
    system("clear || cls");
    showHeader();
    showContent();
}

void candidate_requests() {
    system("clear || cls");
    printf("\n%sCandidate Registration Requests%s\n", COLOR, CLRRM);
    FILE *file = fopen("..//..//database//notifications//candidate_notifications.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("\nPress Enter to return to the admin menu...");
    getchar(); // To consume the newline character left by previous input
    getchar(); // Wait for user to press Enter
    system("clear || cls");
    showHeader();
    showContent();
}

void set_election_start_time() {
    char start_time[20];
    printf("\n%sSet Election Starting Time%s\n", COLOR, CLRRM);
    printf("Enter Election Starting Time (e.g., 8:00 AM): ");
    scanf("%s", start_time);
    FILE *file = fopen("..//..//database//notifications//election_time.txt", "r+");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    char end_time[20];
    fscanf(file, "%s", end_time); // Read the existing end time
    rewind(file); // Move file pointer to the beginning
    fprintf(file, "%s\n%s\n", start_time, end_time); // Write new start time and existing end time
    fclose(file);
    printf("Election starting time set to %s\n", start_time);
    sleep(2);
    system("clear || cls");
    main();
}

void set_election_end_time() {
    char end_time[20];
    printf("\n%sSet Election Ending Time%s\n", COLOR, CLRRM);
    printf("Enter Election Ending Time (e.g., 5:00 PM): ");
    scanf("%s", end_time);
    FILE *file = fopen("..//..//database//notifications//election_time.txt", "r+");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    char start_time[20];
    fscanf(file, "%s", start_time); // Read the existing start time
    rewind(file); // Move file pointer to the beginning
    fprintf(file, "%s\n%s\n", start_time, end_time); // Write existing start time and new end time
    fclose(file);
    printf("Election ending time set to %s\n", end_time);
    sleep(2);
    system("clear || cls");
    main();
}



