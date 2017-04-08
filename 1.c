#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void signalhandle(int signum);
int a;
int main()
{
	signal(SIGINT,signalhandle);
	while(1)
	{
		printf("\ngoing infinite loop\n");
		sleep(2);
		if(SIGINT ==a)
		{
			printf("coming out  of loop after getting the signal Ctrl+c\n");
			break;
		}


	}
	return 0;
}
void signalhandle(int signum)
{
	signal(SIGINT, signalhandle);
	if(signum == SIGINT)
	{
		printf("\ngot out the signal %d\n",signum);
		a=signum;
	}

}
