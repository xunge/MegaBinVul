#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define LLDPD_AF_UNSPEC 0
#define LLDPD_AF_LAST 255
#define LLDPD_MGMT_MAXADDRSIZE 128

struct lldpd_mgmt {
    int m_family;
    char m_addr[LLDPD_MGMT_MAXADDRSIZE];
    size_t m_addrsize;
    u_int32_t m_iface;
};

extern void log_debug(const char *, const char *, ...);