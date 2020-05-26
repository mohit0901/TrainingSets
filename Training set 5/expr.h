//expr.h

#include <assert.h>
struct term {
struct term *nextP;
int coeff;
int power;
};
/* Expression is a list or terms */
typedef struct term * expression;
/* Gives pointer to the first term in the expression list */
struct term *getFirstTerm (expression *prtToExpr);
/* Initialise a expression with no term */
void createExpr(expression *prtToExpr);
/* Insert a new term in expression list -- term with power should not exist
*/
void insertTerm(expression *prtToExpr, int coeff, int power);
/* Insert a new term in expression if none have exponent == power.
Otherwise add coeff to term's coefficient.
Do not forget to delete term is term's new coefficient == 0 */
void addTerm(expression *prtToExpr, int coeff, int power);
/* Gives next term in the expression after one referenced by termP */
struct term *getNextTerm(expression *prtToExpr, struct term *termP);
/* Prints the expression */
void printExpr(expression *prtToExpr);
/* Search for term with largest exponent value <= argument pow */
struct term *searchTerm(expression *prtToExpr, int pow);
/* Make a copy of src expression and make it accessible through destExpr */
void makeExprCopy(expression *srcExpr, expression *dstExpr);

