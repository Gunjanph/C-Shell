#include "header.h"
#include "bg.h"
#include "fg.h"
#include "piping.h"
#include "redirection.h"


typedef long long int ll;
extern char old[10000],new[10000],newer[10000],dir[2][1024];

extern char lstdir[1024];
extern ll p,pidls[100][1024];
extern char command[100][1024],inter[100][1024],list[100][1024];
extern struct utsname name;

int main()
{
	getcwd(old,9999);
	getcwd(new,9999);
	strcpy(dir[0],new);

	printf("\nWELCOME TO MY SHELL<3\n\n");
	
	// SIGNAL HANDLING
	signal(SIGINT, Ctrl_C);
	signal(SIGTSTP, Ctrl_Z);

	while(1)
	{
		// PRINTING PROMPT LINE
		curr_fore[0] = 0;
		prompt(name,old,new);

		strcpy(command[0],"");

		// TAKING COMMANDS
		char *buffer = (char*)malloc(10000*sizeof(char));
		size_t bufsize = 1024;
		ll ch = getline(&buffer,&bufsize,stdin);
		
		if(strcmp(buffer,"\0")==0 || ch ==-1)
		{
			printf("\n");
			quit();
		}
		buffer[strlen(buffer)-1]='\0';

		// DIFFERENTIATING COMMANDS WITH SEMICOLON
		char* tok;
		tok = strtok(buffer,";");
		ll i=0;
		while(tok!=NULL)
		{
			strcpy(command[i],tok);
			tok = strtok(NULL,";");
			i++;
		}

		// OPERATING DIFFERENT COMMANDS
		for(ll j=0;j<i;j++)
		{
			ll flagr=0,pipe_flag=0;
			for(ll t=0;t<strlen(command[j]);t++)
			{
				if(command[j][t]=='<')
				{
					flagr++;
				}
				else if(command[j][t]=='>')
				{
					flagr++;
				}
				else if(command[j][t]=='>' && command[j][t+1]=='>')
				{
					flagr++;
				}
				else if(command[j][t]=='|')
				{
					pipe_flag++;
				}
			}
			if(pipe_flag>0)
				piping(command[j]);
			else if(flagr>0)
				redirection(command[j]);
			else
				check_command(command[j]);
		}
	}
	return 0;
}
