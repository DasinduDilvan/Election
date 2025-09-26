#include <stdio.h>

int option;

int main(){

do{
    printf("|---------------------------------------|\n");
    printf("|                                       |\n");
    printf("|    Welcome to the Election System     |\n");
    printf("|                                       |\n");
    printf("|---------------------------------------|\n");
    printf("|                                       |\n");
    printf("|    1. Voter Login                     |\n");
    printf("|    2. Voter Register                  |\n");
    printf("|    3. Candidate Login                 |\n");
    printf("|    4. Candidate Register              |\n");
    printf("|    5. Party Login                     |\n");
    printf("|    6. Party Register                  |\n");
    printf("|    1. Read Terms & Conditions         |\n");
    printf("|    0. Exit                            |\n");
    printf("|                                       |\n");
    printf("|---------------------------------------|\n");
    printf("|\n");
    printf("|   Please select an option:  ");
    scanf("%d", &option);
    printf("|\n");
    printf("|--------------------------------------\n");
}
while(option < 0 || option > 7);

    switch(option){
        case 1:
            printf("Voter Login Selected\n");
            break;
        case 2:
            printf("Voter Register Selected\n");
            break;
        case 3:
            printf("Candidate Login Selected\n");
            break;
        case 4:
            printf("Candidate Register Selected\n");
            break;
        case 5:
            printf("Party Login Selected\n");
            break;
        case 6:
            printf("Party Register Selected\n");
            break;
        case 7:
            printf("Read Terms & Conditions Selected\n");
            break;
        case 0:
            printf("Exiting the system. Goodbye!\n");
            break;
    }

    return 0;
}