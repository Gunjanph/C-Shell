#include "header.h"
#include "bg.h"

void jobs(ll k)
{
	//ll j=1;
	if(k>1)
	{
		perror("Too Many Arguments");
		printf(":'(");
	}
	else
	{
		for(ll i=0;i<p;i++)
		{
			if(curr_bg[i]!=-1)
			{
				sprintf(path,"/proc/%lld/stat",pidls[i][1]);
				//printf("%s\n",path );
				FILE *fd = fopen(path,"r");
				if(fd == NULL)
				{
					perror("Error in opening stat file");
				}
				else
				{
					for(ll i=0;i<3;i++)
						fscanf(fd, "%s", str);
					if(strcmp(str,"T")==0)
						printf("[%lld] Stopped %s [%lld]\n",i+1,list[i],pidls[i][1] );
					else if(strcmp(str,"R")==0 || strcmp(str,"S")==0)
						printf("[%lld] Running %s [%lld]\n",i+1,list[i],pidls[i][1] );
				}
				fclose(fd);
			}
		}
		printf(":')");
	}
}
