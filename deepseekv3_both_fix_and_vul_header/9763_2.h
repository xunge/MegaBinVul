#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

struct value_pair {
    int type;
    union {
        uint32_t vp_integer;
        uint32_t vp_ipaddr;
        char vp_strvalue[256];
        uint8_t vp_octets[256];
        uint8_t vp_ether[6];
    };
    size_t length;
    uint32_t lvalue;
    struct value_pair *next;
};
typedef struct value_pair VALUE_PAIR;

struct radius_packet {
    uint8_t *data;
    size_t data_len;
    VALUE_PAIR *vps;
};
typedef struct radius_packet RADIUS_PACKET;

struct dict_attr {
    const char *name;
    uint32_t attr;
    int type;
    struct {
        unsigned int array:1;
    } flags;
};
typedef struct dict_attr DICT_ATTR;

extern int fr_debug_flag;
extern FILE *fr_log_fp;
extern const char *dhcp_header_names[];
extern const uint8_t dhcp_header_sizes[];
extern const char *fr_strerror(void);

#define DHCP2ATTR(x) (x)
#define DEFAULT_PACKET_SIZE 576
#define PW_TYPE_BYTE 0
#define PW_TYPE_SHORT 1
#define PW_TYPE_INTEGER 2
#define PW_TYPE_IPADDR 3
#define PW_TYPE_STRING 4
#define PW_TYPE_OCTETS 5
#define PW_TYPE_ETHERNET 6
#define PW_TYPE_DATE 7
#define T_OP_EQ 0

void fr_strerror_printf(const char *fmt, ...);
VALUE_PAIR *pairmake(const char *name, const char *value, int op);
void pairfree(VALUE_PAIR **head);
VALUE_PAIR *pairfind(VALUE_PAIR *head, int attr);
int fr_dhcp_attr2vp(VALUE_PAIR *vp, uint8_t *p, int alen);
void vp_prints(char *buffer, size_t buflen, VALUE_PAIR *vp);
DICT_ATTR *dict_attrbyvalue(uint32_t value);