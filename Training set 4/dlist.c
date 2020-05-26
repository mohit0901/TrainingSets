//implementation of dlist.c

# include "dlist.h"
# include <math.h>
void initDList()
{
    start=NULL;
}
void insertChair(char *player)
{
    //printf("Not implemented\n"); - task 1
    /* Create a new chair for a player. Add it to the
list. Terminate prog if memory not available
*/
// task 2
    struct chair *newnode;
    newnode=(struct chair *)malloc(sizeof(struct chair));
    assert(newnode!=NULL);
    newnode->player=player;
    if(start==NULL)
    {
       start=newnode;
       newnode->leftChair=start;
       newnode->rightChair=start;
    }
    else
    {
        struct chair *ptr;
        ptr=start;
        while(ptr->rightChair!=start)
        {
            ptr=ptr->rightChair;
        }
        ptr->rightChair=newnode;
        newnode->leftChair=ptr;
        newnode->rightChair=start;
        start->leftChair=newnode;
    }
}
char *removeChair(int displacement)
{
    //printf("Not implemented\n"); - task 1 and task 2
    /* Free person name string and chair too.
    Count the fisrt pointed chair as numbered 0.
    Displacement can be positive or negative from
    chair 0. Player pointer should not be NULL.
    */
    //task 3
    struct chair *ptr;
    ptr=start;
    int co=0;
    char *name;
    if(displacement>0)
    {
        while(co!=displacement)
        {
            ptr=ptr->rightChair;
            co++;
        }
        if(ptr==start&&ptr->rightChair!=ptr)
        {
            start->leftChair->rightChair=start->rightChair;
            start->rightChair->leftChair=start->leftChair;
            start=start->rightChair;
            name=ptr->player;
            free(ptr);
        }
        else if(ptr->rightChair==ptr)
        {
            name=ptr->player;
            start=NULL;
            free(ptr);
        }
        else
        {
            ptr->leftChair->rightChair=ptr->rightChair;
            ptr->rightChair->leftChair=ptr->leftChair;
            name=ptr->player;
            free(ptr);
        }
    }
    else
    {
        displacement=abs(displacement);
        while(co!=displacement)
        {
            ptr=ptr->leftChair;
            co++;
        }
        if(ptr==start&&ptr->rightChair!=ptr)
        {
            start->leftChair->rightChair=start->rightChair;
            start->rightChair->leftChair=start->leftChair;
            start=start->leftChair;
            name=ptr->player;
            free(ptr);
        }
        else if(ptr->leftChair==ptr)
        {
            name=ptr->player;
            start=NULL;
            free(ptr);
        }
        else
        {
            ptr->leftChair->rightChair=ptr->rightChair;
            ptr->rightChair->leftChair=ptr->leftChair;
            name=ptr->player;
            free(ptr);
        }
    }
    return name;
}
char *whoInChair(int displacement)
{
    //printf("Not implemented\n"); - task 1

    //task 2
     assert(start!=NULL);
    struct chair *ptr=start;
    if(displacement==0)
        return start->player;
    else if(displacement>0)
    {
        int co=0;
        while(co!=displacement)
        {
            ptr=ptr->rightChair;
            co++;
        }
        return ptr->player;
    }
    else
    {
        displacement=abs(displacement);
        int co=0;
        while(co!=displacement)
        {
            ptr=ptr->leftChair;
            co++;
        }
        return ptr->player;
    }
}
int isEmpty()
{
    if(start==NULL)
        return 1;
    else
        return 0;
}
