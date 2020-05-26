//srchTree.h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
int key;
int height;
int depth;
struct node *left;
struct node *right;
};
void initTree();
void insertKey(int key);
void deleteKey(int key);
int hasKey(int key);
void setDepths();
void setHeights();
void printTree();
