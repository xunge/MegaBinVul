#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))
#define TRUE 1
#define FALSE 0

typedef enum {
    BER_CLASS_UNIV = 0,
    BER_CLASS_APP = 1,
    BER_CLASS_CONTEXT = 2,
    BER_CLASS_PRIV = 3
} ber_class_t;

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct tcap_private_t {
    uint32_t dst_tid;
};

struct tcapsrt_info {
    uint32_t dst_tid;
};

struct asn1_ctx {
    void *value_ptr;
    proto_item *created_item;
    struct pinfo *pinfo;
};

struct pinfo {
    struct column_info *cinfo;
};

struct column_info {
    char *col_data[32];
};

enum {
    COL_INFO = 0
};

extern struct tcapsrt_info *gp_tcapsrt_info;
extern int hf_tcap_tid;
extern int hf_tcap_dtid;
extern int ett_dtid;

typedef int gboolean;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef unsigned int guint;

/* Function prototypes */
int dissect_ber_tagged_type(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, int, ber_class_t, int, gboolean, int (*)(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int));
int dissect_ber_octet_string(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int, int, tvbuff_t**);
void PROTO_ITEM_SET_HIDDEN(proto_item*);
proto_tree* proto_tree_add_subtree(proto_tree*, tvbuff_t*, int, int, int, void*, const char*);
guint tvb_reported_length_remaining(tvbuff_t*, int);
guint8 tvb_get_guint8(tvbuff_t*, int);
guint16 tvb_get_ntohs(tvbuff_t*, int);
guint32 tvb_get_ntoh24(tvbuff_t*, int);
guint32 tvb_get_ntohl(tvbuff_t*, int);
void col_append_str(struct column_info*, int, const char*);
void col_append_fstr(struct column_info*, int, const char*, ...);

/* Dummy function for OCTET_STRING dissector */
int dissect_tcap_OCTET_STRING_SIZE_1_4(gboolean, asn1_ctx_t*, proto_tree*, tvbuff_t*, int);