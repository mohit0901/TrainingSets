# include "deque.h"
# include <stdio.h>
# define lp '('
# define rp ')'
# define lc '{'
# define rc '}'
# define ls '['
# define rs ']'
//using deque as a stack
//using joinR(int) and leaveR
int main(void)
{
    FILE *fp;
    char ch;
    int dl;
    int flag=1;
    fp=fopen("deque.c","r");
    while(!feof(fp))
    {
        fscanf(fp,"%c\n",&ch);
        if(ch==lp||ch==lc||ch==ls)
            joinR((int)ch);
        else if(ch==rp||ch==rc||ch==rs)
        {
            if(hdr.nextR==NULL)
            {
               flag=0;
               break;
            }
            else
            {
                dl=leaveR();
                char c1=(char)dl;
                if(ch==rp&&c1!=lp)
                {
                    flag=0;
                    break;
                }
                else if(ch==rs&&c1!=ls)
                {
                    flag=0;
                    break;
                }
                else if(ch==rc&&c1!=lc)
                {
                    flag=0;
                    break;
                }
            }
        }
    }
    if(hdr.nextR!=NULL)
        flag=0;
    if(flag==1)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
    fclose(fp);
    return 0;
}
