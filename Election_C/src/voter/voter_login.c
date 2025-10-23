#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
    #define CLEAR_CMD "clear"
#else
    #define CLEAR_CMD "clear"
#endif

const char *COLORVL = "\033[1;33m";
const char *CLRRMVL = "\033[0m";

void voter_login();
void showVoterLogHeader();
void showContentofVL();
char *username();
char *password();
char *loginMessage;
void showContentofVL();

char *voterauthenticate(char *username,char *password);

void voter_login(){

    system("clear || cls");
    showVoterLogHeader();
    char *user_name = username();
    char *pass_word = password();

    char *loginMessage = voterauthenticate(user_name,pass_word);
    if(loginMessage != NULL){

        printf("\n\t\tLogin Successful!\n");
        sleep(1);
        system(CLEAR_CMD);
        showVoterLogHeader();
        printf("Welcome %s\n",loginMessage);
        showContentofVL();

    }
    else{
        printf("lodin Faild\n");
        sleep(2);
    }
   
}

void showVoterLogHeader() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", COLORVL, CLRRMVL);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", COLORVL, CLRRMVL);
    printf("║                                                                          ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                               %sVoter Login%s                                ║\n", COLORVL, CLRRMVL);
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
    printf("║\n");

}

void showContentofVL() {
    printf("╠════════════════════════════════════╦═════════════════════════════════════╣\n");
    printf("║                                    ║                                     ║\n");
    printf("║  \033[1;32mLogged in as: Voter\033 ║                                  \033[1;35mDashboard:\033[0m        ║\n");
    printf("║                                    ║                                     ║\n");
    printf("║    1.Party Register Requests       ║    Candidate Requests:              ║\n"); 
    printf("║    2.Candidate Register Requests   ║    Party Requests:                  ║\n" );
    printf("║    3.Set Election staring time     ║    Approved Candidates:             ║\n" );
    printf("║    4.Set Election Ending time      ║    Approved Parties:                ║\n");
    printf("║    5.Logout                        ║    Rejected Candidates:             ║\n");
    printf("║    0.Exit                          ║    Rejected Parties:                ║\n");
    printf("║                                    ║                                     ║\n");
    printf("╠════════════════════════════════════╩═════════════════════════════════════╝\n");
    printf("║\n");
    printf("╠══ ");
}

    char *username(){
    static char username[20];
    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%19s", username);
    return username;
    }

    char *password() {
    static char password[20];
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", password);
    return password;
}


char *voterauthenticate(char *username,char *password){
    
    #ifdef _WIN32
        FILE *fp = fopen("..\\database\\source_data\\voter.txt", "r");
    #else
        FILE *fp = fopen("../database/source_data/voters.txt", "r");
    #endif
    if (!fp) return NULL; //error opening file

    char line[100];
    int lineCounter=0;

    char name[100]="";
    char fileUsername[100] = "";
    char filePassword[100] = "";

    while(fgets(line,sizeof(line),fp)){
        line[strcspn(line, "\n")] = '\0';
        lineCounter=lineCounter+1;
        
        if(lineCounter==2){
            strcpy(name,line);
        }

        if(lineCounter==4){
            strcpy(fileUsername,line);
            

        }
        else if(lineCounter==5){
            strcpy(filePassword,line);

        }
        
        if (lineCounter==10){
            if(strcmp(username,fileUsername) ==0 && strcmp(password,filePassword) ==0 ){
                
                return username;
            }

        lineCounter=0;
        fileUsername[0] = '\0';
        filePassword[0] = '\0';

        }
        
    }
    fclose(fp);

    return NULL;
    
}

