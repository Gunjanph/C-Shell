// ASSUMPTION ~ DOESN'T EXIST IN BETWEEN COMMAND LINE, CAN ONLY EXISTS AT STARTING
#include "header.h"
#include "cd.h"

void last_dir(char lastdir[1024])
{
	char currdir[1024];
	getcwd(currdir,1024);
	if(strcmp(lastdir,currdir)!=0)
	{
		strcpy(dir[0],lastdir);
		strcpy(dir[1],currdir);
	}
}
void cd(char arr[1024])
{
	if(strcmp(arr,"..")==0)
	{
		if(chdir(arr)!=0)
		{
			perror("failed to do cd command");
			printf(":'(");
		}
		else
		{
			ll i=0;
			getcwd(newer,1000);
			if(strlen(newer)>=strlen(old))
			{
				for(i=0;i<strlen(old);i++)
				{
					if(newer[i]==old[i])
					{
						continue;
					}
					else
					{
						break;
					}
				}
			}
			if(i==strlen(old))
			{
				ll j=0;
				for(ll k=strlen(old);k<strlen(newer);k++)
				{
					new[j]=newer[k];
					j++;
				}
				new[j]='\0';
				if(new[strlen(new)-1]=='/')
					new[strlen(new)-1]='\0';
			}
			else
			{
				getcwd(new,1000);
			}
			printf(":')");
		}
	}
	else if(strcmp(arr,".")==0)
	{
		getcwd(new,1000);
		printf(":')");
	}
	else if(strcmp(arr,"-")==0)
	{
		printf("%s\n",dir[0]);
		chdir(dir[0]);
		getcwd(new,1024);
		printf(":')");
	}
	else if(strcmp(arr,"~")==0)
	{
		strcpy(new,old);
		chdir(old);
		printf(":')");
	}
	else
	{
		if(arr[0]=='~')
		{
			strcpy(newer,old);
			ll j=strlen(newer);
			for(ll i=1;i<strlen(arr);i++)
			{
				newer[j]=arr[i];
				j++;
			}
			newer[j]='\0';
			if(chdir(newer)!=0)
			{
				perror("failed to do cd command");
				printf(":'(");
			}
			else
			{
				ll i=0;
				getcwd(newer,1024);
				if(strlen(newer)>=strlen(old))
				{
					for(i=0;i<strlen(old);i++)
					{
						if(newer[i]==old[i])
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}
				if(i==strlen(old))
				{
					ll j=0;
					for(ll k=strlen(old);k<strlen(newer);k++)
					{
						new[j]=newer[k];
						j++;
					}
					new[j]='\0';
					if(new[strlen(new)-1]=='/')
						new[strlen(new)-1]='\0';
				}
				else
				{
					strcpy(new,newer);
				}
				printf(":')");
			}
		}
		else
		{
			ll i=0;
			char present[10000];
			getcwd(present,1000);
			strcpy(temp1,present);
			strcat(temp1,"/");
			if(arr[0]!='/')
				strcat(temp1,arr);
			else
				strcpy(temp1,arr);
			if(chdir(temp1)!=0)
			{
				perror("failed to do cd command");
				printf(":'(");
			}
			else
			{
			getcwd(temp2,1000);
			if(strlen(temp2)>strlen(old))
			{
				for(i=0;i<strlen(old);i++)
				{
					if(temp2[i]==old[i])
					{
						continue;
					}
					else
					{
						break;
					}
				}
			}
			if(i==strlen(old))
			{
				ll j=0;
				for(ll k=strlen(old);k<strlen(temp2);k++)
				{
					new[j]=temp2[k];
					j++;
				}
				new[j]='\0';
				if(new[strlen(new)-1]=='/')
					new[strlen(new)-1]='\0';
			}
			else
				strcpy(new,temp2);
			printf(":')");
			}
		}
	}
}
