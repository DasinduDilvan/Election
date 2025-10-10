#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

const char *COLOR = "\033[1;33m";
const char *CLRRM = "\033[0m";

void showHeader();
void showContent();

int main(){

    system("clear || cls");
    showHeader();

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
    printf("║                                Admin Login                               ║\n");
    printf("╠══════════════════════════════════╦═══════════════════════════════════════╣\n");
}