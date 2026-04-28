#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *sds;

typedef struct {
    int eval_ldb;
    char *hostsocket;
    char *hostip;
    int hostport;
    int dbnum;
    char prompt[256];
} configStruct;

extern configStruct config;

sds sdsempty(void);
sds sdscatfmt(sds s, const char *fmt, ...);
sds sdscatlen(sds s, const void *t, size_t len);
void sdsfree(sds s);
int anetFormatAddr(char *buf, size_t buf_len, char *ip, int port);