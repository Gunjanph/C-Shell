#include "header.h"
#include "envvar.h"

void senv(ll k)
{
	if(k<3)
	{
		perror("Too Few Arguments");
		printf(":'(");
	}
	else if(k>3)
	{
		perror("Too Many Arguments");
		printf(":'(");
	}
	else
	{
		ll file = setenv(inter[1], inter[2], 1);
		if(file == -1)
		{
			perror("Error in setenv");
			printf(":'(");
		}
		else
			printf(":')");
	}
}

void unsenv(ll k)
{
	if(k<2)
	{
		perror("Too Few Arguments");
		printf(":'(");
	}
	else if(k>2)
	{
		perror("Too Many Arguments");
		printf(":'(");
	}
	else
	{
		ll file = unsetenv(inter[1]);
		if(file == -1)
		{
			perror("Error in unsetenv");
			printf(":'(");
		}
		else
			printf(":')");
	}
}
