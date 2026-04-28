#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int verbose;

struct manager_ctx {
    char *method;
};

struct server {
    char *port;
    char *password;
    char *method;
    char fast_open[1];
    char *mode;
    char *plugin;
    char *plugin_opts;
};

void *ss_malloc(size_t size);
void ss_free(void *ptr);
void LOGE(const char *msg);