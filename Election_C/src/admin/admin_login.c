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
int counts[6];
int choice;

int countOfRequests(int location);

int reWriteCandidateRequestFile(int x);

void controlPanel();
int showContent();
int party_requests();
int candidate_requests();
void set_election_start_time();
void set_election_end_time();

int main(){
    #ifdef _WIN32
        system("chcp 65001");
    #endif  
    system(CLEAR_CMD);
    showHeader();
    if (credentials()) {
        printf("\n\t\tLogin Successful!\n");
        sleep(1);
        system(CLEAR_CMD);
        showHeader();

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

int showContent() {
    for(int i=0; i<6; i++){
        counts[i] = countOfRequests(i);
        //printf("%d:%d\n", i,counts[i]);
    }

    printf("╠════════════════════════════════════╦═════════════════════════════════════╣\n");
    printf("║                                    ║                                     ║\n");
    printf("║  \033[1;32mLogged in as: Admin\033[0m               ║  \033[1;35mDashboard:\033[0m                         ║\n");
    printf("║                                    ║                                     ║\n");
    printf("║    1.Party Register Requests       ║    Candidate Requests: %03d          ║\n", counts[0]);
    printf("║    2.Candidate Register Requests   ║    Party Requests: %03d              ║\n", counts[1]);
    printf("║    3.Set Election staring time     ║    Approved Candidates: %03d         ║\n", counts[2]);
    printf("║    4.Set Election Ending time      ║    Approved Parties: %03d            ║\n", counts[3]);
    printf("║    5.Logout                        ║    Rejected Candidates: %03d         ║\n", counts[4]);
    printf("║    0.Exit                          ║    Rejected Parties: %03d            ║\n", counts[5]);
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


int party_requests() {
    system(CLEAR_CMD);
    printf("\n║\n╠═ %sParty Registration Requests%s\n", COLOR, CLRRM);
    printf("║\n");
    FILE *file = fopen("..//..//database//notifications//party_notifications.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return 0;
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

int candidate_requests() {
    system(CLEAR_CMD);
    printf("║\n╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                     %sCandidate Register Requets%s                           ║\n", COLOR, CLRRM);
    printf("╠═══════════════════════╦══════════════════════════════════════════════════╣\n");
    printf("║  1.%sAccept Request%s     ║                                                  ║\n", COLORG, CLRRM);
    printf("║  2.%sReject Request%s     ║                                                  ║\n", COLORR, CLRRM);
    printf("╠═══════════════════════╩══════════════════════════════════════════════════╝\n");
    printf("║\n");

    FILE *readfile = fopen("..//..//database//notifications//candidate_notifications.txt", "r");
        if (!readfile) {
            printf("Error opening file! CN to read\n");
            return 0;
        }
        
        int i = 0;
        char line[counts[0]-1][200];  
        char *firstline;
        char *token;
        char *parts[10];
        char otherlines[counts[0]-1][200];
        char *dataName[9] = {"Candidate ID","Candidate First Name","Candidate Last Name","No","Party Name","Candidate NIC","Candidate Gender","Date of Birth","Election Area"};
        while ( i <= counts[0]-1) {
            fgets(line[i], sizeof(line[i]), readfile);
            if(i==0){
                firstline = line[i];
                token = strtok(firstline, "¥");
                while (token && i < 9) {
                    parts[i] = token;
                    i++;
                    token = strtok(NULL, "¥");
                }            
                for (int j = 0; j < i; j++) {
                    printf("║\t%-20s : %s\n", dataName[j], parts[j]);
                }
                i++;
                continue;
            }
            strcpy(otherlines[i], line[i]);
            
            printf("%s", otherlines[i]);
            i++;
            if(i<=counts[0]-1){break;}
        }

        fclose(readfile);

        FILE *rewritefile = fopen("..//..//database//notifications//candidate_notifications.txt", "w");
            if (!rewritefile) {
                printf("Error opening file! CN to read\n");
                return 0;
            }
            for(int j=1; j<=counts[0]; j++){
                fprintf(rewritefile, "%s", otherlines[j]);
            }
        fclose(rewritefile);
        fclose(readfile);

        

    printf("║\n");
    printf("╠═ Enter Decision (1/2): ");
    int decision;
    scanf("%d", &decision);

    printf("check one");

    if (decision == 1) {
        FILE *writefile = fopen("..//..//database//source_data//candidates.txt", "a");
        if (!writefile) {
            printf("Error opening file for writing!\n");
            return 0;
        }
        fprintf(writefile, "%s\n", firstline[0]);

        printf("check two");
        
        
        fclose(writefile);
        printf("║\n");      
        printf("╚═ Request Accepted!\n");

        printf("check three");

    } else if (decision == 2) {
        FILE *rejectfile = fopen("..//..//database//notifications//rejected_candidates.txt", "a");
        if (!rejectfile) {
            printf("Error opening file for writing!\n");
            return 0;
        }
        fprintf(rejectfile, "%s\n", firstline);
        
        
        fclose(rejectfile);
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

    printf("\n\nPress Enter to return to the admin menu...");
    getchar();
    getchar(); 
    system(CLEAR_CMD);
    showHeader();
    showContent();
    controlPanel();
}


int countOfRequests(int location){
    char *fileDir; 
    if (location==0){fileDir = "..//..//database//notifications//candidate_notifications.txt";}
    else if(location==1){fileDir = "..//..//database//notifications//party_notifications.txt";}
    else if(location==2){fileDir = "..//..//database//source_data//candidates.txt";}
    else if(location==3){fileDir = "..//..//database//source_data//party.txt";}
    else if(location==4){fileDir = "..//..//database//notifications//rejected_candidates.txt";}
    else if(location==5){fileDir = "..//..//database//notifications//rejected_parties.txt";}
    else {return 0;}
    
    int number=0;
    char line[1024];
    FILE *readCandidate = fopen(fileDir, "r");
    if (!readCandidate) {
        printf("Error opening file! %s\n", location);
        return 0;
    }
    while (fgets(line, sizeof(line), readCandidate)) {
        number++;
    }
    fclose(readCandidate);
    return number;
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
