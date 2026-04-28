#include <string.h>
#include <arpa/inet.h>

#define MC_RGMP 0
#define AT_IPv4 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 0

enum {
    COL_PROTOCOL,
    COL_INFO
};

typedef unsigned char guint8;
typedef unsigned int guint32;

typedef struct {
    int type;
    void *data;
} address;

typedef struct {
    address dst;
    void *cinfo;
} packet_info;

typedef struct {
    int COL_PROTOCOL;
    int COL_INFO;
} column_info;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern proto_item *proto_tree_add_item(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int length, int enc);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern void col_set_str(column_info *cinfo, int col, const char *str);
extern void col_clear(column_info *cinfo, int col);
extern void col_add_str(column_info *cinfo, int col, const char *str);
extern void proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, guint8 value);
extern const char *val_to_str(guint8 value, const void *table, const char *fmt);
extern void igmp_checksum(proto_tree *tree, tvbuff_t *tvb, int hf, int hf_bad, packet_info *pinfo, int offset);

static int proto_rgmp;
static int ett_rgmp;
static int hf_type;
static int hf_reserved;
static int hf_checksum;
static int hf_checksum_bad;
static int hf_maddr;
static const void *rgmp_types;

#define _U_
#define g_htonl htonl