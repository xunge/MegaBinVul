#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct asn1_ctx_t asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;

#define NO_BOUND 0
#define FALSE 0
#define _U_ __attribute__((unused))

typedef enum {
    T_targetRAT_Type_utra,
    T_targetRAT_Type_geran,
    T_targetRAT_Type_cdma2000_1XRTT,
    T_targetRAT_Type_cdma2000_HRPD
} T_targetRAT_Type;

extern int ett_lte_rrc_targetRAT_MessageContainer;
extern void *rrc_irat_ho_to_utran_cmd_handle;
extern void *gsm_a_dtap_handle;
extern void *gsm_rlcmac_dl_handle;

typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;

struct asn1_ctx_t {
    proto_item *created_item;
    packet_info *pinfo;
};

struct packet_info {
    void *pool;
};

static int dissect_per_octet_string(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int bound1, int bound2, int bool, tvbuff_t **target);
static T_targetRAT_Type private_data_get_rat_target_type(asn1_ctx_t *actx);
static void lte_rrc_call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
static tvbuff_t *tvb_new_composite(void);
static tvbuff_t *tvb_new_real_data(const guint8 *data, guint length, guint reported_length);
static void tvb_composite_append(tvbuff_t *tvb, tvbuff_t *new_tvb);
static void tvb_composite_finalize(tvbuff_t *tvb);
static void *wmem_alloc(void *pool, size_t size);
static void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *name);
static guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
static proto_tree *proto_item_add_subtree(proto_item *item, int ett_index);