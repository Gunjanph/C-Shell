typedef long long int ll;

char old[10000],new[10000],newer[10000],buff[10000],predir[10000];
char command[100][1024],inter[100][1024],lsfg[1024];
ll curr_fore[100],num,child_pid;

void foreground(char * args[1024]);
void runfg(ll n);
void fg(ll k);
