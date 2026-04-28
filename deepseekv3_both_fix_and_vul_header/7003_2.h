#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define PW_EAP_SIM_SUBTYPE 0
#define PW_EAP_SIM_BASE 0
#define MAX_STRING_LEN 256

typedef struct value_pair {
    int vp_integer;
    unsigned int vp_length;
    uint8_t *vp_octets;
    struct value_pair *next;
} VALUE_PAIR;

typedef struct radius_packet {
    VALUE_PAIR *vps;
} RADIUS_PACKET;

VALUE_PAIR *fr_pair_afrom_num(RADIUS_PACKET *r, int type, int dummy);
void fr_pair_add(VALUE_PAIR **vps, VALUE_PAIR *vp);
void fr_strerror_printf(const char *fmt, ...);
void *talloc_array(void *ctx, size_t size);

#define talloc_array(ctx, type, count) ((type *)talloc_array(ctx, sizeof(type) * (count)))