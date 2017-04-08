#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void ouch(int sig)
{
	printf("\nOUCH!- I got a signal %d\n",sig);
	signal(SIGINT,SIG_DFL);
}
int main()
{
	signal(SIGINT,ouch);

	while(1)
	{
		printf("Hello Satyam\n");
		sleep(2);
	}
	return 0;
}
