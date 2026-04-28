#include <time.h>
#include <string.h>

#define V_ASN1_UTCTIME 23

typedef struct ASN1_TIME_st {
    int type;
    int length;
    unsigned char *data;
    long flags;
} ASN1_TIME;

ASN1_TIME *X509_time_adj(ASN1_TIME *s, long offset_sec, time_t *in_tm);