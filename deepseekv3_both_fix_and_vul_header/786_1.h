#include <stdint.h>
#include <sys/types.h>
#include <arpa/inet.h>

typedef struct netdissect_options netdissect_options;

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b) 
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))

extern const char *tstr;
extern const char *dccp_feature_nums[];
extern const char *dccp_option_values[];