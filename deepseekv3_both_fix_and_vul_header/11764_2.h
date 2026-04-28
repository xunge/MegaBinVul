#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define OS_MAXSTR 4096
#define OS_FLSIZE 1024
#define DEFAULTARPATH "/default/path"
#define AR_BINDIRPATH "/bin/path"
#define FOPEN_ERROR "FOPEN_ERROR"
#define EXEC_INV_CONF "EXEC_INV_CONF"

extern char *ARGV0;
extern int f_time_reading;
extern int exec_size;
extern char exec_names[][OS_FLSIZE + 1];
extern char exec_cmd[][OS_FLSIZE + 1];
extern int exec_timeout[];

void merror(const char *msg, ...);
void verbose(const char *fmt, ...);
int w_ref_parent_folder(const char *str);