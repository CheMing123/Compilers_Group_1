#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*********************
* Notes: digits are not recognized in the lexer, have to look for an 
* alternative way to read strings                     
* stayed in 39:53 
**********************/

typedef enum{
    OPEN_PARENTHESES,
    CLOSE_PARENTHESES,
    SEMI_COLUMN,
} TypeSeparator;

typedef enum{
    EXIT,
} TypeKeyword;

typedef enum{
    INT,
} TypeLiteral;

typedef struct{
    TypeKeyword type;
} TokenKeyword;
    
typedef struct{
    TypeLiteral type;
    char *value; // knew this had to change to char for it to pass anytime soon
} TokenLiteral;

typedef struct{
    TypeSeparator type;
} TokenSeparator;

TokenLiteral *generate_number(char *current, int *current_index){
    TokenLiteral *token = malloc(sizeof(TokenLiteral));
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0;
    while(isdigit(current[*current_index]) && current[*current_index] != '\0'){
        if(!isdigit(current[*current_index])){ // did not recognize that the number was in the current
            break;
        }
        value[value_index] = current[*current_index];
        value_index++;
        current_index++;
    }
    token->value = value;
    return token;
}

TokenKeyword *generate_keyword(char *current, int *current_index){
    TokenKeyword *token = malloc(sizeof(TokenKeyword));
    char *keyword = malloc(sizeof(char) * 8);
    int keyword_index = 0;
    while(isalpha(current[*current_index]) && current[*current_index] != '\0'){
        keyword[keyword_index] = current[*current_index];
        printf("keyword: %c", current[*current_index]);
        keyword_index++;
        current_index++;
    }
    printf("\n");
    if(strcmp(keyword, "exit") == 0){
        printf("TYPE EXIT\n");
        token->type = EXIT;
    }
    return token;
}

void lexer(FILE *file){
    int length;
    char *buffer = 0;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * length);
    fread(buffer, 1, length, file);
    fclose(file);
    buffer[length + 1] = '\0'; 
    char *current = malloc(sizeof(char) * length + 1);
    current = buffer;
    int current_index = 0; 

    while(current[current_index] != '\0'){
        if(current[current_index] == ';'){
            printf("FOUND SEMICOLON\n");
        }
        else if(current[current_index] == '('){
            printf("FOUND OPEN PARENTHESES\n");
        }
        else if(current[current_index] == ')'){
            printf("FOUND CLOSE PARENTHESES\n");
        }
        //finding a way to determine nums and strings
        else if(isdigit(current[current_index])){
            TokenLiteral *test_token = generate_number(current, &current_index);
            printf("TEST TOKEN VALUE = %s\n", test_token->value);
        }
        else if(isalpha(current[current_index])){
            TokenKeyword *test_keyword = generate_keyword(current, &current_index);
        }
        current_index++;
    }
}

int main(){
    FILE *file;
    file = fopen("test.sy", "r");

    lexer(file);
}













