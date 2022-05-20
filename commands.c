#include "header.h"
#include "cd.h"
#include "ls.h"
#include "pwd.h"
#include "echo.h"
#include "fg.h"
#include "bg.h"
#include "pinfo.h"
#include "history.h"
#include "nightwatch.h"
#include "redirection.h"
#include "envvar.h"
#include "piping.h"

void check_command(char command[1024])
{
	char* token;
	char temp[1024];
	strcpy(temp,command);
	addhistory(command);
	token = strtok(temp," \t");
	ll k=0;
	while(token!=NULL)
	{
		strcpy(inter[k],token);
		token = strtok(NULL," \t");
		k++;
	}
	if(strcmp(inter[0],"cd")==0)
	{
		if(k==1)
		{
			perror("No Argument given");
			printf(":'(");
		}
		else
		{
			getcwd(lstdir,1024);
			cd(inter[1]);
			last_dir(lstdir);
		}
	}
	else if(strcmp(inter[0],"pwd")==0)
	{
		pwd();
	}
	else if(strcmp(inter[0],"echo")==0)
	{
		if(k==1)
			printf("\n");
		else
		{
			for(ll i=1;i<k;i++)
				printf("%s ", inter[i]);
			printf("\n");
		}
		printf(":')");
	}
	else if(strcmp(inter[0],"ls")==0)
	{
		if(k==1)
			ls();
		else
		{
			lsflag(k);
		}
	}
	else if(strcmp(inter[0],"nightswatch")==0)
		nightswatch(k);
	else if(strcmp(inter[0],"history")==0)
		hist(k);
	else if(strcmp(inter[0],"pinfo")==0)
		pinfo(k);
	else if(strcmp(inter[0],"setenv")==0)
		senv(k);
	else if(strcmp(inter[0],"unsetenv")==0)
		unsenv(k);
	else if(strcmp(inter[0],"overkill")==0)
		overkill();
	else if(strcmp(inter[0],"quit")==0)
		quit();                             // CHECK FOR FG
	else if(strcmp(inter[0],"jobs")==0)
		jobs(k);
	else if(strcmp(inter[0],"kjob")==0)
		kjob(k);
	else if(strcmp(inter[0],"fg")==0)
		fg(k);
	else if(strcmp(inter[0],"bg")==0)
		bg(k);
	else if(strcmp(inter[k-1],"&")==0)
		runbg(k);
	else
		runfg(k);
}
