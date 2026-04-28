#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <syslog.h>

#define MAXARGS 16
#define MAXINTERFACES 16
#define PORT_TO 1234

struct {
    int debug;
    int prefixnum;
    int retry_interval;
    char *pidfile;
    char *iflist[MAXINTERFACES];
    int wildcard;
    int port;
#ifdef SWILL
    int http_port;
#endif
#ifdef STF
    int stf;
#endif
#ifdef SCOPED_REWRITE
    int scoped_prefixes;
#endif
} T;

typedef unsigned char u_char;

int fwd_add(char *addr, int port);
int conv_trick_conf(u_char *prefix);
#ifdef SCOPED_REWRITE
int conv_scoped_conf(char *from, char *to, int plen);
#endif