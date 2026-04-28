#include <stdlib.h>

#define GEN_OTHERNAME 0
#define GEN_EMAIL 1
#define GEN_DNS 2
#define GEN_X400 3
#define GEN_DIRNAME 4
#define GEN_EDIPARTY 5
#define GEN_URI 6
#define GEN_IPADD 7
#define GEN_RID 8

typedef struct {
    void *x400Address;
    void *ediPartyName;
    void *otherName;
    void *ia5;
    void *dirn;
    void *ip;
    void *rid;
    void *other;
} GENERAL_NAME_d;

typedef struct {
    int type;
    GENERAL_NAME_d d;
} GENERAL_NAME;