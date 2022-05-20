#include "header.h"
#include "pinfo.h"
void pinfo(ll k)
{
	pid_t pid;
	char temp[10000];

	if(k==1)
		pid = getpid();

	else if(k>2)
	{
		perror("Too Many Arguments");
		printf(":'(");
	}
	else
	{
		pid = atoi(inter[1]);
	}

	sprintf(path,"/proc/%d/stat",pid);
	sprintf(exe_path,"/proc/%d/exe",pid);

	FILE *fd = fopen(path,"r");
	if(fd == NULL)
	{
		perror("Invalid Process id");
		printf(":'(");
	}
	else
	{
		for(ll i=0;i<23;i++)
		{
			fscanf(fd, "%s", str);
			if(i==0)
				printf("pid -- %s\n",str);
			else if(i==2)
				printf("Process Status -- %s\n", str);
        	else if (i == 22)
            	printf("memory -- %s\n", str);
		}
		printf(":')");
	}

	int len = readlink(exe_path,ep,1000);
	if(len==-1)
	{
		perror("Cannot find path");
		printf(":'(");
	}
	else
	{
		ll i=0;
		ep[len] = '\0';
		if(strcmp(ep,old)==0)
			strcpy(temp,"~");
		i=-1;
		if(strlen(ep)>strlen(old))
		{
			for(i=0;i<strlen(old);i++)
			{
				if(ep[i]==old[i])
				{
					continue;
				}
				else
					break;
			}
		}
		if(i==strlen(old))
		{
			strcpy(temp,"~");
			ll j=1;
			for(ll k=strlen(old);k<strlen(ep);k++)
			{
				temp[j]=ep[k];
					j++;
				}
				temp[j]='\0';
				if(temp[strlen(ep)-1]=='/')
					temp[strlen(ep)-1]='\0';

		}
		else
			strcpy(temp,ep);
		printf("Executable Path -- %s\n", temp);
		printf(":')");
	}
}
