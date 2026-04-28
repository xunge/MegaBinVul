#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int guint;
typedef unsigned char guint8;
typedef uint16_t guint16;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define ENC_ASCII 2
#define COL_INFO 0

typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct packet_info {
    void *pool;
    void *cinfo;
} packet_info;
typedef struct expert_field expert_field;
typedef struct wmem_pool wmem_pool_t;

extern int hf_bt_dht_peers;
extern int hf_bt_dht_peer;
extern int hf_ip;
extern int hf_ip6;
extern int hf_port;
extern int hf_truncated_data;
extern int hf_bencoded_list_terminator;
extern int ett_bt_dht_peers;
extern expert_field ei_invalid_len;

static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, 
                             guint offset, guint length, int encoding);
static proto_tree* proto_item_add_subtree(proto_item *item, int ett);
static guint8 tvb_get_guint8(tvbuff_t *tvb, guint offset);
static void proto_item_append_text(proto_item *item, const char *format, ...);
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb,
                              guint offset, guint length, int encoding);
static char* tvb_ip_to_str(wmem_pool_t *pool, tvbuff_t *tvb, guint offset);
static guint16 tvb_get_ntohs(tvbuff_t *tvb, guint offset);
static char* tvb_ip6_to_str(wmem_pool_t *pool, tvbuff_t *tvb, guint offset);
static void proto_item_set_text(proto_item *item, const char *format, ...);
static void col_append_fstr(void *cinfo, int column, const char *format, ...);
static char* wmem_strdup_printf(wmem_pool_t *pool, const char *format, ...);
static int bencoded_string_length(packet_info *pinfo, tvbuff_t *tvb, guint *offset);