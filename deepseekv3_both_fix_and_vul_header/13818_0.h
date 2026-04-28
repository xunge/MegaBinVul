#include <string.h>

#define MINIUPNPC_URL_MAXSIZE 256

struct IGDdatas {
    char cureltname[MINIUPNPC_URL_MAXSIZE];
    int level;
    struct {
        char controlurl[MINIUPNPC_URL_MAXSIZE];
        char eventsuburl[MINIUPNPC_URL_MAXSIZE];
        char scpdurl[MINIUPNPC_URL_MAXSIZE];
        char servicetype[MINIUPNPC_URL_MAXSIZE];
    } tmp;
};