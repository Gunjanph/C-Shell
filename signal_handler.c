#include "header.h"
#include "bg.h"
#include "fg.h"

void Ctrl_C(int signum)
{
	if(strcmp(command[0],"")!=0) // JUST TO LOOK GOOD
		printf("\n");
	else
		printf("\nType quit or Ctrl+d to exit the shell\n\033[0;31mJust keep entering commands\n\033[0m");
	printf(":')");
	fflush(stdout);
}

void Ctrl_Z(int signum)
{
	signal(SIGTSTP, Ctrl_Z);
	if(curr_fore[0]==1)
	{
		pidls[p][1] = child_pid;
		strcpy(list[p],inter[0]);
		printf("[%lld]+ Stopped %s\n",p+1,list[p]);
		p++;
	}
	printf(":')");
}