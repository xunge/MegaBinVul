#include <stdlib.h>
#include <string.h>

typedef struct _packet_info packet_info;
typedef struct _address address;
typedef unsigned char guint8;

enum address_type {
    AT_STRINGZ,
    AT_ETHER
};

#define SET_ADDRESS(paddr, addr_type, addr_len, addr_data) \
    do { \
        (paddr)->type = addr_type; \
        (paddr)->len = addr_len; \
        (paddr)->data = addr_data; \
    } while (0)

struct _address {
    enum address_type type;
    int len;
    void *data;
};

struct _packet_info {
    void *pool;
};

char *dnet_ntoa(const guint8 *addr);
void *wmem_strdup(void *pool, const char *str);