#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTOKEN 256
#define LABEL 1
#define DEFINITIONS 2

extern int mibLine;
extern const char *File;
extern void snmp_log_perror(const char *);
extern int get_token(FILE *, char *, int);
extern void new_module(const char *, const char *);
extern void DEBUGMSGTL(const char *, ...);

struct debugmsg_args {
    const char *domain;
    const char *format;
    const char *arg;
};