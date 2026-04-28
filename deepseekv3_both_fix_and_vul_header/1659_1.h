#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define OS_MAXSTR 1024
#define OS_FLSIZE 256
#define DEFAULTAR "/default/path"
#define AR_BINDIR "/bin/path"
#define FOPEN_ERROR "Error opening file '%s': %d - %s"
#define EXEC_INV_CONF "Invalid configuration in file '%s'"

extern char exec_names[][OS_FLSIZE + 1];
extern char exec_cmd[][OS_FLSIZE + 1];
extern int exec_timeout[];
extern int exec_size;
extern int f_time_reading;

void merror(const char *format, ...);
void minfo(const char *format, ...);
int w_ref_parent_folder(const char *str);