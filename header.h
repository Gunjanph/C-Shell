#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <libgen.h>
#include <time.h>
#include <termios.h>
#include <signal.h>

void prompt(struct utsname name, char original[10000], char new[10000]);
void quit();
void check_command(char *command);