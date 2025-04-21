#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum{
    INT,
    KEYWORD,
    SEPARATOR,
} TokenType;

typedef struct{
    TokenType type;
    char *value;
} Token;

void print_token(Token token){
    for(int i = 0; token.value[i] != '\0'; i++){
        printf("%c", token.value[i]);
    }
    printf("\n");
    if(token.type == INT){
        printf("TOKEN TYPE: INT\n");
    }    
    else if(token.type == KEYWORD){
        printf("TOKEN TYPE: KEYWORD\n");
    }
    else if(token.type == SEPARATOR){
        printf("TOKEN TYPE: SEPARATOR\n");
    }
}

Token *generate_number(char *current, int *current_index){
    Token *token = malloc(sizeof(Token));
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0;
    while(isdigit(current[*current_index]) && current[*current_index] != '\0'){
        if(!isdigit(current[*current_index])){ // did not recognize that the number was in the current
            break;
        }
        value[value_index] = current[*current_index];
        value_index++;
        *current_index += 1;
    }
    value[value_index] = '\0';
    token->value = value;
    return token;
}

Token *generate_keyword(char *current, int *current_index){
    Token *token = malloc(sizeof(Token));
    char *keyword = malloc(sizeof(char) * 8);
    int keyword_index = 0;
    while(isalpha(current[*current_index]) && current[*current_index] != '\0'){
        keyword[keyword_index] = current[*current_index];
        keyword_index++;
        *current_index += 1;
    }
    keyword[keyword_index] = '\0';
    if(strcmp(keyword, "exit") == 0){
        printf("TYPE EXIT\n");
        token->type = KEYWORD;
        token->value = "EXIT";
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
        else if(isdigit(current[current_index])){
            Token *test_token = generate_number(current, &current_index);
            current_index--;
            printf("TEST TOKEN VALUE: %s\n", test_token->value);
        }
        else if(isalpha(current[current_index])){
            Token *test_keyword = generate_keyword(current, &current_index);
            print_token(*test_keyword);
            current_index--;
        }
        current_index++;
    }
}

int main(){
    FILE *file;
    file = fopen("test.sy", "r");

    lexer(file);
}













