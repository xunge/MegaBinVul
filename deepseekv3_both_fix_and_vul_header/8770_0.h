#include <stdio.h>
#include <string.h>
#include <time.h>

#define FN_REFLEN 512
#define REDEL_EXT ".backup"

#define MY_REDEL_NO_COPY_STAT 1
#define MY_REDEL_MAKE_BACKUP 2

#define DBUG_ENTER(x)
#define DBUG_PRINT(x, y)
#define DBUG_RETURN(x) return x

typedef int myf;

int my_copystat(const char *org_name, const char *tmp_name, myf MyFlags);
int my_rename(const char *from, const char *to, myf MyFlags);
int my_delete_allow_opened(const char *name, myf MyFlags);
char *fn_format(char *to, const char *name, const char *key, const char *ext, int flag);
char *strend(char *str);
void get_date(char *to, int time_flag, time_t time);