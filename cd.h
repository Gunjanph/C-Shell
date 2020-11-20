typedef long long int ll;

char temp1[10000],temp2[10000],old[10000],new[10000],newer[10000],buff[10000];
char command[100][1024],inter[100][1024],dir[2][1024];
struct utsname name;
struct passwd *pw;

void last_dir(char lastdir[1024]);
void cd(char arr[1024]);
