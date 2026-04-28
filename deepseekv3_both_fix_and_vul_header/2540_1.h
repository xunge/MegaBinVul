#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef struct netdissect_options netdissect_options;

struct aodv_ext {
    unsigned int type;
    unsigned int length;
};
struct aodv_hello {
    uint32_t interval;
};

#define AODV_EXT_HELLO 1
#define ND_TCHECK(x) 
#define ND_PRINT(args)
#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))