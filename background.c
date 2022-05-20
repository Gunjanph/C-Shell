#include "header.h"
#include "bg.h"

void pidover()
{
	int status=0;
	int cpid,exst;
	for(ll i=0;i<p;i++)
	{
		if(curr_bg[i]!=-1)
		{
			cpid = waitpid(pidls[i][1], &status, WNOHANG);
			if(cpid == pidls[i][1] || cpid<0)
			{
				exst = WEXITSTATUS(status);
				if(cpid<0 || WIFEXITED(status))
					printf("\n%s with pid %lld exited normally\n",list[i],pidls[i][1]);
				else
					printf("\n%s with pid %lld exited abnormally\n",list[i],pidls[i][1]);
		 		curr_bg[i]=-1;
			}
		}
	}
}
void background(char * args[1024])
{	
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		perror("Error while forking");
		printf(":'(");
	}
	else if(pid==0)     //CHILD PROCESS
	{
		setpgid(0,0);
		execvp(args[0],args);
		if(execvp(args[0],args)<0)
		{
			perror("Command is not working for child");
		}
		exit(1);
	}
	else
	{
		setpgid(pid,pid);
		pidls[p][1] = pid;
		strcpy(list[p],args[0]);
		printf("[%lld] %d\n",p+1,pid);
		printf(":')");
		p++;
	}
}
void runbg(ll n)
{
	char *args[1024];
	for(ll i=0;i<=n;i++)
	{
		args[i] = (char*)malloc(1000*sizeof(char));
	}
	strcpy(args[0],inter[0]);
	for(ll i=1;i<n-1;i++)
	{
		strcpy(args[i],inter[i]);
	}
	args[n-1]=NULL;
	background(args);
}
