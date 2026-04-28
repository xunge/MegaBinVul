#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

struct upnp_event_notify {
    int state;
    char *buffer;
    size_t buffersize;
    size_t tosend;
    const char *path;
    const char *addrstr;
    const char *portstr;
    struct {
        int service;
        const char *uuid;
        unsigned int seq;
    } *sub;
};

enum {
    EError,
    ESending,
    EWanCFG,
    EWanIPC,
#ifdef ENABLE_L3F_SERVICE
    EL3F,
#endif
#ifdef ENABLE_6FC_SERVICE
    E6FC,
#endif
#ifdef ENABLE_DP_SERVICE
    EDP,
#endif
};

#define UPNP_VERSION_MAJOR 1
#define UPNP_VERSION_MINOR 1

char *getVarsWANCfg(int *l);
char *getVarsWANIPCn(int *l);
#ifdef ENABLE_L3F_SERVICE
char *getVarsL3F(int *l);
#endif
#ifdef ENABLE_6FC_SERVICE
char *getVars6FC(int *l);
#endif
#ifdef ENABLE_DP_SERVICE
char *getVarsDP(int *l);
#endif