#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096
#define UDP_ONLY 1
#define TCP_AND_UDP 2

extern char *working_dir;
extern char *executable;
extern int verbose;

struct manager_ctx {
    char *manager_address;
    char *acl;
    char *timeout;
    int nofile;
    char *user;
    int verbose;
    int mode;
    int fast_open;
    int ipv6first;
    int mtu;
    char *plugin;
    char *plugin_opts;
    char **nameservers;
    int nameserver_num;
    char **hosts;
    int host_num;
    char *method;
};

struct server {
    char *port;
    char *mode;
    char fast_open[1];
    char *plugin;
    char *plugin_opts;
    char *method;
};