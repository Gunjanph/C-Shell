#include "header.h"
#include "pinfo.h"
void pinfo(ll k)
{
	pid_t pid;
	char temp[10000];
	//printf("%s\n",inter[1]);

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
	//	printf("%d\n",pid);
	}
	//printf("%d\n",pid);

	sprintf(path,"/proc/%d/stat",pid);
	sprintf(exe_path,"/proc/%d/exe",pid);

	//printf("%s\n",exe_path);

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
        //fclose(fd);
	}

	int len = readlink(exe_path,ep,1000);
	//printf("%d %s\n",len,ep);
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
					//	printf("%lld%c\n",i, present[i]);
					continue;
				}
				else
					break;
			}
		}
		if(i==strlen(old))
		{
			//printf("%s\n",present);
			strcpy(temp,"~");
			//printf("1: %s  %ld\n",temp,strlen(temp));
			ll j=1;
			for(ll k=strlen(old);k<strlen(ep);k++)
			{
				temp[j]=ep[k];
				//	printf("%c %lld %lld\n",eper[k],k,j);
					j++;
				}
				temp[j]='\0';
				//printf("%s\n",temp);
				if(temp[strlen(ep)-1]=='/')
					temp[strlen(ep)-1]='\0';
				//	printf("%s\n",new);

		}
		else
			strcpy(temp,ep);
		//printf("%s\n",temp);
		printf("Executable Path -- %s\n", temp);
		printf(":')");
	}
}
