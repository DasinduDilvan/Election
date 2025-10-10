#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
char *voterID();
char *fname();
char *lname();
char *username();
char *password();
char *NIC();
char *gender();
char *dob();
char *area();
char confirm();
int make_voter_ID();
void massageSuccess();
void massageCanceled();

int main(){
    
    showHeader();
    char *firstname = fname();
    char *lastname = lname();
    char *user_name = username();
    char *pass_word = password();
    char *NIC_num = NIC();
    char *gender_mf  = gender();
    char *Dateofbirth = dob();
    char *election_area = area();
    char confirm_save;
    printf("║\n");
    printf("╠═ Confirm Registration (y/n): ");
    scanf(" %c", &confirm_save);

    if (confirm_save == 'y' || confirm_save == 'Y') {

        int voter_ID_num = make_voter_ID();

        printf("║\n");
        printf("╠═ Registration confirmed.\n");


            FILE *file = fopen("..//..//database//source_data//voters.txt", "a");
            if (file == NULL) {
                printf("Error opening file!\n");
                return 1;
            }
            fprintf(file,"%s\n", firstname);
            fprintf(file,"%s\n", lastname);
            fprintf(file,"%s\n", user_name);
            fprintf(file,"%s\n", pass_word);
            fprintf(file,"%s\n", NIC_num);
            fprintf(file,"%s\n", gender_mf);
            fprintf(file,"%s\n", Dateofbirth);
            fprintf(file,"%s\n\n", election_area);
            fprintf(file,"%d\n", voter_ID_num);
            fclose(file);

            massageSuccess();
            
    }
    else {
        printf("║\n");
        printf("╠═ Registration cancelled.\n");
        massageCanceled();
        return 0;    
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
    printf("║                                Voter Login                               ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
}

int make_voter_ID(){
     
    FILE *file = fopen("..//..//database//source_data//voters.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[512];
    char last_line[512] = "";

    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        while (line[i] != '\0') {
            last_line[i] = line[i];
            i++;
        }
        last_line[i] = '\0'; 
    }

    fclose(file);   

    int voter_ID = 0;
    for (int i = 0; last_line[i] != '\0'; i++) {
        if (last_line[i] >= '0' && last_line[i] <= '9') {
            voter_ID = voter_ID * 10 + (last_line[i] - '0');
        }
    }

    return voter_ID + 1;
}

char *fname(){
    static char fname[20];
    printf("║\n");
    printf("╠═ Enter First Name: ");
    scanf("%19s", fname);
    return fname;
}

char *lname(){
    static char lname[20];
    printf("║\n");
    printf("╠═ Enter Last Name: ");
    scanf("%19s", lname);
    return lname;
}

char *username(){
    static char username[20];
    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%19s", username);
    return username;
}

char *password(){
    static char password[20];
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%19s", password);
    return password;
}

char *NIC(){
    static char NIC[20];
    printf("║\n");
    printf("╠═ Enter NIC: ");
    scanf("%19s", NIC);
    return NIC;
}

char *gender(){
    static char gender[10];
    printf("║\n");
    printf("╠═ Enter Gender(m/f): ");
    scanf("%9s", gender);
    return gender;
}

char *dob(){
    static char dob[15];
    printf("║\n");
    printf("╠═ Enter Date of Birth(DD/MM/YYYY): ");
    scanf("%14s", dob);
    return dob;
}

char *area(){
    static char area[30];
    printf("║\n");
    printf("╠═ Enter Area: ");
    scanf("%29s", area);
    return area;
}

void massageSuccess(){
    printf("║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        %sRegistration Successful!%s                          ║\n", COLOR, CLRRM);
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
}

void massageCanceled(){
    printf("║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         %sRegistration Canceled!%s                           ║\n", COLOR, CLRRM);
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");

}
