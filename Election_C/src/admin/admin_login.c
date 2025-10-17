#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

const char *COLOR = "\033[1;33m";
const char *COLORG = "\033[1;32m";
const char *COLORR = "\033[1;31m";
const char *CLRRM = "\033[0m";

void showHeader();
int credentials();
int *count_of_requests();
int numbers[6];
int choice;

int noOfCandidateRequestLines();
int noOfPartyRequestLines();
int showCandidateFirstLine();
int reWriteCandidateRequestFile(int x);
void controlPanel();
void showContent();
void party_requests();
void candidate_requests();
void set_election_start_time();
void set_election_end_time();

int main(){
    system(CLEAR_CMD);
    showHeader();
    if (credentials()) {
        printf("\n\t\tLogin Successful!\n");
        sleep(1);
        system(CLEAR_CMD);
        showHeader();

        int *requests = count_of_requests();

        showContent();

        controlPanel();
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
    printf("╚═ Enter Admin Password: ");
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
    printf("║    1.Party Register Requests       ║    Candidate Requests: %03d          ║\n", numbers[0]);
    printf("║    2.Candidate Register Requests   ║    Party Requests: %03d              ║\n", numbers[1]);
    printf("║    3.Set Election staring time     ║    Approved Candidates: %03d         ║\n", numbers[2]);
    printf("║    4.Set Election Ending time      ║    Approved Parties: %03d            ║\n", numbers[3]);
    printf("║    5.Logout                        ║    Rejected Candidates: %03d         ║\n", numbers[4]);
    printf("║    0.Exit                          ║    Rejected Parties: %03d            ║\n", numbers[5]);
    printf("║                                    ║                                     ║\n");
    printf("╠════════════════════════════════════╩═════════════════════════════════════╝\n");
    printf("║\n");
    printf("╠══ ");
}

void controlPanel(){    
    printf("\033[1;37mEnter your choice:\033[0m ");
    scanf("%d", &choice);

    switch (choice){
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

void party_requests() {
    system(CLEAR_CMD);
    printf("\n║\n╠═ %sParty Registration Requests%s\n", COLOR, CLRRM);
    printf("║\n");
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
    getchar();
    getchar(); 
    system(CLEAR_CMD);
    showHeader();
    showContent();
    controlPanel();
}

void candidate_requests() {
    system(CLEAR_CMD);
    printf("║\n╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                     %sCandidate Register Requets%s                           ║\n", COLOR, CLRRM);
    printf("╠═══════════════════════╦══════════════════════════════════════════════════╣\n");
    printf("║  1.%sAccept Request%s     ║                                                  ║\n", COLORG, CLRRM);
    printf("║  2.%sReject Request%s     ║                                                  ║\n", COLORR, CLRRM);
    printf("╠═══════════════════════╩══════════════════════════════════════════════════╝\n");
    printf("║\n");

    int countOfCandidateRequestLines = noOfCandidateRequestLines();
    int countOfPartyRequestLines = noOfPartyRequestLines();
    //printf("║  Total Candidate Requests: %d\n", countOfCandidateRequestLines);
    //printf("║  Total Voter Requests: %d\n", countOfPartyRequestLines);
    showCandidateFirstLine();
    reWriteCandidateRequestFile(countOfCandidateRequestLines);

        

    printf("║\n");
    printf("╠═ Enter Decision (1/2): ");
    int decision;
    scanf("%d", &decision);

    //fclose(readfile);
    if (decision == 1) {
        printf("║\n");
        printf("╚═ Request Accepted!\n");

    } else if (decision == 2) {
        printf("║\n");
        printf("╚═ Request Rejected!\n");
    } else {
        printf("║\n");
        printf("╚═ Invalid choice!\n");
        sleep(2);
        system(CLEAR_CMD);
        showHeader();
        showContent();
        printf("\n");
        candidate_requests();
    }


    printf("\nPress Enter to return to the admin menu...");
    getchar();
    getchar(); 
    system(CLEAR_CMD);
    showHeader();
    showContent();
    controlPanel();
}


int noOfCandidateRequestLines(){
    int number=0;
    char line[1024];
    FILE *readCandidate = fopen("..//..//database//notifications//candidate_notifications.txt", "r");
    if (!readCandidate) {
        printf("Error opening file! candidate_notifications.txt\n");
        return 0;
    }
    while (fgets(line, sizeof(line), readCandidate)) {
        number++;
    }
    fclose(readCandidate);
    return number-1;

    //FILE *requestCount = fopen("..//..//database//notifications//request_count.txt", "r+");
    //fprintf(requestCount, "%d\n%d\n", count[0], count[1]);
    //fclose(requestCount);
}

int noOfPartyRequestLines(){
    int number=0;
    char line[1024];
    FILE *readParty = fopen("..//..//database//notifications//party_notifications.txt", "r");
    if (!readParty) {
        printf("Error opening file! Party_notifications.txt\n");
        return 0;
    }
    while (fgets(line, sizeof(line), readParty)) {
        number++;
    }
    fclose(readParty);

    return number-1;
}

int showCandidateFirstLine(){
    FILE *readfile = fopen("..//..//database//notifications//candidate_notifications.txt", "r");
        if (!readfile) {
            printf("Error opening file!\n");
            return 0;
        }
        
        char buffer[1024];   
        char line[50][50];      
        int i = 0;
        char *dataName[9]={"Candidate ID","Candidate First Name","Candidate Last Name","No","Party Name","Candidate NIC","Candidate Gender","Date of Birth","ElectionArea"};

        if (fgets(buffer, sizeof(buffer), readfile)) {
            buffer[strcspn(buffer, "\n")] = 0; 

            char *token = strtok(buffer, "#@!@#");
            while (token != NULL && i < 50) {
                strcpy(line[i], token);  
                i++;
                token = strtok(NULL, "#@!@#");
            }
            int j=0;
            while(j<i){
                if(j==3 || j==4){
                    j++;
                    continue;
                }
                printf("║ \t%-20s : %s\n",dataName[j],line[j]);
                j++;
            }
        }

        fclose(readfile);
}

int reWriteCandidateRequestFile(int x){
    FILE *readfile = fopen("..//..//database//notifications//candidate_notifications.txt", "r");
        if (!readfile) {
            printf("Error opening file!\n");
            return 0;
        }
        
        int i = 1;
        char line[x][50];      

        
        while (fgets(line[i], sizeof(line[i]), readfile)) {
            if (i==0){
                i++;

                continue;
            }
                printf("%s\n",line[i]);
            }

        
        fclose(readfile);

        FILE *writefile = fopen("..//..//database//notifications//candidate_notifications.txt", "w");
        if (!writefile) {
            printf("Error opening file for writing!\n");
            return 0;
        }

        fclose(writefile);
}



void set_election_start_time() {
    char start_time[20];
    printf("\n\n╔═ %sSet Election Starting Time%s\n", COLOR, CLRRM);
    printf("║\n");
    printf("╠═ Enter Starting Time (Ex: 8:00AM): ");
    scanf("%19s", start_time);
    FILE *file = fopen("..//..//database//notifications//election_time.txt", "r+");
    if (!file) {
        printf("\nError opening file!\n");
        return;
    }
    char end_time[20];
    fscanf(file, "%s", end_time); 
    rewind(file); 
    fprintf(file, "%s\n%s\n", start_time, end_time); 
    fclose(file);
    printf("║\n");
    printf("╚═ Election starting time set to %s\n", start_time);
    sleep(3);
    system(CLEAR_CMD);
    showHeader();
    showContent();
    controlPanel();
}

void set_election_end_time() {
    char end_time[20];
    printf("\n%s\n╔═ Set Election Ending Time%s\n", COLOR, CLRRM);
    printf("║\n");
    printf("╚═ Enter Ending Time (Ex: 5:00PM): ");
    scanf("%19s", end_time);
    FILE *file = fopen("..//..//database//notifications//election_time.txt", "r+");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    char start_time[20];
    fscanf(file, "%s", start_time);
    rewind(file); 
    fprintf(file, "%s\n%s\n", start_time, end_time); 
    fclose(file);
    printf("║\n");
    printf("╚═ Election ending time set to %s\n", end_time);
    sleep(3);
    system(CLEAR_CMD);
    showHeader();
    showContent();
    controlPanel();
}
