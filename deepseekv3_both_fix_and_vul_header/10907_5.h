#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct packet_info {
    struct wmem_allocator_t *pool;
};

typedef struct wmem_allocator_t wmem_allocator_t;

struct asn1_ctx_t {
    proto_item *created_item;
    struct packet_info *pinfo;
};

enum {
    ett_lte_rrc_siPsiSibContainer
};

enum SI_OrPSI_GERAN {
    SI_OrPSI_GERAN_si,
    SI_OrPSI_GERAN_psi
};

typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gboolean;

#define FALSE 0
#define TRUE 1
#define _U_ __attribute__((unused))

extern int dissect_per_octet_string(tvbuff_t *tvb, int offset, struct asn1_ctx_t *actx, proto_tree *tree, int hf_index, int min_len, int max_len, gboolean has_extension, tvbuff_t **octet_str_tvb);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern enum SI_OrPSI_GERAN private_data_get_si_or_psi_geran(struct asn1_ctx_t *actx);
extern void lte_rrc_call_dissector(void *handle, tvbuff_t *tvb, struct packet_info *pinfo, proto_tree *tree);
extern void add_new_data_source(struct packet_info *pinfo, tvbuff_t *tvb, const char *name);
extern tvbuff_t *tvb_new_composite(void);
extern void tvb_composite_append(tvbuff_t *tvb, tvbuff_t *segment);
extern void tvb_composite_finalize(tvbuff_t *tvb);
extern tvbuff_t *tvb_new_real_data(const guint8 *data, guint length, guint reported_length);
extern void *wmem_alloc(wmem_allocator_t *allocator, size_t size);

extern void *gsm_a_dtap_handle;
extern void *gsm_rlcmac_dl_handle;

typedef struct asn1_ctx_t asn1_ctx_t;