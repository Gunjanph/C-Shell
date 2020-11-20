typedef long long int ll;

char old[10000],new[10000],newer[10000],buff[10000],predir[10000],str[1024];
char command[100][1024],inter[100][1024],list[100][1024];
char path[1024];
struct utsname name;

ll p,pidls[100][1024],curr_bg[1024],job_num,sig_num,bg_num;

void background(char * args[1024]);
void runbg(ll n);
void sig_handler(int signum);
void overkill();
void pidover();
void jobs(ll k);
void kjob(ll k);
void bg(ll k);
void Ctrl_C(int signum);
void Ctrl_Z(int signum);