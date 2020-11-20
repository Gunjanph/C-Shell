typedef long long int ll;

char old[10000],new[10000],newer[10000],buff[10000],predir[10000];
char command[100][1024],inter[100][1024],history[21][1024];
ll count;

void addhistory(char comm[1024]);
void hist(ll k);
