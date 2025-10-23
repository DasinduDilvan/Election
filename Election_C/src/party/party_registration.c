
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void party_registration();
void showPartyHeader();

struct party{
    int Party_ID;
    char Party_Name[50];
    char Username[50];
    char Password[20];
    char Party_Color[20];
    char Party_Leader[20];
    char Symbol[50];
}partydetails;

char confirm();

int getPartyData();

void party_registration{}{
    system("cls || clear");
    showPartyHeader();

    getPartyData();

    char confirm_save;
    printf("║\n");
    printf("╠═ Confirm Party Registration (y/n): ");
   
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

        fprintf(file, "¥%s¥%s¥%s¥%s¥%s¥%s\n%d", partydetails.Party_Name, partydetails.Username, partydetails. partydetails.Party_Color, partydetails.Party_Leader, partydetails.Symbol, partydetails.Party_ID);
        
        fclose(file);

        
        printf("║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                         %sParty Registration saved%s                         ║\n", COLOR, CLRRM);
        printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
    }

    printf("Press Enter to return to the main menu...");
    getchar();
    getchar();
    system("..\\main\\main.exe");

    //return 0;
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

int getPartyData(){
    #ifdef _WIN32
        FILE *file = fopen("..\\..\\database\\notifications\\party_notifications.txt", "r");
    #else
        FILE *file = fopen("../../database/notifications/party_notifications.txt", "r");
    #endif

    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    char line[512];
    char last_line[512] = "";

    while (fgets(line, sizeof(line), file)) {
        strcpy(last_line, line);
    }

    fclose(file);

    //int party_ID = 0;
    for (int i = 0; last_line[i] != '\0'; i++) {
        if (last_line[i] >= '0' && last_line[i] <= '9') {
            partydetails.Party_ID = partydetails.Party_ID * 10 + (last_line[i] - '0');
        }
    }
    ++partydetails.Party_ID;

    //return party_ID =+ 1;

    printf("║\n");
    printf("╠═ Enter Party Name: ");
    scanf(" %49s[^\n]", partydetails.Party_Name);

    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%49s", partydetails.Username);

    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", partydetails.Password);

    printf("║\n");
    printf("╠═ Enter Party Color: ");
    scanf("%19s", partydetails.Party_Color);

    printf("║\n");
    printf("╠═ Enter Party Leader: ");
    scanf("%19s", partydetails.Party_Leader);

    printf("║\n");
    printf("╠═ Enter Party Symbol: ");
    scanf(" %49s[^\n]", partydetails.Symbol);
}

