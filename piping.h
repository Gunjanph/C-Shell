typedef long long int ll;

char old[10000],new[10000],newer[10000],lstdir[1024];
char command[100][1024],inter[100][1024];

char pipe_comm[100][1024];
ll check,filedes;
int pipe_arr[2];

void piping(char comm[1024]);