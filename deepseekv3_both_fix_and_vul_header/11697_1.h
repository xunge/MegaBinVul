#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

extern char *dump_file;
extern void log_message(int level, const char *format, ...);
extern void dump_data_vrrp(FILE *file);