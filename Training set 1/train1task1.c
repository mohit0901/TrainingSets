# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# define LPAR '('
# define RPAR ')'
# define PLUS '+'
# define MULT '*'
# define MOD '%'
# define SUB '-'
# define DIV '/'
# define FINISH '\0'
# define INT '0'
struct token
{
    char kind;
    int value;
};
char expr[100];
int where=0;
void skipDigits()
{
    while(isdigit(expr[where]))
        where++;
}
void skipWhite()
{
    while(isspace(expr[where]))
        where++;
}
struct token getNextToken()
{
    struct token token;
    skipWhite();
    if(isdigit(expr[where]))
    {
        sscanf(&expr[where],"%d",&token.value);
        token.kind='0';
        skipDigits();
    }
    else if(expr[where]=='\0')
        token.kind=FINISH;
    else
    {
        token.kind=expr[where];
        where++;
    }
    return token;
}
void main()
{
    printf("Enter expression: ");
    gets(expr); //fgets ( expr,100,stdin);
    struct token token;
     token=getNextToken();
    while(token.kind!=FINISH)
       {
        printf("%c",token.kind);
        if(token.kind==INT)
        {
            printf(" %d",token.value);
        }
        printf("\n");
         token=getNextToken();
       }
}
