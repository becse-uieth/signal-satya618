#include"header.h"
void ouch(int);
int main()
{
        printf("hello satyam\n");
        printf("parent pid =%d\n",getppid());
        printf("child pid =%d\n",getpid());
        kill(getppid(),SIGALRM);
        printf("signal passed\n");
        return 0;
}  
