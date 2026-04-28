#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    const u_char *ndo_snapend;
    int ndo_vflag;
} netdissect_options;

struct rpl_dio_genoption {
    uint8_t rpl_dio_type;
    uint8_t rpl_dio_len;
};

#define RPL_DIO_GENOPTION_LEN 2
#define RPL_OPT_PAD0 0

#define ND_TCHECK(p)
#define ND_TTEST2(p, l) 1
#define ND_PRINT(args)

extern const char *tok2str(const char **, const char *, uint8_t);
void hex_print(netdissect_options *, const char *, const uint8_t *, unsigned int);