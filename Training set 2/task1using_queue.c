#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(void) {
int i, s;
init(); // Start deque
for (i=0; i< 10; i++) {
insertLeft(i*i);
s = size();
printf("Size = %d Data = %d\n", s, removeRight());
insertLeft(i*i*i);
}
while (size()>0) {
printf("Emptying deque %d\n", removeRight());
}
return 0;
}

