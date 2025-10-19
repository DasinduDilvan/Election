#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
    #define PATH_SEPARATOR "\\"
    #define MAIN_PROGRAM "..\\main\\main.exe"
#else
    #define CLEAR_CMD "clear"
    #define PATH_SEPARATOR "/"
    #define MAIN_PROGRAM "../main/main"
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
void showContent();
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
        system(MAIN_PROGRAM);
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
    for(int i=0; i<6; i++){
        counts[i] = countOfRequests(i);
        //printf("%d:%d\n", i,counts[i]);
    }

    printf("╠════════════════════════════════════╦═════════════════════════════════════╣\n");
    printf("║                                    ║                                     ║\n");
    printf("║  \033[1;32mLogged in as: Admin\033[0m               ║  \033[1;35mDashboard:\033[0m                         ║\n");
    printf("║                                    ║                                     ║\n");
    printf("║    1.Party Register Requests       ║    Candidate Requests: \033[1;33m%03d\033[0m          ║\n", counts[0]);
    printf("║    2.Candidate Register Requests   ║    Approved Candidates: %03d         ║\n", counts[2]);
    printf("║    3.Set Election staring time     ║    Rejected Candidates: %03d         ║\n", counts[4]);
    printf("║    4.Set Election Ending time      ║    Party Requests: \033[1;33m%03d\033[0m              ║\n", counts[1]);
    printf("║    5.Logout                        ║    Approved Parties: %03d            ║\n", counts[3]);
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
            system(MAIN_PROGRAM);
            break;
        case 0:
            printf("\t\t\nThank you for using Election Management System\n");
            exit(0);
            break;
        } 
}

//------------------------------------------------------------------------------------------------------------------------

int candidate_requests() {
    system(CLEAR_CMD);
    printf("║\n╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                     %sCandidate Register Requests%s                          ║\n", COLOR, CLRRM);
    printf("╠═══════════════════════╦══════════════════════════════════════════════════╣\n");
    printf("║  1.%sAccept Request%s     ║    You can Accept or Reject the Candidates,      ║\n", COLORG, CLRRM);
    printf("║  2.%sReject Request%s     ║    Who Waiting for Admin approval.               ║\n", COLORR, CLRRM);
    printf("╠═══════════════════════╩══════════════════════════════════════════════════╝\n");
    printf("║\n");

    #ifdef _WIN32
        FILE *readfile = fopen("..\\..\\database\\notifications\\candidate_notifications.txt", "r");
    #else
        FILE *readfile = fopen("../../database/notifications/candidate_notifications.txt", "r");
    #endif
    
    if (!readfile) {    
        printf("Error opening file! CN to read\n");
        return 0;
    }
    
    char lines[100][200];  // Store all lines
    char firstline[200];   // Store first line separately
    char *parts[10];       // For tokenizing first line
    char *dataName[9] = {"Candidate ID","Candidate First Name","Candidate Last Name","No","Party Name","Candidate NIC","Candidate Gender","Date of Birth","Election Area"};
    
    int lineCount = 0;
    
    // Read all lines
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), readfile) && lineCount < 100) {
        lineCount++;
    }
    fclose(readfile);
    
    if (lineCount == 0) {
        printf("║  No pending requests!\n");
        printf("\n\nPress Enter to return to the admin menu...");
        getchar();
        getchar();
        return 0;
    }
    
    // Copy first line for processing
    strcpy(firstline, lines[0]);
    
    // Tokenize and display first line
    char temp[200];
    strcpy(temp, firstline);
    char *token = strtok(temp, "¥");
    int j = 0;
    
    while (token != NULL && j < 9) {
        parts[j] = malloc(strlen(token) + 1);
        strcpy(parts[j], token);
        // Remove newline if present
        parts[j][strcspn(parts[j], "\n")] = 0;
        printf("║  %-20s: %s\n", dataName[j], parts[j]);
        token = strtok(NULL, "¥");
        j++;
    }
    int partCount = j;
    
    printf("║\n");
    printf("╠═ Enter Decision (1/2): ");
    int decision;
    scanf("%d", &decision);
    
    if (decision == 1) {
        // Accept: Add to candidates.txt
        #ifdef _WIN32
            FILE *writefile = fopen("..\\..\\database\\source_data\\candidates.txt", "a");
        #else
            FILE *writefile = fopen("../../database/source_data/candidates.txt", "a");
        #endif
        
        if (!writefile) {
            printf("Error opening file for writing!\n");
            // Free allocated memory
            for(int x = 0; x < partCount; x++) free(parts[x]);
            return 0;
        }
        
        // Write all parts with delimiter
        for(int x = 0; x < partCount; x++) {
            fprintf(writefile, "%s", parts[x]);
            if(x < partCount - 1) fprintf(writefile, "¥");
        }
        fprintf(writefile, "\n");
        fclose(writefile);
        
        printf("║\n");      
        printf("╚═ Request Accepted!\n");
        
    } else if (decision == 2) {
        // Reject: Add to rejected_candidates.txt
        #ifdef _WIN32
            FILE *rejectfile = fopen("..\\..\\database\\notifications\\rejected_candidates.txt", "a");
        #else
            FILE *rejectfile = fopen("../../database/notifications/rejected_candidates.txt", "a");
        #endif
        
        if (!rejectfile) {
            printf("Error opening file for writing!\n");
            // Free allocated memory
            for(int x = 0; x < partCount; x++) free(parts[x]);
            return 0;
        }
        
        fprintf(rejectfile, "%s", firstline);
        if(firstline[strlen(firstline)-1] != '\n') {
            fprintf(rejectfile, "\n");
        }
        fclose(rejectfile);
        
        printf("║\n");
        printf("╚═ Request Rejected!\n");
        
    } else {
        printf("║\n");
        printf("╚═ Invalid choice!\n");
        // Free allocated memory
        for(int x = 0; x < partCount; x++) free(parts[x]);
        sleep(2);
        system(CLEAR_CMD);
        showHeader();
        showContent();
        controlPanel();
        return 1;
    }
    
    // Rewrite file without first line
    #ifdef _WIN32
        FILE *rewritefile = fopen("..\\..\\database\\notifications\\candidate_notifications.txt", "w");
    #else
        FILE *rewritefile = fopen("../../database/notifications/candidate_notifications.txt", "w");
    #endif
    
    if (!rewritefile) {
        printf("Error opening file for rewriting!\n");
        // Free allocated memory
        for(int x = 0; x < partCount; x++) free(parts[x]);
        return 0;
    }
    
    // Write all lines except the first
    for(int a = 1; a < lineCount; a++) {
        fprintf(rewritefile, "%s", lines[a]);
    }
    fclose(rewritefile);
    
    // Free allocated memory
    for(int x = 0; x < partCount; x++) {
        free(parts[x]);
    }
    
    printf("\n\nPress Enter to return to the admin menu...");
    getchar();
    getchar(); 
    system(CLEAR_CMD);
    showHeader();
    showContent();
    controlPanel();
    
    return 1;
}

//--------------------------------------------------------------------------------------------------------


int party_requests() {
    system(CLEAR_CMD);
    printf("║\n╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        %sParty Register Requests%s                           ║\n", COLOR, CLRRM);
    printf("╠═══════════════════════╦══════════════════════════════════════════════════╣\n");
    printf("║  1.%sAccept Request%s     ║    You can Accept or Reject the Parties,      ║\n", COLORG, CLRRM);
    printf("║  2.%sReject Request%s     ║    Who Waiting for Admin approval.            ║\n", COLORR, CLRRM);
    printf("╠═══════════════════════╩══════════════════════════════════════════════════╝\n");
    printf("║\n");

    #ifdef _WIN32
        FILE *readfile = fopen("..\\..\\database\\notifications\\party_notifications.txt", "r");
    #else
        FILE *readfile = fopen("../../database/notifications/party_notifications.txt", "r");
    #endif
    
    if (!readfile) {    
        printf("Error opening file! PN to read\n");
        return 0;
    }
    
    char lines[100][200]; 
    char firstline[200]; 
    char *parts[10];  
    char *dataName[5] = {"Party ID", "Party Name", "Party Leader", "Party Symbol", "Registration Date"};
    
    int lineCount = 0;
    
    while (fgets(lines[lineCount], sizeof(lines[lineCount]), readfile) && lineCount < 100) {
        lineCount++;
    }
    fclose(readfile);
    
    if (lineCount == 0) {
        printf("║  No pending requests!\n");
        printf("\n\nPress Enter to return to the admin menu...");
        getchar();
        getchar();
        system(CLEAR_CMD);
        showHeader();
        showContent();
        controlPanel();
        return 0;
    }
    
    // Copy first line for processing
    strcpy(firstline, lines[0]);
    
    // Tokenize and display first line
    char temp[200];
    strcpy(temp, firstline);
    char *token = strtok(temp, "¥");
    int j = 0;
    
    while (token != NULL && j < 5) {
        parts[j] = malloc(strlen(token) + 1);
        strcpy(parts[j], token);
        // Remove newline if present
        parts[j][strcspn(parts[j], "\n")] = 0;
        printf("║  %-20s: %s\n", dataName[j], parts[j]);
        token = strtok(NULL, "¥");
        j++;
    }
    int partCount = j;
    
    printf("║\n");
    printf("╠═ Enter Decision (1/2): ");
    int decision;
    scanf("%d", &decision);
    
    if (decision == 1) {
        // Accept: Add to party.txt
        #ifdef _WIN32
            FILE *writefile = fopen("..\\..\\database\\source_data\\party.txt", "a");
        #else
            FILE *writefile = fopen("../../database/source_data/party.txt", "a");
        #endif
        
        if (!writefile) {
            printf("Error opening file for writing!\n");
            // Free allocated memory
            for(int x = 0; x < partCount; x++) free(parts[x]);
            return 0;
        }
        
        // Write all parts with delimiter
        for(int x = 0; x < partCount; x++) {
            fprintf(writefile, "%s", parts[x]);
            if(x < partCount - 1) fprintf(writefile, "¥");
        }
        fprintf(writefile, "\n");
        fclose(writefile);
        
        printf("║\n");      
        printf("╚═ Request Accepted!\n");
        
    } else if (decision == 2) {
        // Reject: Add to rejected_parties.txt
        #ifdef _WIN32
            FILE *rejectfile = fopen("..\\..\\database\\notifications\\rejected_parties.txt", "a");
        #else
            FILE *rejectfile = fopen("../../database/notifications/rejected_parties.txt", "a");
        #endif
        
        if (!rejectfile) {
            printf("Error opening file for writing!\n");
            // Free allocated memory
            for(int x = 0; x < partCount; x++) free(parts[x]);
            return 0;
        }
        
        fprintf(rejectfile, "%s", firstline);
        if(firstline[strlen(firstline)-1] != '\n') {
            fprintf(rejectfile, "\n");
        }
        fclose(rejectfile);
        
        printf("║\n");
        printf("╚═ Request Rejected!\n");
        
    } else {
        printf("║\n");
        printf("╚═ Invalid choice!\n");
        // Free allocated memory
        for(int x = 0; x < partCount; x++) free(parts[x]);
        sleep(2);
        system(CLEAR_CMD);
        showHeader();
        showContent();
        controlPanel();
        return 1;
    }
    
    // Rewrite file without first line
    #ifdef _WIN32
        FILE *rewritefile = fopen("..\\..\\database\\notifications\\party_notifications.txt", "w");
    #else
        FILE *rewritefile = fopen("../../database/notifications/party_notifications.txt", "w");
    #endif
    
    if (!rewritefile) {
        printf("Error opening file for rewriting!\n");
        // Free allocated memory
        for(int x = 0; x < partCount; x++) free(parts[x]);
        return 0;
    }
    
    // Write all lines except the first
    for(int a = 1; a < lineCount; a++) {
        fprintf(rewritefile, "%s", lines[a]);
    }
    fclose(rewritefile);
    
    // Free allocated memory
    for(int x = 0; x < partCount; x++) {
        free(parts[x]);
    }
    
    printf("\n\nPress Enter to return to the admin menu...");
    getchar();
    getchar(); 
    system(CLEAR_CMD);
    showHeader();
    showContent();
    controlPanel();
    
    return 1;
}


//------------------------------------------------------------------------------------------------------------------------

int countOfRequests(int location){
    char *fileDir; 
    #ifdef _WIN32
        if (location==0){fileDir = "..\\..\\database\\notifications\\candidate_notifications.txt";}
        else if(location==1){fileDir = "..\\..\\database\\notifications\\party_notifications.txt";}
        else if(location==2){fileDir = "..\\..\\database\\source_data\\candidates.txt";}
        else if(location==3){fileDir = "..\\..\\database\\source_data\\party.txt";}
        else if(location==4){fileDir = "..\\..\\database\\notifications\\rejected_candidates.txt";}
        else if(location==5){fileDir = "..\\..\\database\\notifications\\rejected_parties.txt";}
    #else
        if (location==0){fileDir = "../../database/notifications/candidate_notifications.txt";}
        else if(location==1){fileDir = "../../database/notifications/party_notifications.txt";}
        else if(location==2){fileDir = "../../database/source_data/candidates.txt";}
        else if(location==3){fileDir = "../../database/source_data/party.txt";}
        else if(location==4){fileDir = "../../database/notifications/rejected_candidates.txt";}
        else if(location==5){fileDir = "../../database/notifications/rejected_parties.txt";}
    #endif
    
    int number=0;
    char line[1024];
    FILE *readCandidate = fopen(fileDir, "r");
    if (!readCandidate) {
        printf("Error opening file! %d\n", location);
        return 0;
    }
    while (fgets(line, sizeof(line), readCandidate)) {
        number++;
    }
    fclose(readCandidate);
    return number;
}

//------------------------------------------------------------------------------------------------------------------------

void set_election_start_time() {
    char start_time[20];
    printf("\n\n╔═ %sSet Election Starting Time%s\n", COLOR, CLRRM);
    printf("║\n");
    printf("╠═ Enter Starting Time (Ex: 8:00AM): ");
    scanf("%19s", start_time);
    #ifdef _WIN32
        FILE *file = fopen("..\\..\\database\\notifications\\election_time.txt", "r+");
    #else
        FILE *file = fopen("../../database/notifications/election_time.txt", "r+");
    #endif
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

//------------------------------------------------------------------------------------------------------------------------

void set_election_end_time() {
    char end_time[20];
    printf("\n%s\n╔═ Set Election Ending Time%s\n", COLOR, CLRRM);
    printf("║\n");
    printf("╚═ Enter Ending Time (Ex: 5:00PM): ");
    scanf("%19s", end_time);
    #ifdef _WIN32
        FILE *file = fopen("..\\..\\database\\notifications\\election_time.txt", "r+");
    #else
        FILE *file = fopen("../../database/notifications/election_time.txt", "r+");
    #endif
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

//------------------------------------------------------------------------------------------------------------------------