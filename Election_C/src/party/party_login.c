#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
    #define CLEAR_CMD "clear"
#else
    #define CLEAR_CMD "clear"
#endif

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
void showContent();
char *username();
char *password();
void showContent();

char *loginMessage;
char *authenticate(char *username,char *password);

int main(){
    system("chcp 65001");
    system("clear || cls");
    showHeader();
    char *user_name = username();
    char *pass_word = password();

    char *loginMessage = authenticate(user_name,pass_word);
    if(loginMessage != NULL){

        printf("\n\t\tLogin Successful!\n");
        sleep(1);
        system(CLEAR_CMD);
        showHeader();
        printf("Welcome %s\n",loginMessage);
        showContent();

    }
    else{
        printf("lodin Faild\n");
        sleep(2);
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
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                               %sAdmin Login%s                                ║\n", COLOR, CLRRM);
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
    printf("║\n");

}

void showContent() {
    printf("╠════════════════════════════════════╦═════════════════════════════════════╣\n");
    printf("║                                    ║                                     ║\n");
    printf("║  \033[1;32mLogged in as: Admin\033 ║                                  \033[1;35mDashboard:\033[0m        ║\n");
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


char *authenticate(char *username,char *password){
    
    #ifdef _WIN32
        FILE *partyApproved = fopen("..\\..\\database\\source_data\\party.txt", "r");
        FILE *partyPending = fopen("..\\..\\database\\notifications\\party_notification.txt", "r");
        FILE *partyRejected = fopen("..\\..\\database\\notifications\\rejected_parties.txt", "r");
    #else
        FILE *partyApproved = fopen("../../database/source_data/party.txt", "r");
        FILE *partyPending = fopen("../../database/notifications/party_notification.txt", "r");
        FILE *partyRejected = fopen("../../database/notifications/rejected_parties.txt", "r");
    #endif
    if (!partyApproved) return NULL;
    if (!partyPending) return NULL;
    if (!partyRejected) return NULL;

    
    
    for(int i=0;i<3;i++){
        char line[100];
        int lineCounter=0;

        char name[100]="";
        char fileUsername[100] = "";
        char filePassword[100] = "";

        while(fgets(line,sizeof(line),partyApproved)){
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

    }

    fclose(partyApproved);
    fclose(partyPending);
    fclose(partyRejected);

    return NULL;


}

