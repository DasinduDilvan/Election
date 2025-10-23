
#include <stdio.h>


const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showCandidateHeader();
char *candidateID(); 
char *fname();
char *lname();
char *username();
char *password();
char *NIC();
char *gender();
char *partyNumber(); 
char confirm();

int main(){
    showCandidateHeader();
    
    
    int candidate_ID = candidateID();
    char *firstname = fname();
    char *lastname = lname();
    char *user_name = username();
    char *pass_word = password();
    char *NIC_num = NIC();
    char *gender_mf  = gender();
    char *party_num = partyNumber(); 
    char *approval_status = "PENDING"; 

    char confirm_save;
    printf("║\n");
    printf("╠═ Confirm Candidate Registration (y/n): ");
   
    scanf(" %c", &confirm_save); 

    if (confirm_save != 'y' && confirm_save != 'Y') {
        
        printf("╠═ Registration cancelled.\n");
        return 0;
    }
    else {
        printf("║\n");
        printf("╠═ Registration confirmed. Status set to PENDING for Admin Approval.\n");


        FILE *file = fopen("../../database/source_data/candidates.txt", "a");
        if (file == NULL) {
            printf("Error opening file for candidate data!\n");
            return 1;
        }

fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n", 
                firstname, 
                lastname, 
                user_name, 
                pass_word, 
                NIC_num, 
                gender_mf, 
                party_num, 
                approval_status,
                candidate_ID
        );
        

        fclose(file);

        
        printf("\n");
        printf("╠══════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                    %sCandidate Registration saved%s                     ║\n", COLOR, CLRRM);
        printf("║                     Waiting on Administrator approval                    ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
    }
    return 0;
}
void showCandidateHeader(){
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║      %s███████ ██      ███████  ██████ ████████ ██  ██████  ███    ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ████   ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s█████   ██      █████   ██         ██    ██ ██    ██ ██ ██  ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s██      ██      ██      ██         ██    ██ ██    ██ ██  ██ ██%s      ║\n", COLOR, CLRRM);
    printf("║      %s███████ ███████ ███████  ██████    ██    ██  ██████  ██   ████%s      ║\n", COLOR, CLRRM);
    printf("║                                                                          ║\n");
    printf("╠══════════════════════════════════╦═══════════════════════════════════════╣\n");


}



char candidateID(){
    #ifdef _WIN32
        FILE *file = fopen("..\\..\\database\\notifications\\candidate_notifications.txt", "r");
    #else
        FILE *file = fopen("../../database/notifications/candidate_notifications.txt", "r");
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

    int candidate_ID = 0;
    for (int i = 0; last_line[i] != '\0'; i++) {
        if (last_line[i] >= '0' && last_line[i] <= '9') {
            candidate_ID = candidate_ID * 10 + (last_line[i] - '0');
        }
    }

    return candidate_ID + 1;
}

char *partyNumber(){
    
    static char partyNum[10];
    printf("║\n");
    printf("╠═ Enter Party Number: ");
    scanf("%9s", partyNum);
    return partyNum;
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