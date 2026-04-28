#include <stdlib.h>

#define GEN_X400 0
#define GEN_EDIPARTY 1
#define GEN_OTHERNAME 2
#define GEN_EMAIL 3
#define GEN_DNS 4
#define GEN_URI 5
#define GEN_DIRNAME 6
#define GEN_IPADD 7
#define GEN_RID 8

typedef struct GENERAL_NAME {
    int type;
    union {
        void *x400Address;
        void *ediPartyName;
        void *otherName;
        void *ia5;
        void *dirn;
        void *ip;
        void *rid;
        void *other;
    } d;
} GENERAL_NAME;