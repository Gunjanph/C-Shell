typedef long long int ll;

char old[10000],new[10000],newer[10000],buff[10000],predir[10000];
char command[100][1024],inter[100][1024];
struct utsname name;
struct passwd *pw;
struct dirent *dp,**dl;
void permission(char arr[1024],ll k);
void ls();
void lsflag(ll k);
