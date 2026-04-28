#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nfs_host_cookie {
    const char *filename;
    const char *sharepath;
    const char *security;
    int (*callback)(const char *, const char *, const char *, const char *, const char *, void *);
    void *cookie;
} nfs_host_cookie_t;

#define SA_OK 0
#define SA_NO_MEMORY 1
#define SA_SYNTAX_ERR 2
#define DEBUG 1