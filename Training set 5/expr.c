//expr.c

#include "expr.h"
#include <stdio.h>
#include <stdlib.h>
/* Gives pointer to the first term in the expression list */
struct term *getFirstTerm (expression *ptrToExpr) {
assert(ptrToExpr!=NULL);
assert(*ptrToExpr!=NULL);
return (*ptrToExpr)->nextP;
}
/* Initialise a expression with no term */
void createExpr(expression *ptrToExpr) {
assert(ptrToExpr!=NULL);
(*ptrToExpr) = malloc(sizeof(struct term));
(*ptrToExpr)->nextP = NULL;
}
/* Insert a new term in expression list -- term with power should not exist
*/
void insertTerm(expression *ptrToExpr, int coeff, int power) {
struct term *ptr, *prev;
struct term *newTerm = malloc(sizeof(struct term));
newTerm->coeff = coeff;
newTerm->power = power;
ptr = getFirstTerm(ptrToExpr);
prev = *ptrToExpr;
/* Notice that ptr is used only if not NULL */
while (ptr != NULL && power < ptr->power) {
// Find the right location for new node
prev = ptr;
ptr = getNextTerm(ptrToExpr, ptr);
}
assert(ptr == NULL || ptr->power != power);
newTerm->nextP = ptr;
prev->nextP = newTerm;
}
/* Gives next term in the expression after one referenced by termP */
struct term *getNextTerm(expression *ptrToExpr, struct term *termP) {
assert(termP != NULL);
return termP->nextP;
}
/* Available here but not through expr.h */
static void printTerm(struct term *term) {
printf("%+d*X^%d ", term->coeff,term->power);
}
/* Prints the expression */
void printExpr(expression *ptrToExpr) {
struct term *prnt = getFirstTerm(ptrToExpr);
if(*ptrToExpr==NULL)
    printf("Expression is empty\n");
while (prnt!=NULL){
printTerm(prnt);
prnt = getNextTerm(ptrToExpr, prnt);
}
printf("\n");
}
/* Search for term with largest exponent value <= argument pow */
struct term *searchTerm(expression *prtToExpr, int pow)
{
    struct term *ptr,*prev;
    ptr=getFirstTerm(prtToExpr);
    assert(ptr!=NULL);
    while(ptr->power>pow)
    {
        ptr=getNextTerm(prtToExpr,ptr);
        if(ptr==NULL)
            return NULL;
    }
    return ptr;

}
/* Insert a new term in expression if none have exponent == power.
Otherwise add coeff to term's coefficient.
Do not forget to delete term is term's new coefficient == 0 */
void addTerm(expression *prtToExpr, int coeff, int power)
{
    //prtToExpression is a pointer storing address of another pointer
    struct term *ptr,*prev;
    ptr=getFirstTerm(prtToExpr);
    prev=ptr;
    while(ptr->power>power)
    {
        prev=ptr;
        ptr=getNextTerm(prtToExpr,ptr);
        if(ptr==NULL)
            break;
    }
    if(prev!=ptr)
    {
        struct term *newterm;
        newterm=(struct term *)malloc(sizeof(struct term));
        newterm->power=power;
        newterm->coeff=coeff;
        if(ptr!=NULL&&ptr->power==power)
        {
            if(ptr->coeff+coeff!=0)
            {
                ptr->coeff=ptr->coeff+coeff;
            }
            else
            {
                if(ptr==NULL)
                    prev->nextP=NULL;
                else
                {
                    prev->nextP=ptr->nextP;
                    free(ptr);
                }

            }
        }
        else
        {
            prev->nextP=newterm;
            newterm->nextP=ptr;
        }
    }
    else
    {
        if(ptr->power==power)
        {
            if(ptr->coeff+coeff!=0)
            {
                ptr->coeff=ptr->coeff+coeff;
            }
            else
            {
                struct term *newmem;
                newmem=(struct term *)malloc(sizeof(struct term));
                newmem->nextP=ptr->nextP;
                *prtToExpr=newmem;
                free(ptr);
            }
        }
        else
        {
            struct term *newterm;
            newterm=(struct term *)malloc(sizeof(struct term));
            newterm->coeff=coeff;
            newterm->power=power;
            newterm->nextP=ptr;
            struct term *newmem;
                newmem=(struct term *)malloc(sizeof(struct term));
                newmem->nextP=newterm;
                *prtToExpr=newmem;
        }
    }
}
/* Make a copy of src expression and make it accessible through destExpr */
void makeExprCopy(expression *srcExpr, expression *dstExpr)
{
    struct term *ptr;
    if((*srcExpr)->nextP==NULL)
        printf("Source expression empty cannot copy\n");
    else
    {
        ptr=getFirstTerm(srcExpr);
        while(ptr!=NULL)
        {
            insertTerm(dstExpr,ptr->coeff,ptr->power);
            ptr=getNextTerm(srcExpr,ptr);
        }
    }
}
