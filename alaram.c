#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
static int alarm_fired=0;
void ding(int sig)
{
	alarm_fired=1;
}
int main()
{
	pid_t pid;
	printf("\nalarm application starting\n");
	pid=fork();
	switch(pid)
	{
		case -1:
			perror("fork failed\n");
			exit(1);
		case 0:
			sleep(5);
			kill(getppid(),SIGALRM);
			exit(0);
	}
		printf("\nwaiting for alarm to go off\n");
		signal(SIGALRM,ding);
		pause();
		if(alarm_fired)printf("Ding!\n");
			printf("done\n");
		exit(0);
}
