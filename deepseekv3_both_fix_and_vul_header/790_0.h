#include <stdint.h>
#include <netinet/in.h>

#define FALSE 0
#define TRUE 1

#define INT_SWITCHING_TYPE_SUBOBJ 1
#define WAVELENGTH_SUBOBJ 2

typedef struct netdissect_options netdissect_options;

extern const char *tok2str(const char *, const char *, int);
#define ND_PRINT(args)
#define ND_TCHECK_32BITS(p)

#define EXTRACT_8BITS(p) ((p)[0])
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

extern const char *lmp_data_link_subobj[];
extern const char *gmpls_switch_cap_values[];
extern const char *gmpls_encoding_values[];