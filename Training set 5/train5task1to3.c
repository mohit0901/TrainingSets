//main.c

#include <stdio.h>
#include <stdlib.h>
#include "expr.c"
expression expr1;
expression expr2;
expression result;
struct term *term1P, *term2P;

int main(void) {
/* Construct expression 1 */
createExpr(&expr1); // Get the start pointer set
insertTerm(&expr1, 10, 1000);
insertTerm(&expr1, 100, 2000);
insertTerm(&expr1, -10, 500);
insertTerm(&expr1, -10, -1000);
printf("Expression_1 = ");
printExpr(&expr1);
/* Construct expression 2 */
createExpr(&expr2); // Get the start pointer set
insertTerm(&expr2, 10, 1000);
insertTerm(&expr2, 200, 3000);
insertTerm(&expr2, 110, 500);
insertTerm(&expr2, 1000, 0);
insertTerm(&expr2, 10, -1000);
printf("Expression_2 = ");
printExpr(&expr2);
/* Construct result = expr1 + expr2 */
/*createExpr(&result);
term1P = getFirstTerm(&expr1);
term2P = getFirstTerm(&expr2);
while (term1P!=NULL || term2P!=NULL) {
if (term1P == NULL) {
insertTerm(&result, term2P->coeff, term2P->power);
term2P = getNextTerm(&expr2, term2P);
continue;
}
if (term2P == NULL) {
insertTerm(&result, term1P->coeff, term1P->power);
term1P = getNextTerm(&expr1, term1P);
continue;
}
if (term1P->power == term2P->power) {
        if (term1P->coeff+term2P->coeff!=0)
insertTerm(&result,

term1P->coeff+term2P->coeff, term2P->power);

term2P = getNextTerm(&expr2, term2P);
term1P = getNextTerm(&expr1, term1P);
continue;
}
if (term1P->power > term2P->power) {
insertTerm(&result, term1P->coeff, term1P->power);
term1P = getNextTerm(&expr1, term1P);
continue;
}
if (term1P->power < term2P->power) {
insertTerm(&result, term2P->coeff, term2P->power);
term2P = getNextTerm(&expr2, term2P);
continue;
}
}
printf("Expression_1 + Expression_2 = ");
printExpr(&result);
printf("\n");
//code for subtraction of two polynomials
createExpr(&result);
term1P = getFirstTerm(&expr1);
term2P = getFirstTerm(&expr2);
while (term1P!=NULL || term2P!=NULL) {
if (term1P == NULL) {
insertTerm(&result, -term2P->coeff, term2P->power);
term2P = getNextTerm(&expr2, term2P);
continue;
}
if (term2P == NULL) {
insertTerm(&result, term1P->coeff, term1P->power);
term1P = getNextTerm(&expr1, term1P);
continue;
}
if (term1P->power == term2P->power) {
        if (term1P->coeff-term2P->coeff!=0)
insertTerm(&result,

term1P->coeff-term2P->coeff, term2P->power);

term2P = getNextTerm(&expr2, term2P);
term1P = getNextTerm(&expr1, term1P);
continue;
}
if (term1P->power > term2P->power) {
insertTerm(&result, term1P->coeff, term1P->power);
term1P = getNextTerm(&expr1, term1P);
continue;
}
if (term1P->power < term2P->power) {
insertTerm(&result, -term2P->coeff, term2P->power);
term2P = getNextTerm(&expr2, term2P);
continue;
}
}
printf("Expression_1 - Expression_2 = ");
printExpr(&result);
printf("\n");
//using searchTerm function
/*struct term *result=searchTerm(&expr2,-1000);
if(result==NULL)
    printf("Term not found\n");
else
{
    printf("The term is : \n");
    printf("Coefficient is: %d\n",result->coeff);
    printf("Power is: %d\n",result->power);
}*/

//checking add term function

//addTerm(&expr1, -100, 2000);
/*addTerm(&expr1,200,2000);
addTerm(&expr1,20,1000);
addTerm(&expr1,-100,500);
//addTerm(&expr1,-20,-1000);
addTerm(&expr1,-90,-2000);
addTerm(&expr1,+90,-2000);
addTerm(&expr1,110,500);
addTerm(&expr1,-30,1000);
addTerm(&expr1,-300,2000);
addTerm(&expr1,200,4000);
addTerm(&expr1,10,-1000);
//printExpr(&expr1);
//addTerm(&expr1, -100, 2000);
printf("Expression 1 is:\n");
printExpr(&expr1);*/


//testing copy function

/*expression expr3;
createExpr(&expr3);
makeExprCopy(&expr1,&expr3);
printf("expression 1 is: \n");
printExpr(&expr1);
printf("expression 3 is: \n");
printExpr(&expr3);
expression expr4;
createExpr(&expr4);
makeExprCopy(&expr4,&expr3);
printf("\n");*/

//adding two polynomials using addTerm and makeExprcopy
printf("\n");
createExpr(&result);
makeExprCopy(&expr1,&result);
term2P = getFirstTerm(&expr2);
while(term2P!=NULL)
{
    addTerm(&result,term2P->coeff,term2P->power);
    term2P=getNextTerm(&expr2,term2P);
}
printf("expression 1 + expression 2 : \n");
printExpr(&result);
//implementing subtraction using add term and copy function
printf("\n");
createExpr(&result);
makeExprCopy(&expr1,&result);
term2P = getFirstTerm(&expr2);
while(term2P!=NULL)
{
    addTerm(&result,-term2P->coeff,term2P->power);
    term2P=getNextTerm(&expr2,term2P);
}
printf("expression 1 - expression 2 : \n");
printExpr(&result);

return 0;
}
