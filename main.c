#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // to use isaplpha, to check if number is alphanumeric

typedef enum{
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
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

typedef struct {
    TypeLiteral type;
    int value;
} TokenLiteral;

void lexer(FILE *file){
    char current = fgetc(file);

    while(current != EOF){
        if(current == ';'){
            printf("FOUND SEMICOLON\n");
        }
        else if(current == '('){
            printf("FOUND OPEN PARENTHESES\n");
        }
        else if(current == ')'){
            printf("FOUND CLOSED PARENTHESES\n");
        }
        else if(isdigit(current)){
            printf("FOUND DIGIT: %d\n", current);
        }
        current = fgetc(file);
    }
}

typedef struct {
    TypeSeparator type;
} TokenSeparator;

int main(){
    FILE *file;
    file = fopen("test.sy", "r");
    lexer(file);
}
