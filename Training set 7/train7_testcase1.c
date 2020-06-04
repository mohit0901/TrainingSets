#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
char town[] = "VILL: RUPA KI NANGAL";
struct Huff {
int freq;
char alpha;
struct Huff *left;
struct Huff *right;
struct Huff *parent;
};
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int freq[] = {21912, 16587, 14810, 14003, 13318, 12666,
11450, 10977, 10795, 7874, 7253, 5246, 4943,
4761, 4200, 3853, 3819, 3693, 3316, 2715,
2019, 1257, 315, 205, 188, 128 };
/* Other test cases
int freq[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,
14,15,16,17,18,19,20,21,22,23,24,25,26};
int freq[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1};*/
/*int freq[] = {3,0,0,0,0,0,1,0,2,0,2,3,0,2,0,1,0,
1,0,0,1,1,0,0,0,0};*/

struct Huff alphabet[26]; // Fixed array to store letters
// References to nodes awaiting to be in Huffman tree
// Roots of trees in a forest
struct Huff *heap[30];
// and count of entries in heap
int heapSz = 0; // index 0 is not used in this heap
// To re-establish heap property after an insertion
void heapifyUp(int index);
// To re-establish heap property after a deletion
void heapifyDown(int index);
void initAlphaNodes(void) {
/* Fill freq data in array alphabet
Alphabets are nodes outside our Huffman tree
Leaf nodes in the heap will have
reference to these entities in their
*/
int i;
for (i=0; i<26; i++) {
alphabet[i].alpha = letters[i];
alphabet[i].freq = freq[i];
alphabet[i].left = NULL;
alphabet[i].right = NULL;
}
}
struct Huff *makeHuffNode(int freq, struct Huff *left,
struct Huff *right) {
struct Huff *newNode = malloc(sizeof(struct Huff));
assert(newNode != NULL);
// Will use this to keep coding information
newNode->alpha = ' ';
newNode->freq = freq;
newNode->right = right;
newNode->left = left;
if (left != NULL) {
left->parent = newNode;
// If not pointing to an entry in array alphabet
if (left->alpha == ' ')
left->alpha = '0';
}
if (right != NULL) {
right->parent = newNode;
right->alpha = '1';
}
return newNode;
}
void addToHeap(struct Huff *newNode) {
assert(heapSz < 30);
heap[++heapSz] = newNode;
heapifyUp(heapSz); // Restore heap property
}
struct Huff *removeMin(void) {
assert(heapSz>1);
struct Huff *tmp = heap[1];
heap[1] = heap[heapSz--];
heapifyDown(1); // Restore heap property
return tmp;
}
void initHeapLeaves(void) {
int i;
for (i=0; i<26; i++) {
addToHeap(makeHuffNode(alphabet[i].freq, &alphabet[i], NULL));
}
}
void swapAtIdx(int x, int y) {
/* Used by heapify functions */
struct Huff *tmp;
tmp = heap[x];
heap[x] = heap[y];
heap[y] = tmp;
}
void heapifyUp(int index)
{
/* Removed about 10 lines of code
See Figure 27.7 in Reema Thareja textbook */
if(index<=1)
    return;
if(heap[index]->freq>heap[index/2]->freq)
    return;
swapAtIdx(index/2,index);
heapifyUp(index/2);
return;
}
void heapifyDown(int index) {
/* Removed 10 to 15 lines of code
See Figure 12.10 in Reema Thareja */
int left_child=2*index;
int right_child=left_child+1;
if(left_child>heapSz)
    return;
if(right_child>heapSz)
{
    if(heap[index]->freq>heap[left_child]->freq)
        swapAtIdx(index,left_child);
    return;
}
if((heap[index]->freq>heap[left_child]->freq) && (heap[index]->freq>heap[right_child]->freq))
{
    if(heap[left_child]->freq < heap[right_child]->freq)
    {
        swapAtIdx(index,left_child);
        heapifyDown(left_child);
    }
    else
    {
        swapAtIdx(index,right_child);
        heapifyDown(right_child);
    }

}
else if(heap[left_child]->freq<heap[index]->freq)
{
    swapAtIdx(index,left_child);
    heapifyDown(left_child);
}
else if(heap[right_child]->freq<heap[index]->freq)
{
    swapAtIdx(index,right_child);
    heapifyDown(right_child);
}
return;
}
int heapIsRootOnly(void) { // Huffman tree is ready?
return heapSz == 1;
}
void printLetterCode(char c) {
int i = c-'A';
struct Huff *bit = alphabet[i].parent;
while (bit != NULL) {
printf("%c", bit->alpha);
bit = bit->parent;
}
}
int main(void) {
struct Huff *left, *right, *newNode, *node;
int i;
initAlphaNodes();
initHeapLeaves();
while (!heapIsRootOnly()) {
left = removeMin();
if (heapIsRootOnly()) {
right = heap[1];
heap[1] =
makeHuffNode(left->freq+right->freq, left, right);
break;
}
right = removeMin();
addToHeap(makeHuffNode(left->freq+right->freq,
left, right));
}
/* Code town */
printf("Words in %s are coded as follows\n", town);
i =-1;
while (town[++i] != '\0')
if (isspace(town[i]))
printf("\n");
else if (!isupper(town[i]))
printf("\n%c", town[i]);
else
printLetterCode(town[i]);
}



