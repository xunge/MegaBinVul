#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>

struct mg_str {
    const char *ptr;
    size_t len;
};

struct mg_connection {
    int fd;
};

struct mg_http_message {
    struct mg_str query;
    struct mg_str body;
};

#define MG_DIRSEP '/'

void mg_http_get_var(const struct mg_str *query, const char *name, char *dst, size_t dst_len);
void mg_http_reply(struct mg_connection *c, int status, const char *headers, const char *fmt, ...);
#define LOG(level, args)
#define LL_DEBUG 0