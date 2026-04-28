#include <stdint.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

#define INT_SWITCHING_TYPE_SUBOBJ 1
#define WAVELENGTH_SUBOBJ 2

typedef struct netdissect_options {
    int dummy;
} netdissect_options;

typedef unsigned char u_char;

struct tok {
    const char *s;
    unsigned int v;
};

extern const struct tok lmp_data_link_subobj[];
extern const struct tok gmpls_switch_cap_values[];
extern const struct tok gmpls_encoding_values[];

#define EXTRACT_8BITS(p) ((uint8_t)(*(p)))
#define EXTRACT_32BITS(p) ((uint32_t)(*(p)))
#define ND_PRINT(args) printf args