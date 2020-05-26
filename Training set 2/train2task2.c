//training set 2_task 2
# include "queue.h"
# include <stdio.h>
void main()
{
    int i,j,res;
    //initially filling the queue with numbers from 2 to 10
    for(i=2;i<=99999;i++)
        joinQ(i);
    joinQ(0);
    i=2;
    while(i<=99999)
    {
        while(data[left]!=0)
        {
            res=leaveQ();
            if(res==i||res%i!=0)
                joinQ(res);
        }
        i=i+1;
        leaveQ();
        joinQ(0);
    }
    printf("Prime numbers are: \n");
    int co=0;
    while(data[left]!=0)
    {
        co++;
        res=leaveQ();
        printf("%d\n",res);
    }
    printf("Prime numbers are: %d\n",co);

}
