//main.c

#include "srchTree.c"
int main(void) {
initTree();
insertKey(14); insertKey(17); insertKey(11);
insertKey(17);insertKey(7); insertKey(53); insertKey(4);
insertKey(13); insertKey(12); insertKey(8); insertKey(60);
printf("\n----------- INSERTIONS COMPLETED -------------\n");
if (hasKey(17))
printf("Found key 17\n");
else
printf("Not Found key 17\n");
printTree();
printf("\n--------------- BEGIN DELETIONS ------------\n");
deleteKey(60);
deleteKey(53);
deleteKey(17);
if (hasKey(17))
printf("Found key 17\n");
else
printf("Not Found key 17\n");
deleteKey(14);
/*deleteKey(11);
deleteKey(17);
deleteKey(14);
deleteKey(7);
deleteKey(60);
deleteKey(4);
deleteKey(8);
deleteKey(13);
deleteKey(12);
deleteKey(53);*/
printf("\n------------ DELETIONS COMPLETED --------------\n");
printTree();
return 0;
}
