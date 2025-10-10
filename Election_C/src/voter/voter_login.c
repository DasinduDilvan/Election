#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
void showContent();
char *username();
char *password();

int main(){

    system("clear || cls");
    showHeader();
    char *user_name = username();
    char *pass_word = password();

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
    printf("║                                Voter Login                               ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════╣\n");

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





