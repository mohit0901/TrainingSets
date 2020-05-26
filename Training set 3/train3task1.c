#include <stdio.h>
#include "deque.c"

int main(int argc, char *argv[]) {
	joinL(20);
	joinL(200);
	printf("%d\n", size());
	printf("%d \n", leaveR());
	printf("%d\n", size());
	printf("%d \n", leaveR());
	printf("%d\n", size());
	return 0;
}

