#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

#define ND_TCHECK2(a, b)
#define ND_PRINT(args)
#define EXTRACT_32BITS(p) (*((uint32_t*)(p)))

static const char *tok2str(const char *str, const char *default_str, int val);
static void print_unknown_data(netdissect_options *ndo, const unsigned char *data, const char *str, int len);

enum {
    BACPOPT_FPEER
};

static const char *bacconfopts_values[] = {
    NULL
};