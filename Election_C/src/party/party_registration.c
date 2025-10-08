#include <stdio.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
char *pname();
char *lname();
char *symb();
char *regdate();
char *dist();

int main(){
    showHeader();
    char *party_name = pname();
    char *leader_name = lname();
    char *symbol = symb();
    char *registration_date = regdate();
    char *district  = dist();
    char confirm_save;
    printf("║\n");
    printf("╠═ Confirm Registration (y/n): ");
    scanf(" %c", &confirm_save);

    if (confirm_save != 'y' && confirm_save != 'Y') {
        printf("╠═ Registration cancelled.\n");
        return 0;
    }
    else {
        printf("Registration confirmed.\n");

    FILE *file = fopen("../../database/source_data/party.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file,"%s\n", party_name);
    fprintf(file,"%s\n", leader_name);
    fprintf(file,"%s\n", symbol);
    fprintf(file,"%s\n", registration_date);
    fprintf(file,"%s\n", district);
    fclose(file);

    /*FILE *ffff = fopen("../../../database/source_data/party.txt", "r");
    if (ffff == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    char test[100];
    fscanf(ffff,"%s\n", test);
    printf("%s\n", test);
    fclose(file);*/

    printf("\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                       %sRegistration Successful!%s                           ║\n", COLOR, CLRRM);
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
    }
return 0;
}

void showHeader(){
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
    printf("║                                Party Registration                        ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
}

char *pname(){
    static char pname[20];
    printf("║\n");
    printf("╠═ Enter Party Name: ");
    scanf("%19s", pname);
    return pname;
}

char *lname(){
    static char lname[20];
    printf("║\n");
    printf("╠═ Enter Leader Name: ");
    scanf("%19s", lname);
    return lname;
}

char *symb(){
    static char symb[20];
    printf("║\n");
    printf("╠═ Enter Symbol: ");
    scanf("%19s", symb);
    return symb;
}

char *regdate(){
    static char regdate[15];
    printf("║\n");
    printf("╠═ Enter Registration Date(DD/MM/YYYY): ");
    scanf("%14s", regdate);
    return regdate;
}

char *dist(){
    static char dist[30];
    printf("║\n");
    printf("╠═ Enter District: ");
    scanf("%29s", dist);
    return dist;
}

char confirm(){
    char confirm;
    printf("║\n");
    printf("╠═ Confirm Registration (y/n): ");
    scanf(" %c", &confirm);
    return confirm;
}