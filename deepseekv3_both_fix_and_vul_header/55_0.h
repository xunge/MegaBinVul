#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <syslog.h>
#include <stdint.h>

typedef struct {
    uint16_t id;
    uint16_t opcode:4;
    uint16_t rcode:4;
    uint16_t rd:1;
    uint16_t qr:1;
    uint16_t aa:1;
    uint16_t tc:1;
    uint16_t ra:1;
    uint16_t zero:3;
    uint16_t qdcnt;
    uint16_t ancnt;
    uint16_t nscnt;
    uint16_t arcnt;
} Mesg_Hdr;

#define OP_QUERY 0
#define RC_OK 0

#define PUTSHORT(s, p) { \
    *(p)++ = (uint8_t)((s) >> 8); \
    *(p)++ = (uint8_t)((s) & 0xff); \
}

typedef struct {
    int debug;
} T_struct;
extern T_struct T;

extern char *string_rtype(uint16_t qtype);
extern int dname_copy(u_char *src, u_char *dst, int dstlen);