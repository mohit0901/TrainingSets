#include "queue.h"
void joinQ(int val)
{
    insertRight(val);
}
int leaveQ()
{
    int res;
    res=removeLeft();
    return res;
}
