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
	// printf("%s\n",command[j]);
	token = strtok(temp," \t");
	ll k=0;
	while(token!=NULL)
	{
		strcpy(inter[k],token);
		//	printf("%s\n",inter[k]);
		token = strtok(NULL," \t");
		k++;
	}
	//printf("%lld\n",k);
	// ll input=0,output=0,app=0,flagr=0,pipe_flag=0;
	// for(ll it=0;it<k;it++)
	// {
	// 	if(strcmp(inter[it],"<")==0)
	// 	{
	// 		input++;
	// 		flagr++;
	// 	}
	// 	else if(strcmp(inter[it],">")==0)
	// 	{
	// 		flagr++;
	// 		output++;
	// 	}
	// 	else if(strcmp(inter[it],">>")==0)
	// 	{
	// 		flagr++;
	// 		app++;
	// 	}
	// 	else if(strcmp(inter[it],"|")==0)
	// 		pipe_flag++;
	// }
	// //printf("%s\n",command[j]);
	// // printf("%lld %lld %lld\n", input, output, app );
	// if(flagr!=0 && pipe_flag==0)
	// 	redirection(k,input,output,app);
	// if(pipe_flag!=0)
	// 	piping(pipe_flag,flagr,k,input,output,app);
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
		//if(inter[1][0]=='"')
		//	echo(command[j]);
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
			//	printf("%s\n",inter[1]);
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
		quit(); // CHECK FOR FG
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
