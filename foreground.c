#include "header.h"
#include "fg.h"

void ChildsigstopHandler(int signalCode)
{
	kill(getpid(), SIGTSTP);
}

void foreground(char * args[1024])
{
	pid_t pid;
	// strcpy(lastForegroundProc, args[0]);
	curr_fore[0] = 1;
	pid = fork();
	child_pid = pid;
	if(pid<0)
	{
		perror("Error while forking\n");
		printf(":'(");
	}
	else if(pid==0)//CHILD PROCESS
	{
		signal(SIGTSTP, ChildsigstopHandler);

		//printf("%d;%d\n",getpid(),getppid());
		// curr_fore[0] = getpid();
		int che=execvp(args[0],args);
		if(che<0)
		{
			perror("Command is not working for child");
			printf(":'(");
			exit(0);
		}
		else
			printf(":')");
		exit(0);
	}
	else
	{
		// curr_fore[0] = -1;
		//printf("%lld\n", curr_fore[0]);
		waitpid(pid, NULL, WUNTRACED);
	}
}

void runfg(ll n)
{
	char *args[1024];
	for(ll i=0;i<=n;i++)
	{
		args[i] = (char*)malloc(1024*sizeof(char));
	}
	strcpy(args[0],inter[0]);
	for(ll i=1;i<n;i++)
		strcpy(args[i],inter[i]);
	args[n]=NULL;
	foreground(args);
}
