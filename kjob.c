#include "header.h"
#include "bg.h"

void kjob(ll k)
{
	if(k>3)
	{
		perror("Too Many Arguments");
		printf(":'(");
	}
	else if(k<3)
	{
		perror("More Arguments Required");
		printf(":'(");
	}
	else
	{
		job_num = atoi(inter[1]);
		sig_num = atoi(inter[2]);
		if(curr_bg[job_num-1]==-1 || job_num>p)
		{
			perror("No such job exists");
			printf(":'(");
		}
		else
		{
			kill(pidls[job_num-1][1], sig_num);
			printf(":')");
		}
	}
}