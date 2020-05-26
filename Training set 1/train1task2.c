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
int stack[MAX];
int top=-1;
struct token
{
    char kind;
    int value;
};
char expr[100];
int where=0;
void push(int);
int pop();
int peek();
int isEmpty();
int isFull();
void initStack();
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
    int res;
    printf("Enter expression: ");
    gets(expr);
    struct token token;
     token=getNextToken();
    while(token.kind!=FINISH)
    {

        if(token.kind==INT)
        {
            push(token.value);
        }
        else if(token.kind!=FINISH)
        {
            int A=pop();
            int B=pop();
            if(token.kind==PLUS)
                push(B+A);
            else if(token.kind==MULT)
                push(B*A);
            else if(token.kind==MOD)
                push(B%A);
            else if(token.kind==SUB)
                push(B-A);
            else if(token.kind==DIV)
                push(B/A);
        }
        token=getNextToken();

    }
    res=stack[top];
    printf("Value of postfix expression is: %d",res);
}
void push(int val)
{
    top=top+1;
    stack[top]=val;
}
int pop()
{
    int val=stack[top];
    top=top-1;
    return val;
}
int peek()
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
