#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define HFIXEDSZ 12
#define QFIXEDSZ 4
#define RRFIXEDSZ 10

#define DNS_HEADER_QDCOUNT(p) (((p)[4] << 8) | (p)[5])
#define DNS_HEADER_ANCOUNT(p) (((p)[6] << 8) | (p)[7])
#define DNS_RR_TYPE(p) (((p)[0] << 8) | (p)[1])
#define DNS_RR_CLASS(p) (((p)[2] << 8) | (p)[3])
#define DNS_RR_LEN(p) (((p)[8] << 8) | (p)[9])

#define C_IN 1
#define T_A 1
#define T_CNAME 5

#define ARES_SUCCESS 0
#define ARES_EBADRESP -1
#define ARES_ENOMEM -2
#define ARES_ENODATA -3

int ares_expand_name(const unsigned char *aptr, const unsigned char *abuf, int alen, char **s, long *enclen);