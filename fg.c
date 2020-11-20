#include "header.h"
#include "fg.h"
#include "bg.h"

void fg(ll k)
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
		num = atoi(inter[1]);
		int status;
		if(curr_bg[num-1]==-1)
		{
			perror("No such job");
			printf(":'(");
		}
		else
		{
			signal(SIGTTIN,SIG_IGN);
            signal(SIGTTOU,SIG_IGN);
            tcsetpgrp(0,pidls[num-1][1]);
            kill(pidls[num-1][1], SIGCONT);
            curr_bg[num-1]=-1;
            waitpid(-1, &status, WUNTRACED);
            tcsetpgrp(0,getpgrp());
            signal(SIGTTOU,SIG_DFL);
            signal(SIGTTIN,SIG_DFL);
            printf(":')");
		}
	}
}