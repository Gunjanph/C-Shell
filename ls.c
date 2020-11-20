#include "header.h"
#include "ls.h"
#include "cd.h"

char temp[100][1024];
ll errflag=0;

void permission(char arr[1024],ll flag)
{
	struct stat list;
	DIR *dir;
	char path[1024];
	ll num;
	if((dir = opendir(arr))==NULL)
	{
		perror("Cannot open directory");
		errflag=1;
	}
	else
	{
		if(flag==1)
		{
			//getcwd(path,1024);
			//strcat(path,"/");
			//strcat(path,arr);
			//chdir(path);
			//getcwd(path,1024);
			getcwd(path,1024);
			strcat(path,"/");
			if(arr[0]!='/')
				strcat(path,arr);
			else
				strcpy(path,arr);
			num = scandir(path, &dl, NULL, alphasort);
			if(num<0)
			{
				perror("scandir");
				errflag=1;
			}
			for(ll i=0;i<num;i++)
			{
				ll s = stat(dl[i]->d_name,&list);
				if(s<0)
				{
					perror("Error in accessing file");
					continue;
				}
				if (S_ISREG(list.st_mode))
					printf("-");
				else if (S_ISDIR(list.st_mode))
					printf("d");
				if (S_IRUSR & list.st_mode)
					printf("r");
				else
					printf("-");
				if (S_IWUSR & list.st_mode)
					printf("w");
				else
					printf("-");
				if (S_IXUSR & list.st_mode)
					printf("x");
				else
					printf("-");
				if (S_IRGRP & list.st_mode)
					printf("r");
				else
					printf("-");
				if (S_IWGRP & list.st_mode)
					printf("w");
				else
					printf("-");
				if (S_IXGRP & list.st_mode)
					printf("x");
				else
					printf("-");
				if (S_IROTH & list.st_mode)
					printf("r");
				else
					printf("-");
				if (S_IWOTH & list.st_mode)
					printf("w");
				else
					printf("-");
				if (S_IXOTH & list.st_mode)
					printf("x");
				else
					printf("-");
				free(dl[num]);

				printf(" %5ld ", list.st_nlink);
				struct passwd *pw = getpwuid(list.st_uid);
				if (pw == NULL)
				{
					perror("Failed in getting username");
					errflag=1;
				}
				else
					printf("%3s ", pw->pw_name);

				struct group *gr = getgrgid(list.st_gid); 
				if (gr == NULL)
				{
					perror("Failed in getting group");
					errflag=1;
				}
				else
					printf("%s ", gr->gr_name);

				printf("%12ld ", list.st_size);
				struct tm *time = localtime(&(list.st_mtime));
				strftime(buff,20,"%b %d %H:%M", time);
				printf("%s ", buff);
				printf("%s\n", dl[i]->d_name);
			}
			//chdir(predir);
			free(dl);
			if(closedir(dir)==-1)
			{
				perror("Cannot close the file");
				errflag=1;
			}
		}
		else
		{
			getcwd(path,1024);
			strcat(path,"/");
			if(arr[0]!='/')
				strcat(path,arr);
			else
				strcpy(path,arr);
			num = scandir(path, &dl, NULL, alphasort);
			//chdir(path);
			for(ll i=0;i<num;i++)
			{
				stat(dl[i]->d_name,&list);
				if(dl[i]->d_name[0]!='.')//&&strcmp(dp->d_name,".."))
				{
					if (S_ISREG(list.st_mode))
						printf("-");
					else if (S_ISDIR(list.st_mode))
						printf("d");

					if (S_IRUSR & list.st_mode)
						printf("r");
					else
						printf("-");
					if (S_IWUSR & list.st_mode)
						printf("w");
					else
						printf("-");
					if (S_IXUSR & list.st_mode)
						printf("x");
					else
						printf("-");
					if (S_IRGRP & list.st_mode)
						printf("r");
					else
						printf("-");
					if (S_IWGRP & list.st_mode)
						printf("w");
					else
						printf("-");
					if (S_IXGRP & list.st_mode)
						printf("x");
					else
						printf("-");
					if (S_IROTH & list.st_mode)
						printf("r");
					else
						printf("-");
					if (S_IWOTH & list.st_mode)
						printf("w");
					else
						printf("-");
					if (S_IXOTH & list.st_mode)
						printf("x");
					else
						printf("-");
					printf(" %5ld ", list.st_nlink);
					struct passwd *pw = getpwuid(list.st_uid);
					if (pw == NULL)
					{
						perror("Failed in getting username");
						errflag=1;
					}
					else
						printf("%3s ", pw->pw_name);
					struct group *gr = getgrgid(pw->pw_gid); 
					if (gr == NULL)
					{
						perror("Failed in getting group");
						errflag=1;
					}
					else
						printf("%s ", gr->gr_name);
					printf("%12ld ", list.st_size);
					struct tm *time = localtime(&(list.st_mtime));
					strftime(buff,20,"%b %d %H:%M", time);
					printf("%s ", buff);
					printf("%s\n", dl[i]->d_name);
				}
			}
			if(closedir(dir)==-1)
			{
				perror("Cannot close the file");
				errflag=1;
			}
		}
	}
}

void lsflag(ll k)
{
	ll l=0,a=0,n=0;
	getcwd(predir,1024);
	for(ll i=1;i<k;i++)
	{
		//printf("%d\n",strcmp(inter[i],"-al"));
		if(inter[i][0]=='-')
		{
			if(strcmp(inter[i],"-l")==0)
				l++;
			else if(strcmp(inter[i],"-a")==0)
				a++;
			else if(strcmp(inter[i],"-al")==0 || strcmp(inter[i],"-la")==0)
			{
				//        printf("1\n");
				l++;
				a++;
			}
		}
		else
		{
			strcpy(temp[n],inter[i]);
			n++;
		}
	}
	if(l>0 && a>0)
	{
		if(n==0)
		{
			strcpy(temp[0],".");
			// printf("1\n");
			permission(temp[0],1);
		}
		for(ll i=0;i<n;i++)
		{
			if(n>1)
			{
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					// strcpy(new,predir);
					cd(predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				printf("%s:\n",temp[i]);
				permission(temp[i],1);
				if(i<n-1)
					printf("\n");
			}
			else
			{
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					cd(predir);
					//printf(" %s ++++\n",predir);
					// strcpy(new,predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				permission(temp[i],1);
			}
		}
	}
	else if(l>0 && a==0)
	{
		if(n==0)
		{
			strcpy(temp[0],".");
			permission(temp[0],0);
		}
		for(ll i=0;i<n;i++)
		{
			if(n>1)
			{
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					//printf("krit: %s\n",temp[i]);
					cd(predir);
					// strcpy(new,predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				printf("%s:\n",temp[i]);
				permission(temp[i],0);
				if(i<n-1)
					printf("\n");
			}
			else
			{
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					cd(predir);
					// strcpy(new,predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				permission(temp[i],0);
			}
		}
	}
	else if(a>0 && l==0)
	{
		if(n==0)
		{
			DIR *dir;
			if((dir = opendir("."))==NULL)
			{
				errflag=1;
				perror("Cannot open current directory");
			}
			else
			{
				while((dp = readdir(dir))!=NULL)
				{
					printf("%s\n", dp->d_name);
				}
				if(closedir(dir)==-1)
				{
					errflag=1;
					perror("Cannot close the file");
				}
			}
		}
		for(ll i=0;i<n;i++)
		{
			//	printf("1\n");
			if(n>1)
			{
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					cd(predir);
					// strcpy(new,predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				printf("%s:\n",temp[i]);
				DIR *dir;
				if((dir = opendir(temp[i]))==NULL)
				{
					errflag=1;
					perror("Cannot open current directory");
				}
				else
				{
					while((dp = readdir(dir))!=NULL)
					{
						printf("%s\n", dp->d_name);
					}
					if(closedir(dir)==-1)
					{
						errflag=1;
						perror("Cannot close the file");
					}
				}
				if(i<n-1)
					printf("\n");
			}
			else
			{
				DIR *dir;
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					cd(predir);
					// strcpy(new,predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				if((dir = opendir(temp[i]))==NULL)
				{
					errflag=1;
					perror("Cannot open current directory");
				}
				else
				{
					while((dp = readdir(dir))!=NULL)
					{
						printf("%s\n", dp->d_name);
					}
					if(closedir(dir)==-1)
					{
						errflag=1;
						perror("Cannot close the file");
					}

				}
			}
		}
	}
	else
	{
		DIR *dir;
		for(ll i=0;i<n;i++)
		{
			if(n>1)
			{
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					// strcpy(new,predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				printf("%s:\n",temp[i]);
				if((dir = opendir(temp[i]))==NULL)
				{
					errflag=1;
					perror("Cannot open current directory");
				}
				else
				{
					while((dp = readdir(dir))!=NULL)
					{
						if(dp->d_name[0]!='.')//&&strcmp(dp->d_name,".."))
							printf("%s\n", dp->d_name);
					}
					if(closedir(dir)==-1)
					{
						errflag=1;
						perror("Cannot close the file");
					}
				}
				if(i<n-1)
					printf("\n");
			}
			else
			{
				if(temp[i][0]=='~')
				{
					cd(temp[i]);
					strcpy(temp[i],new);
					cd(predir);
					// strcpy(new,predir);
					// chdir(predir);
					// getcwd(new,1000);
				}
				if((dir = opendir(temp[i]))==NULL)
				{
					errflag=1;
					perror("Cannot open current directory");
				}
				else
				{
					while((dp = readdir(dir))!=NULL)
					{
						if(dp->d_name[0]!='.')//&&strcmp(dp->d_name,".."))
							printf("%s\n", dp->d_name);
					}
					if(closedir(dir)==-1)
					{
						errflag=1;
						perror("Cannot close the file");
					}
				}
			}
		}
	}
	if(errflag==1)
		printf(":'(");
	else
		printf(":')");
}
void ls()
{
	DIR *dir;
	//printf("%s\n", new);
	if((dir = opendir("."))==NULL)
	{
		perror("Cannot open current directory");
		printf(":'(");
	}
	else
	{
		while((dp = readdir(dir))!=NULL)
		{
			if(dp->d_name[0]!='.')//&&strcmp(dp->d_name,".."))
				printf("%s\n", dp->d_name);
		}
		if(closedir(dir)==-1)
		{
			perror("Cannot close the file");
			printf(":'(");
		}
		else
			printf(":')");
	}
}
