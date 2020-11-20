typedef long long int ll;

char old[10000],new[10000],newer[10000],lstdir[1024];
char command[100][1024],inter[100][1024];
char outfile[1024],appfile[1024],infile[1024];

ll in,out,ap,infd,outfd,apfd,err_flag;

void redirection(char comm[1024]);
