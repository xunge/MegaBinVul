#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define NBNS_DECODED_NAME_LEN 64
#define MAX_ASCII_ADDR_LEN 16
#define NBNS_MSGLEN_QUERY_RESPONSE 512
#define NBNS_TTL_POS 40
#define NBNS_RDATA_POS 46
#define CLASS_IN 1
#define TYPE_NB 32
#define OPCODE_QUERY 0
#define OPCODE_R 0
#define E_SUCCESS 0
#define PO_DROPPED (1 << 0)

typedef uint16_t u_int16;
typedef uint32_t u_int32;
typedef unsigned char u_char;

struct ip_addr {
    uint32_t addr32[1];
};

struct packet_object {
    struct {
        uint8_t *data;
        size_t len;
    } DATA;
    struct {
        uint8_t *src;
    } L2;
    struct {
        struct ip_addr src;
    } L3;
    struct {
        uint16_t src;
        uint16_t dst;
    } L4;
    uint32_t flags;
};

struct nbns_header {
    uint16_t transactid;
    uint16_t response:1;
    uint16_t opcode:4;
    uint16_t broadcast:1;
    uint16_t rcode:4;
    uint16_t rd:1;
    uint16_t tc:1;
    uint16_t aa:1;
    uint16_t ra:1;
    uint16_t z:3;
    uint16_t qd_count;
    uint16_t an_count;
    uint16_t ns_count;
    uint16_t ar_count;
};

struct nbns_query {
    struct nbns_header header;
    uint16_t type;
    uint16_t class;
    uint8_t question[1];
};

struct nbns_rdata {
    uint16_t len;
    uint16_t nbflags;
    uint32_t addr;
};

struct interface {
    struct ip_addr ip;
};

extern struct interface *GBL_IFACE;

void nbns_expand(uint8_t *question, char *name);
int get_spoofed_nbns(char *name, struct ip_addr **reply);
char *ip_addr_ntoa(struct ip_addr *addr, char *buf);
void send_udp(struct ip_addr *src, struct ip_addr *dst, uint8_t *mac, uint16_t sport, uint16_t dport, uint8_t *data, size_t len);
void USER_MSG(const char *fmt, ...);

#define SAFE_CALLOC(ptr, nmemb, size) do { \
    ptr = calloc(nmemb, size); \
} while(0)

#define SAFE_FREE(ptr) do { \
    free(ptr); \
    ptr = NULL; \
} while(0)