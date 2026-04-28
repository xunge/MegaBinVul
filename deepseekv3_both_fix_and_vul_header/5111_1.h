#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define RR_TYPE_LENGTH 2
#define RR_CLASS_LENGTH 2
#define RR_TTL_LENGTH 4
#define RR_RDLENGTH_LENGTH 2
#define DNS_CLASS_IN 1
#define DNS_TYPE_A 1
#define DNS_TYPE_AAAA 28
#define INADDRSZ 4
#define IN6ADDRSZ 16
#define EBADMSG 74

typedef struct {
    uint16_t qdcount;
    uint16_t ancount;
} sock_dns_hdr_t;

static ssize_t _skip_hostname(uint8_t *buf, size_t len, uint8_t *bufpos);
static uint16_t _get_short(uint8_t *bufpos);