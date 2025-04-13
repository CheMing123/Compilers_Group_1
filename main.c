#include <stdio.h>
#include <stdlib.h>

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

typedef struct {
    TypeSeparator type;
} TokenSeparator;

int main(){
    FILE *file;
    file = fopen("test.sy", "r");
    char current = fgetc(file);

    while(current != EOF){
        printf("%c", current);
        current = fgetc(file);
    }
}
