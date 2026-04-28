#include <stdint.h>
#include <inttypes.h>

typedef struct netdissect_options netdissect_options;
#define ND_PRINT(args) 
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))
#define EXTRACT_64BITS(p) ((uint64_t)(((uint64_t)ntohl(*((const uint32_t *)(p) + 0))) << 32 | \
                                      ((uint64_t)ntohl(*((const uint32_t *)(p) + 1))) << 0))