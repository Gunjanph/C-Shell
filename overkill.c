#include "header.h"
#include "bg.h"

void overkill()
{
	ll err=0;
	for(ll i=0;i<p;i++)
	{
		if(curr_bg[i]!=-1)
		{
			ll check_kill = kill(pidls[i][1], 9);
			if(check_kill == -1)
			{
				perror("Error in killing pid");
				err=1;
			}
		}
	}
	if(err==1)
		printf(":'(");
	else
		printf(":')");
}