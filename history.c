#include "header.h"
#include "history.h"

void addhistory(char comm[1024])
{
	if(count < 20)
	{
		if(count!=0 && strcmp(history[count-1],comm)!=0)
		{
			strcpy(history[count],comm);
			count++;
		}
		else if(count==0)
		{
			strcpy(history[count],comm);
			count++;
		}
	}
	else
	{
		if(strcmp(history[18],comm)!=0)
		{
			for(ll i=1;i<20;i++)
			{
				strcpy(history[i-1],history[i]);
			}
			strcpy(history[19],comm);
			count++;
		}
	}
}

void hist(ll k)
{
	ll n = 10;
	if(k==2)
		n = atoi(inter[1]);
	if(count>=20)
	{
		for(ll i=20-n;i<=19;i++)
			printf("%s\n",history[i]);
		printf(":')");
	}
	else
	{
		if(n==10 && n>count)
			n=count;
		if(n>count || n>20)
		{
			perror("Too much arguments asked for");
			printf(":'(");
		}
		else
		{
			for(ll i=count-n;i<count;i++)
				printf("%s\n",history[i]);
			printf(":')");
		}
	}
}