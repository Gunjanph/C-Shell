#include "header.h"
#include "nightwatch.h"

void nightswatch(ll k)
{
	ll flag;
	if(k<4)
	{
		perror("Too Few arguments");
		printf(":'(");
	}
	else if(k == 4)
	{
		if(strcmp(inter[3],"interrupt")==0)
			flag=0;
		else if(strcmp(inter[3],"newborn")==0)
			flag=1;
		else
		{
			perror("Invalid Argument:");
			printf(":'(");
		}
	}
	else
	{
		perror("Too Many arguments");
		printf(":'(");
	}
	pid_t pid = fork();
	if(pid==0)
	{
		if(flag == 0)
		{
			FILE *fd = fopen("/proc/interrupts", "r");
			if(fd == NULL)
			{
				perror("Invalid Process id");
				printf(":'(");
			}
			else
			{
				fscanf(fd, "%[^\n]",str);
				printf("%s\n",str );
				fclose(fd);
			}
		}
		while(1)
		{
			if(flag== 0)
				interrupt();
			else if(flag==1)
				newborn();
			sleep(atoi(inter[2]));
			c=0;
		}
	}
	// while((c = getchar()) != 'q')
	// {}
	if((c = getchar()) == 'q')
		kill(pid,SIGKILL);
}
void interrupt()
{
	FILE *fd = fopen("/proc/interrupts", "r");
	if(fd == NULL)
	{
		perror("Invalid Process id");
		printf(":'(");
	}
	else
	{
		ll j=0;
		while (fgets(str, sizeof(str), fd)) 
		{ 
			if(j == 2 ) 
			{ 
				// printf("%s", str);
				break;    
			} 
			j++;
		} 
		for(ll i=0;i<strlen(str);i++)
		{
			if(str[i]=='I')
			{	
				str[i]='\0';
				break;
			}
		}
		printf("%s\n",str);
		printf(":')");
	}
	fclose(fd);
}
void newborn()
{

	FILE *fd = fopen("/proc/loadavg", "r");
	if(fd == NULL)
	{
		perror("Invalid Process id");
		printf(":'(");
	}
	else
	{
		// ll j=0;
		// c=0;
		for(ll i=0;i<5;i++)
			fscanf(fd, "%s",str);

		printf("%s\n",str);
		printf(":')");
	}
	fclose(fd);
}
