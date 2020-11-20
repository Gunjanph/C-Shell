#include "header.h"
#include "bg.h"

void bg(ll k)
{
	if(k>2)
	{
		perror("Too Many Arguments");
		printf(":'(");
	}
	else if(k<2)
	{
		perror("Too Few Arguments");
		printf(":'(");
	}
	else
	{
		bg_num = atoi(inter[1]);
		if(curr_bg[bg_num-1]==-1)
		{
			perror("No such job");
			printf(":'(");
		}
		else
		{
			kill(pidls[bg_num-1][1], SIGCONT);
			printf(":')");
		}
	}
}
