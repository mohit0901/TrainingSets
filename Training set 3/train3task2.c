# include <stdio.h>
# include "deque.h"
int main(void)
{
    FILE *fp;
    char ch;
    fp=fopen("deque.c","r");
    printf("Characters are:\n");
    while(!feof(fp))
    {
        fscanf(fp,"%c",&ch);
        printf("%c",ch);

    }
    fclose(fp);
    return 0;
}
