//implementation of dlist.h

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
struct chair {
struct chair *leftChair;
char *player;
struct chair *rightChair;
};
struct chair *start=NULL;
void initDList();
void insertChair(char *player);
char *removeChair(int displacement);
char *whoInChair(int displacement);
int isEmpty();

