//srchTree.c

#include "srchTree.h"
#include <assert.h>
#include <string.h>
#define SCRN_WIDTH 100
#define OFFSET 9
struct node *theTree;
int STEP;
static struct node *makeNode(int key) {
struct node *new = malloc(sizeof(struct node));
assert(new != NULL);
new->left = new->right = NULL;
new->key = key;
new->height = 0;
new->depth = 0;
return new;
}
void initTree() {
theTree = NULL;
}
static int find(int key, struct node *t) {
if (t == NULL)
return 0;
if (t->key == key)
return 1;
if (t->key > key)
return find(key, t->left);
else
return find(key, t->right);
}
int hasKey(int key) {
return find(key, theTree);
}
static struct node *insert(int key, struct node *tree) {
struct node *t;
if (tree == NULL) {
t = makeNode(key);
return t;
}
if(!hasKey(key))
{
    if(key<tree->key&&tree->left==NULL)
    {
        t=makeNode(key);
        tree->left=t;
    }
    else if(key>tree->key&&tree->right==NULL)
    {
        t=makeNode(key);
        tree->right=t;
    }
    else if(key<tree->key)
    {
        insert(key,tree->left);
    }
    else if(key>tree->key)
    {
        insert(key,tree->right);
    }
    return tree;

}
else
    return tree;

}
void insertKey(int key) {
theTree = insert(key, theTree);
}
static int setNodeHeights(struct node *tree) {
int lh, rh;
if (tree == NULL)
return 0;
lh = setNodeHeights(tree->left)+1;
rh = setNodeHeights(tree->right)+1;
tree->height = lh>rh?lh:rh;
return tree->height;
}
void setHeights() {
theTree->height = setNodeHeights(theTree);
}
static void setNodeDepths(struct node *tree, int depth) {
if (tree == NULL)
return;
tree->depth = depth+1;
setNodeDepths(tree->left, tree->depth);
setNodeDepths(tree->right, tree->depth);
}
void setDepths() {
setNodeDepths(theTree, 0);
}
static int graftReplacementKey(struct node *tree) {
struct node *parent;
int replacementKey;
assert(tree != NULL);
while (tree->right != NULL) {
parent = tree;
tree = tree->right;
}
replacementKey = tree->key;
parent->right = tree->left;
free(tree);
return replacementKey;
}
static struct node * deleteNode(int key, struct node *tree) {
struct node * tmp;
int replacementKey;
if (tree == NULL)
return tree;
if (tree->key > key) {
tree->left = deleteNode(key, tree->left);
return tree;
} else if (tree->key < key) {
tree->right = deleteNode(key, tree->right);
return tree;
}
/* The remaining case when node is deleted */
assert(tree->key == key);
/* TASK 03
ABOUT 30 LINES OF CODE REMOVED
*/
if(tree->left==NULL&&tree->right==NULL)
{
    free(tree);
    return NULL;
}
else if(tree->left!=NULL && tree->right==NULL)
{
    struct node *ptr;
    ptr=tree;
    free(tree);
    return ptr->left;
}
else if(tree->right!=NULL && tree->left==NULL)
{
    struct node *ptr;
    ptr=tree;
    free(tree);
    return ptr->right;
}
else
{
    tree->key = graftReplacementKey(tree->left);
    if(tree->left->left==NULL)
        tree->left=NULL;
}
return tree;
}
void deleteKey(int key) {
theTree = deleteNode(key, theTree);
}
static void printNode(struct node *tree, int spaces,char ch) {
if (tree == NULL) {
//printf("\n");
return;
}
while (spaces-->0)
printf(" ");
printf("%d%c\n", tree->key,ch);
}
static void printWell(struct node *tree, int spaces,char ch) {
if (tree == NULL) {
printNode(NULL, spaces,'\0');
return;
}
printWell(tree->right,spaces+STEP,'R');
printNode(tree,spaces,ch);
printWell(tree->left,spaces+STEP,'L');

}
void printTree() {
int i;
if (theTree == NULL) {
printf("START----> NULL\n");
return;
}
setHeights();
setDepths();
STEP = SCRN_WIDTH/theTree->height;
if (STEP>9)
STEP = 9;
printf("\n");
printWell(theTree->right, OFFSET+STEP,'R');
printf("START -> %droot\n", theTree->key);
printWell(theTree->left, OFFSET+STEP,'L');
}
