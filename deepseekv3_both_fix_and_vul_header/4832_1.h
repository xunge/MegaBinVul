#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>

struct pool {
    char *stratum_port;
    char *sockaddr_url;
};