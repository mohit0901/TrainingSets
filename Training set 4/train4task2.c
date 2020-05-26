//implementation of main.c

#include <stdio.h>
#include <stdlib.h>
#include "dlist.c"
char tmp[101];
int rollDice() {
int i = 1+rand()%6;
return i;
}
int main(void) {
char *name;
int dice;
initDList();
FILE *playerF = fopen("players.txt","r");

fgets(tmp, 100, playerF);
while (!feof(playerF)) {
// Get space filled with \0
name = calloc(1,strlen(tmp)+1);
// Newline should not copied
strncpy(name, tmp, strlen(tmp)-1);
insertChair(name);
fgets(tmp, 100, playerF);
}
printf("\nAll players are in their chairs now. Game begins\n\n");
/*while (!isEmpty()) {
printf("%s is in chair 0. ", whoInChair(0));
dice = rollDice();
if (dice%2 == 1) // Odd numbers on left!
dice *= -1;
printf("Rid chair %d. ", dice);
name = removeChair(dice);
if (isEmpty())
printf("\n\nWinner is %s\n", name);
else
printf("\nLosing player was %s.\n", name);
free(name);
}*/

//checking insertChair function
struct chair *ptr=start;
printf("The list is:\n");
while(ptr->rightChair!=start)
{
    printf("%s\n",ptr->player);
    ptr=ptr->rightChair;
}
printf("%s\n",ptr->player);
printf("\n");

//checking who in chair function

printf("Person at chair 0: %s\n",whoInChair(0));
printf("Person at chair 1: %s\n",whoInChair(1));
printf("Person at last chair: %s\n",whoInChair(-1));
printf("Person at second last chair: %s\n",whoInChair(-2));
printf("\n");
//checking isEmptyFunction
int res=isEmpty();
if(res==1)
    printf("Empty\n");
else
    printf("Not empty\n");

//checking initDList function
initDList();
res=isEmpty();
if(res==1)
    printf("Empty\n");
else
    printf("Not Empty\n");

return 0;
}



