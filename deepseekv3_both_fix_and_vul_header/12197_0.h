#include <stdint.h>
#include <string.h>

#define BGP_LABEL_BYTES 3

typedef uint32_t mpls_label_t;

struct peer;

static inline int label_bos(mpls_label_t *label) { return *label & 0x100; }
static inline int bgp_is_withdraw_label(mpls_label_t *label) { return *label == 0x800000; }
static inline void bgp_set_valid_label(mpls_label_t *label) { *label &= 0xFFFFF; }

#define EC_BGP_INVALID_LABEL_STACK 0

void zlog_info(const char *format, ...);
void flog_warn(int ec, const char *format, ...);