#include "header.h"
#include "echo.h"
void echo(char arr[10000])
{
	ll j,k;
	for(ll i=0;i<strlen(arr);i++)
	{
		if(arr[i]=='e')
		{
			if(arr[i+1]=='c'&&arr[i+2]=='h'&&arr[i+3]=='o')
			{
				j=i+4;
				break;
			}
		}
	}
	if(strlen(arr)<=j)
		printf("1\n");
	else
	{
		for(ll i=j;j<strlen(arr);i++)
		{
			if(arr[i]==' ')
				continue;
			else
			{
				k=i;
				break;
			}
		}
		for(ll i=k;i<strlen(arr)-1;i++)
		{
			printf("%c",arr[i]);
		}
		printf("\n");
	}
}