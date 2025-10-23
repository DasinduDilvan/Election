#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

const char *CDCOLOR = "\033[1;36m"; 
const char *CDCLRRM = "\033[0m";

void candidate_login();
void showCandidateLoginHeader();
void showCandidateDetails();
char *getCandidateUsername();
char *getCandidatePassword();
char *authenticateCandidate(char *username, char *password);

char *candidateLoginMessage;
char candidate_user_name[20];

void candidate_login(){
    system("chcp 65001");
    system("clear || cls");
    showCandidateLoginHeader();
    
    char *input_username = getCandidateUsername();
    char *input_password = getCandidatePassword();
    
    strcpy(candidate_user_name, input_username);
    
    candidateLoginMessage = authenticateCandidate(input_username, input_password);
    
    if(candidateLoginMessage != NULL && strcmp(candidateLoginMessage, "Wrong username password or your Registration rejected") != 0){
        printf("\n\t\tLogin Successful!\n");
        printf("\t\t%s\n", candidateLoginMessage);
        sleep(2);
        system(CLEAR_CMD);
        showCandidateLoginHeader();
        showCandidateDetails();
        
        printf("\n  Press Enter to go back to home...");
        getchar();
        getchar();
        system("..\\main\\main.exe");
    }
    else{
        printf("\n\tLogin Failed!");
        if(candidateLoginMessage != NULL){
            printf("\t%s\n", candidateLoginMessage);
        }
        sleep(2);
        printf("║\n");
        printf("╠═  Press Enter to go back to home...");
        getchar();
        getchar();
        system("..\\main\\main.exe");
    }
}

void showCandidateLoginHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", CDCOLOR, CDCLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", CDCLRRM, CDCLRRM);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", CDCOLOR, CDCLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", CDCOLOR, CDCLRRM);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", CDCOLOR, CDCLRRM);
    printf("║                                                                          ║\n");
}

void showCandidateDetails() {
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                        %sCandidate Information%s                             ║\n", CDCOLOR, CDCLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                          ║\n");
    
    #ifdef _WIN32
        FILE *candidateFile = fopen("..\\..\\database\\source_data\\candidates.txt", "r");
    #else
        FILE *candidateFile = fopen("../../database/source_data/candidates.txt", "r");
    #endif
    
    if (!candidateFile) {
        printf("║                  Error: Unable to load candidate data                   ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
        return;
    }
    
    char line[256];
    int found = 0;
    
    while(fgets(line, sizeof(line), candidateFile)){
        line[strcspn(line, "\n")] = '\0';
        
        char lineCopy[256];
        strcpy(lineCopy, line);
        
        char *token = strtok(lineCopy, "¥");
        int fieldIndex = 0;
        char candidateID[50] = "";
        char username[50] = "";
        char candidateName[100] = "";
        char district[100] = "";
        char partyName[100] = "";
        
        while(token != NULL){
            switch(fieldIndex){
                case 0: strcpy(candidateID, token); break;
                case 1: strcpy(username, token); break;
                case 2: break; // Password
                case 3: strcpy(candidateName, token); break;
                case 4: strcpy(district, token); break;
                case 5: strcpy(partyName, token); break;
            }
            token = strtok(NULL, "¥");
            fieldIndex++;
        }
        
        if(strcmp(username, candidate_user_name) == 0){
            found = 1;
            printf("║    Candidate ID :    %04s                                                ║\n", candidateID);
            printf("║    Name         :    %-50s  ║\n", candidateName);
            printf("║    District     :    %-50s  ║\n", district);
            printf("║    Party        :    %-50s  ║\n", partyName);
            printf("║    Username     :    %-50s  ║\n", username);
            printf("║                                                                          ║\n");
            printf("║    \033[1;36mStatus\033[0m       :    \033[1;32mApproved for Election\033[0m                               ║\n");
            break;
        }
    }
    
    fclose(candidateFile);
    
    if(!found){
        printf("║  Candidate details not found                                            ║\n");
        printf("║                                                                          ║\n");
    }
    
    printf("║                                                                          ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
}

char *getCandidateUsername(){
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                             %sCandidate Login%s                              ║\n", CDCOLOR, CDCLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
    printf("║\n");
    static char username[20];
    printf("╠═ Enter Username: ");
    scanf("%19s", username);
    return username;
}

char *getCandidatePassword() {
    static char password[20];
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", password);
    return password;
}

char *authenticateCandidate(char *username, char *password){
    
    #ifdef _WIN32
        FILE *candidateApproved = fopen("..\\..\\database\\source_data\\candidates.txt", "r");
    #else
        FILE *candidateApproved = fopen("../../database/source_data/candidates.txt", "r");
    #endif
    
    if (!candidateApproved) {
        return "Wrong username password or your Registration rejected";
    }
    char line[256];
    

    while(fgets(line, sizeof(line), candidateApproved)){
        line[strcspn(line, "\n")] = '\0';
        
        char lineCopy[256];
        strcpy(lineCopy, line);
        
        char *token = strtok(lineCopy, "¥");
        int fieldIndex = 0;
        char fileUsername[100] = "";
        char filePassword[100] = "";
        
        while(token != NULL){
            if(fieldIndex == 1){
                strcpy(fileUsername, token);
            }
            else if(fieldIndex == 2){
                strcpy(filePassword, token);
            }
            token = strtok(NULL, "¥");
            fieldIndex++;
        }
        
        if(strcmp(fileUsername, username) == 0 && strcmp(filePassword, password) == 0){
            fclose(candidateApproved);
            return "Candidate has been approved for the Election";
        }
    }
    
    fclose(candidateApproved);
    return "Wrong username password or your Registration rejected";
}