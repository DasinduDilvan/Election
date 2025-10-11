#include <stdio.h>

int main(){
    printf("Hello, World!\n");
    char names[100];
    FILE *file = fopen("test.txt", "r");
            if (file == NULL) {
                printf("Error opening file!\n");
                return 1;
            }
            char firstname[50];
            while(fgets(firstname, sizeof(names), file)){
                printf("First name: %s", firstname);
            }
            

            fclose(file);

            printf("aa%c", firstname[1]);
    return 0;
}
