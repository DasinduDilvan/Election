#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../main/main.h"

#ifdef _WIN32
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif

const char *PLCOLOR = "\033[1;33m";
const char *PLCLRRM = "\033[0m";

void party_login();
void showPartyLoginHeader();
void showPartyDetails();
char *getUsername();
char *getPassword();
char *partyauthenticate(char *username, char *password);

// Global variables to store login info
char *loginMessage;
char user_name[20];

//party_login();

void party_login(){
    system("chcp 65001");
    system("clear || cls");
    showPartyLoginHeader();
    
    char *input_username = getUsername();
    char *input_password = getPassword();
    
    // Store username for later use
    strcpy(user_name, input_username);
    
    loginMessage = partyauthenticate(input_username, input_password);
    
    if(loginMessage != NULL && strcmp(loginMessage, "Wrong username password or your Registration rejected") != 0){
        printf("\n\t\tLogin Successful!\n");
        printf("\t\t%s\n", loginMessage);
        sleep(2);
        system(CLEAR_CMD);
        showPartyLoginHeader();
        showPartyDetails();
        
        sleep(2);
        main_menu();
    }
    else{
        printf("\n\tLogin Failed!");
        if(loginMessage != NULL){
            printf("\t%s\n", loginMessage);
        }
        sleep(2);
        printf("║\n");
        sleep(2);
        main_menu();
    }

    //return 0;
}

void showPartyLoginHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", PLCOLOR, PLCLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", PLCOLOR, PLCLRRM);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", PLCOLOR, PLCLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", PLCOLOR, PLCLRRM);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", PLCOLOR, PLCLRRM);
    printf("║                                                                          ║\n");
}

void showPartyDetails() {
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                          %sParty Information%s                               ║\n", PLCOLOR, PLCLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                          ║\n");
    
    // Read party details from file
    #ifdef _WIN32
        FILE *partyFile = fopen("..\\database\\source_data\\party.txt", "r");
    #else
        FILE *partyFile = fopen("../database/source_data/party.txt", "r");
    #endif
    
    if (!partyFile) {
        printf("║                  Error: Unable to load party deta                        ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
        return;
    }
    
    char line[256];
    int found = 0;
    
    while(fgets(line, sizeof(line), partyFile)){
        line[strcspn(line, "\n")] = '\0';
        
        char lineCopy[256];
        strcpy(lineCopy, line);
        
        char *token = strtok(lineCopy, "<@|@>");
        int fieldIndex = 0;
        char partyID[50] = "";
        char username[50] = "";
        char partyName[100] = "";
        char leaderName[100] = "";
        char symbol[50] = "";
        
        while(token != NULL){
            switch(fieldIndex){
                case 0: strcpy(partyID, token); break;
                case 1: strcpy(username, token); break;
                case 2: break; // Skip password
                case 3: strcpy(partyName, token); break;
                case 4: strcpy(leaderName, token); break;
                case 5: strcpy(symbol, token); break;
            }
            token = strtok(NULL, "<@|@>");
            fieldIndex++;
        }
        
        // Check if this is the logged-in user's party
        if(strcmp(username, user_name) == 0){
            found = 1;
            printf("║    Party ID     :    %4s                                                ║\n", partyID);
            printf("║    Party Name   :    %-50s  ║\n", partyName);
            printf("║    Leader Name  :    %-50s  ║\n", leaderName);
            printf("║    Symbol       :    %-50s  ║\n", symbol);
            printf("║    Username     :    %-50s  ║\n", username);
            printf("║                                                                          ║\n");
            printf("║    \033[1;33mStatus\033[0m       :    \033[1;32mApproved for Election\033[0m                               ║\n");
            break;
        }
    }
    
    fclose(partyFile);
    
    if(!found){
        printf("║  Party details not found                                                ║\n");
        printf("║                                                                          ║\n");
    }
    
    printf("║                                                                          ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
}

char *getUsername(){
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                               %sParty Login%s                                ║\n", PLCOLOR, PLCLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
    printf("║\n");
    static char username[20];
    printf("╠═ Enter Username: ");
    scanf("%19s", username);
    return username;
}

char *getPassword() {
    static char password[20];
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", password);
    return password;
}

char *partyauthenticate(char *username, char *password){
    
    #ifdef _WIN32
        FILE *partyApproved = fopen("..\\database\\source_data\\party.txt", "r");
    #else
        FILE *partyApproved = fopen("../database/source_data/party.txt", "r");
    #endif
    
    if (!partyApproved) {
        return "Wrong username password or your Registration rejected";
    }
    char line[256];
    
    // Check in approved parties only
    while(fgets(line, sizeof(line), partyApproved)){
        line[strcspn(line, "\n")] = '\0';
        
        char lineCopy[256];
        strcpy(lineCopy, line);
        
        char *token = strtok(lineCopy, "<@|@>");
        int fieldIndex = 0;
        char fileUsername[100] = "";
        char filePassword[100] = "";
        
        while(token != NULL){
            if(fieldIndex == 2){
                strcpy(fileUsername, token);
            }
            else if(fieldIndex == 3){
                strcpy(filePassword, token);
            }
            token = strtok(NULL, "<@|@>");
            fieldIndex++;
        }
        
        if(strcmp(fileUsername, username) == 0 && strcmp(filePassword, password) == 0){
            fclose(partyApproved);
            return "Party has been approved for the Election";
        }
    }
    
    // Not found in file
    fclose(partyApproved);
    return "Wrong username password or your Registration rejected";
}
