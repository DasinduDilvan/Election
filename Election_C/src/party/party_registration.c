
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showPartyHeader();
char *partyname();
char *username();
char *password();
char *partycolor();
char *partyleader(); 
char confirm();

int main(){
    system("cls || clear");
    showPartyHeader();
    
    char *party_name = partyname();
    char *user_name = username();
    char *pass_word = password();
    char *color = partycolor();
    char *leader  = partyleader();

    char confirm_save;
    printf("║\n");
    printf("╠═ Confirm Party Registration (y/n): ");

        int Party_ID = partyID();
   
    scanf(" %c", &confirm_save); 

    if (confirm_save != 'y' && confirm_save != 'Y') {
        printf("║\n");
        printf("╠═ Registration cancelled.\n");
        return 0;
    }
    else {
        printf("║\n");
        printf("╠═ Registration confirmed. Status set to PENDING for Admin Approval.\n");

        FILE *file = fopen("../../database/notifications/party_notifications.txt", "a");
        if (file == NULL) {
            printf("Error opening file for party data!\n");
            return 1;
        }

        fprintf(file, "¥%s¥%s¥%s¥%s\n", party_name, user_name, pass_word, color, leader);
        
        fclose(file);

        
        printf("║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                         %sParty Registration saved%s                         ║\n", COLOR, CLRRM);
        printf("║                     Waiting on Administrator approval                    ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
    }

    printf("Press Enter to return to the main menu...");
    getchar();
    getchar();
    system("..\\main\\main.exe");

    return 0;
}
void showPartyHeader(){
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
}

char *partyname(){
    static char partyname[50];
    printf("║\n");
    printf("╠═ Enter Party Name: ");
    scanf(" %49s[^\n]", partyname);
    return partyname;
}

char *username(){
    static char username[50];
    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%49s", username);
    return username;
}

char *password(){
    static char password[20];
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", password);
    return password;
}

char *partycolor(){
    static char color[20];
    printf("║\n");
    printf("╠═ Enter Party Color: ");
    scanf("%19s", color);
    return color;
}

char *partyleader(){
    static char leader[20];
    printf("║\n");
    printf("╠═ Enter Party Leader: ");
    scanf("%19s", leader);
    return leader;
}