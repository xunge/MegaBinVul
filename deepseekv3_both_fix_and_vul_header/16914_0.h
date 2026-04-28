#include <stdlib.h>
#include <stdint.h>

#define HFIXEDSZ 12
#define QFIXEDSZ 4
#define RRFIXEDSZ 10

#define ARES_SUCCESS 0
#define ARES_EBADRESP 1
#define ARES_ENOMEM 2

#define C_IN 1
#define T_SOA 6

#define DNS_HEADER_QDCOUNT(buf) (((buf)[4] << 8) | (buf)[5])
#define DNS_HEADER_ANCOUNT(buf) (((buf)[6] << 8) | (buf)[7])
#define DNS_QUESTION_TYPE(buf) (((buf)[0] << 8) | (buf)[1])
#define DNS_RR_TYPE(buf) (((buf)[0] << 8) | (buf)[1])
#define DNS_RR_CLASS(buf) (((buf)[2] << 8) | (buf)[3])
#define DNS_RR_LEN(buf) (((buf)[8] << 8) | (buf)[9])
#define DNS__32BIT(buf) (((buf)[0] << 24) | ((buf)[1] << 16) | ((buf)[2] << 8) | (buf)[3])

struct ares_soa_reply {
    char *nsname;
    char *hostmaster;
    uint32_t serial;
    uint32_t refresh;
    uint32_t retry;
    uint32_t expire;
    uint32_t minttl;
};

enum {
    ARES_DATATYPE_SOA_REPLY = 1
};

void ares_free(void *ptr);
void ares_free_data(void *ptr);
void *ares_malloc_data(int type);
int ares__expand_name_for_response(const unsigned char *aptr,
                                  const unsigned char *abuf,
                                  int alen,
                                  char **name,
                                  long *len);