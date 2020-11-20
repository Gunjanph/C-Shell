#include "header.h"

void prompt(struct utsname name, char original[10000], char new[10000])
{
	char* user;
	if(uname(&name)==0)
	{
		user = getlogin();
		printf("<");
		printf("\033[0;36m");
		printf("%s@%s",user,name.nodename);
		printf("\033[0m");
		printf(":");
		printf("\033[0;33m");
		printf("~");
		if(strcmp(original,new)!=0)
			printf("%s",new);
		printf("\033[0m");
		printf("> ");
	}
	else
	{
		perror("uname");
		printf(":'(");
		exit(1);
	}
}
