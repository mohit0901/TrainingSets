# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# define LPAR '('
# define RPAR ')'
# define PLUS '+'
# define MULT '*'
# define MOD '%'
# define SUB '-'
# define DIV '/'
# define FINISH '\0'
# define INT '0'
# define MAX 100
char stack[MAX];
int top=-1;
struct token
{
    char kind;
    int value;
};
char expr[100];
int where=0;
void push(char);
char pop();
char peek();
int isEmpty();
int isFull();
void initStack();
int prior(char);
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
    gets(expr);
    char ch;
    struct token token;
    int l=strlen(expr);
    expr[l]=RPAR;
    expr[l+1]='\0';//to go with algorithm
    push(LPAR);
    do
    {
        token=getNextToken();
        if(token.kind==LPAR)
            push(LPAR);
        else if(token.kind==INT)
            printf("%d ",token.value);
        else if(token.kind==RPAR)
        {
            while(peek()!=LPAR)
            {
                ch=pop();
                printf("%c ",ch);

            }
            pop();
        }
        else if(token.kind!=FINISH)
        {
            if(peek()==LPAR)
                push(token.kind);
            else
            {
                while(prior(peek())>prior(token.kind))
                {
                    ch=pop();
                    printf("%c ",ch);
                }
                push(token.kind);
            }
        }
    }while(token.kind!=FINISH);

}
void push(char val)
{
    top=top+1;
    stack[top]=val;
}
char pop()
{
    char val=stack[top];
    top=top-1;
    return val;
}
char peek()
{
    int a=isEmpty();
    if(a==1)
        printf("Stack is empty\n");
    else
        return stack[top];
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
void initStack()
{
    top=-1;
}
int prior(char ch)
{
    if(ch=='*'||ch=='/'||ch=='%')
        return 2;
    else if(ch=='+'||ch=='-')
        return 1;
    else
        return -1;

}
