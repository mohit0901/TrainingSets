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
while (!isEmpty()) {
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
}
return 0;
}


