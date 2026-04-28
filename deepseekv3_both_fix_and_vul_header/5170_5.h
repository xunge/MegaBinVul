#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))
#define TRUE 1
#define FALSE 0
#define BER_CLASS_APP 1
#define COL_INFO 0

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct asn1_ctx_t {
    void *value_ptr;
    void *created_item;
    struct pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct pinfo_t {
    struct cinfo_t *cinfo;
} pinfo_t;

typedef struct cinfo_t {
    char info[256];
} cinfo_t;

struct tcap_private_t {
    uint32_t src_tid;
};

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gboolean;

extern int hf_tcap_tid;
extern int hf_tcap_otid;
extern int ett_otid;
extern struct tcapsrt_info_t *gp_tcapsrt_info;

struct tcapsrt_info_t {
    uint32_t src_tid;
};

int dissect_tcap_OCTET_STRING_SIZE_1_4();

int dissect_ber_tagged_type(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset,
                           int hf_index, int ber_class, int tag, gboolean is_constructed, int (*dissector)());

void PROTO_ITEM_SET_HIDDEN(void *item);
proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, void *null, const char *text);
int dissect_ber_octet_string(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, tvbuff_t **parameter_tvb);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntoh24(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
void col_append_str(cinfo_t *cinfo, int column, const char *str);
void col_append_fstr(cinfo_t *cinfo, int column, const char *format, ...);