#include <string.h>
#include <arpa/inet.h>

#define MC_ALL_ROUTERS 0xe0000016
#define _U_ __attribute__((unused))

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct value_string {
    unsigned int value;
    const char *strptr;
} value_string;

typedef unsigned char guint8;
typedef unsigned int guint32;

#define AT_IPv4 0
#define ENC_NA 0

extern int proto_mrdisc;
extern int ett_mrdisc;
extern int hf_type;
extern value_string mrdisc_types[];
extern int dissect_mrdisc_mra(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);
extern int dissect_mrdisc_mrst(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);

#define MRDISC_MRA 0
#define MRDISC_MRS 1
#define MRDISC_MRT 2

struct packet_info {
    struct {
        int type;
        void *data;
    } dst;
    void *cinfo;
};

#define COL_PROTOCOL 0
#define COL_INFO 1

static inline void col_set_str(void *cinfo, int col, const char *str) {}
static inline void col_clear(void *cinfo, int col) {}
static inline void col_add_str(void *cinfo, int col, const char *str) {}
static inline proto_item *proto_tree_add_item(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int length, int enc) { return NULL; }
static inline proto_tree *proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static inline guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static inline const char *val_to_str(guint8 val, value_string *vs, const char *fmt) { return ""; }
static inline void proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, guint32 value) {}