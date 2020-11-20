#include "header.h"
#include "piping.h"
#include "redirection.h"

void piping(char comm[1024])
{
	// printf("in piping\n");
	ll err=0;
	char *p;
	pid_t newproc;
	int type=0, parr[2], fd=0;
    ll no = 0,flagr=0;
	p = strtok (comm, "|");
    char **pipe_args = malloc(1024 * sizeof(char *));
	while (p != NULL)
    {
        pipe_args[no] = p;
        p = strtok (NULL, "|");
        no++;
    }
    for(int j=0; j<no; j++)
    {
    	// printf("%s\n",pipe_args[j]);
    	flagr=0;
    	for(ll i=0;i<strlen(pipe_args[j]);i++)
    	{
    		if(pipe_args[j][i]=='<')
				flagr++;
			else if(pipe_args[j][i]=='>')
				flagr++;
			else if(pipe_args[j][i]=='>' && pipe_args[j][i+1]=='>')
				flagr++;
    	}
        if(pipe(parr)<0)
        {
        	perror("Error in Piping");
        	err=1;
        }
        newproc=fork();
        //printf("in j loop\n");
        if(newproc<0)
        {
        	err=1;
        	perror("Error while forking");
        }
        else if(newproc==0)
        {
            if(dup2(fd , 0)<0)
            {
            	perror("Error in dup2 for stdin");
            	err=1;
            }
            if(pipe_args[j+1]!=NULL)
            { 
            	if(dup2(parr[1],1)<0)
            	{
            		err=1;
            		perror("Error in dup2 for stdout");
            	}
            }
            close(parr[0]);
            if(flagr>0)
            	redirection(pipe_args[j]);
            else
            	check_command(pipe_args[j]);
            //close(parr[1]);
            exit(2);
        }
        else
        {
            wait(NULL);
            close(parr[1]);
            fd = parr[0];
            //close(parr[0]);
        }
    }
    if(err==1)
    	printf(":'(");
    else
    	printf(":')");
}
