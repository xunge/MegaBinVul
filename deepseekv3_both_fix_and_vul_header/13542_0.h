#include <string.h>

enum {
    SUB0,
    PUB0,
    PAIR1
};

extern int nng_proxy_client(int argc, char **argv, int type);
extern void help(int type);