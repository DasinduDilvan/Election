#include <stdio.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
char voterID();
char fname();
char lname();
char username();
char password();
char NIC();
char gender();
char dob();
char area();
char confirm();

int main(){
    showHeader();
    char *voter_ID = voterID();
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

    if (confirm_save != 'y' && confirm_save != 'Y') {
        printf("╠═ Registration cancelled.\n");
        return 0;
    }
    else {
        printf("Registration confirmed.\n");

    FILE *file = fopen("../../../database/source_data/voters.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file,"%s\n", voter_ID);
    fprintf(file,"%s\n", firstname);
    fprintf(file,"%s\n", lastname);
    fprintf(file,"%s\n", user_name);
    fprintf(file,"%s\n", pass_word);
    fprintf(file,"%s\n", NIC_num);
    fprintf(file,"%s\n", gender_mf);
    fprintf(file,"%s\n", Dateofbirth);
    fprintf(file,"%s\n", election_area);
    fclose(file);

    FILE *file = fopen("../../../database/source_data/voters.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    char test[100];
    fscanf(file,"%s\n", test);
    printf("%s\n", test);
    fclose(file);
    
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
    printf("║                                Voter Login                               ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╝\n");
}

char voterID(){
    char voterID[20];
    printf("║\n");
    printf("╠═ Enter Voter ID: ");
    scanf("%s", voterID);
    return *voterID;
}

char fname(){
    char fname[20];
    printf("║\n");
    printf("╠═ Enter First Name: ");
    scanf("%s", fname);
    return *fname;
}

char lname(){
    char lname[20];
    printf("║\n");
    printf("╠═ Enter Last Name: ");
    scanf("%s", lname);
    return *lname;
}

char username(){
    char username[20];
    printf("║\n");
    printf("╠═ Enter Username: ");
    scanf("%s", username);
    return *username;
}

char password(){
    char password[20];
    printf("║\n");
    printf("╠═ Enter Password: ");
    scanf("%s", password);
    return *password;
}

char NIC(){
    char NIC[20];
    printf("║\n");
    printf("╠═ Enter NIC: ");
    scanf("%s", NIC);
    return *NIC;
}

char gender(){
    char gender[10];
    printf("║\n");
    printf("╠═ Enter Gender(m/f): ");
    scanf("%s", gender);
    return *gender;
}

char dob(){
    char dob[15];
    printf("║\n");
    printf("╠═ Enter Date of Birth(DD/MM/YYYY): ");
    scanf("%s", dob);
    return *dob;
}

char area(){
    char area[30];
    printf("║\n");
    printf("╠═ Enter Area: ");
    scanf("%s", area);
    return *area;
}

char confirm(){
    char confirm;
    printf("║\n");
    printf("╠═ Confirm Registration (y/n): ");
    scanf(" %c", &confirm);
    return confirm;
}