#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#define REG_LIVE_READ 1
#define U64_MAX UINT64_MAX
#define S64_MIN INT64_MIN
#define S64_MAX INT64_MAX

struct tnum {
    uint64_t value;
    uint64_t mask;
};

struct bpf_reg_state {
    unsigned int live;
    int type;
    uint64_t umin_value;
    uint64_t umax_value;
    int64_t smin_value;
    int64_t smax_value;
    struct tnum var_off;
    unsigned int id;
    unsigned int off;
    unsigned int range;
};

struct idpair {
    unsigned int old;
    unsigned int cur;
};

enum {
    NOT_INIT,
    SCALAR_VALUE,
    PTR_TO_MAP_VALUE,
    PTR_TO_MAP_VALUE_OR_NULL,
    PTR_TO_PACKET_META,
    PTR_TO_PACKET,
    PTR_TO_CTX,
    CONST_PTR_TO_MAP,
    PTR_TO_STACK,
    PTR_TO_PACKET_END
};

static bool range_within(struct bpf_reg_state *rold, struct bpf_reg_state *rcur);
static bool tnum_in(struct tnum a, struct tnum b);
static bool tnum_is_unknown(struct tnum a);
static bool check_ids(unsigned int old_id, unsigned int cur_id, struct idpair *idmap);
static void WARN_ON_ONCE(int condition);