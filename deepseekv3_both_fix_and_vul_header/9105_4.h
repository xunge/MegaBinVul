#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef int (*dissect_per_constrained_integer_t)(tvbuff_t*, int, asn1_ctx_t*, proto_tree*, int, unsigned, unsigned, uint32_t*, bool);

#define _U_ __attribute__((unused))
#define FALSE false

static uint32_t e_dch_ddi_value;
static uint32_t e_dch_macdflow_id;
static uint32_t num_items;

struct flags {
    unsigned visited;
};

struct fd {
    struct flags flags;
};

struct pinfo {
    struct fd *fd;
};

struct asn1_ctx_t {
    struct pinfo *pinfo;
};

struct edch_channel_info {
    uint32_t edch_ddi[1];
};

static struct edch_channel_info nbap_edch_channel_info[1];