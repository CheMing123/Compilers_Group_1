#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    char *buffer = 0;
    long length;


    file = fopen("test.sy", "r");

    
    if(!file){
        printf("ERROR: COULD NOT FIND FILE\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    printf("LENGTH: %ld\n", length);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(length + 1);

    fread(buffer, 1, length, file);
    if(!fread){
        printf("ERROR: fread failed!\n");
        exit(1);
    }
    printf("%s", buffer);
    fclose(file);
    buffer[length] = '\0';

    char *current = malloc(sizeof(char) * length + 1);
    current = buffer; 
    int current_index = 0;
    while(current[current_index] != '\0'){
        printf("%c\n", current[current_index]);
        current_index++;
    }

    return 0;
}
