#include <stdio.h>

int main(){
    printf("Hello, World!\n");
    FILE *file = fopen("..//..//database//source_data//voters.txt", "a");
            if (file == NULL) {
                printf("Error opening file!\n");
                return 1;
            }
            fprintf(file,"%s\n", firstname);
            fclose(file);

    return 0;
}
