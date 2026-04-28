#include <stdint.h>
#include <sys/types.h>

struct dhcp_opt {
    uint8_t option;
    int type;
};

extern const struct dhcp_opt dhcp_opts[];

#define STRING   0x01
#define RFC3442  0x02  
#define RFC5969  0x04
#define UINT32   0x08
#define SINT32   0x10
#define IPV4     0x20
#define UINT16   0x40
#define SINT16   0x80
#define UINT8    0x100
#define ARRAY    0x200