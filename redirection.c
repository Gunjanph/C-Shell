#include "header.h"
#include "redirection.h"

void redirection(char comm[1024])
{
	ll n=0;
	char *re;
	char retemp[1024];
	strcpy(retemp,comm);
	re = strtok (retemp, "><>>");
    char **redir_args = malloc(1024 * sizeof(char *));
	while (re != NULL)
    {
        redir_args[n] = re;
        re = strtok (NULL, "><>>");
        n++;
    }

	ll j=1,input=0,output=0,app=0;
	for(ll i=0;i<strlen(comm);i++)
	{
		if(j>=n)
			break;
		if(redir_args[j][0]==' ')
		{
			ll length = strlen(redir_args[j]);
			for(ll x=0;x<length-1;x++)
			{
				if(redir_args[j][x+1]!=' ')
					redir_args[j][x]=redir_args[j][x+1];
				else
					redir_args[j][x]='\0';
			}
			redir_args[j][length-1]='\0';
		}
		if(comm[i]=='<')
		{
			input++;
			strcpy(infile,redir_args[j]);
			j++;
		}
		else if(comm[i]=='>' && comm[i+1]=='>')
		{
			app++;
			strcpy(appfile,redir_args[j]);
			j++;
		}
		else if(comm[i]=='>')
		{
			output++;
			strcpy(outfile,redir_args[j]);
			j++;
		}
	}
	if(input>0)
	{
		in = dup(0);
		infd = open(infile, O_RDONLY);
		if(infd == -1)
		{
			err_flag=1;
			perror("Error in Opening File");
		}
		else
		{
			dup2(infd, 0);
		}
	}
	if(output>0)
	{
		out = dup(1);
		outfd = open(outfile, O_RDWR|O_CREAT|O_TRUNC,0644);
		if(outfd == -1)
		{
			err_flag=1;
			perror("Error in Opening File");
		}
		else
		{
			dup2(outfd, 1);
		}
	}
	if(app>0)
	{
		printf("in app\n");
		ap = dup(1);
		apfd = open(appfile, O_RDWR|O_CREAT|O_APPEND,0644);
		if(outfd == -1)
		{
			err_flag=1;
			perror("Error in Opening File");
		}
		else
		{
			dup2(apfd, 1);
		}
	}
	if(err_flag!=1)
		check_command(redir_args[0]);
	else
		printf(":'(");
	if(input>0)
	{
		dup2(in,0);
		close(infd);
		close(in);
	}
	if(output>0)
	{
		dup2(out,1);
		close(outfd);
		close(out);
	}
	if(app>0)
	{
		dup2(ap,1);
		close(apfd);
		close(ap);
	}
}