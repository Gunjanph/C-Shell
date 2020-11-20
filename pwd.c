#include "header.h"
#include "pwd.h"

void pwd()
{
	chdir(".");
	getcwd(m,1000);
	printf("%s\n",m);
	printf(":')");
}