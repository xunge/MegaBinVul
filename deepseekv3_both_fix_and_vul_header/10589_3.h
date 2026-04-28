#include <string.h>
#include <arpa/inet.h>

#define MC_ALL_IGMPV3_ROUTERS 0xe0000016
#define _U_ __attribute__((unused))

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef unsigned char guint8;
typedef unsigned int guint32;

#define AT_IPv4 0
#define ENC_NA 0

struct packet_info {
    struct {
        int type;
        void* data;
    } dst;
    void* cinfo;
};

#define COL_PROTOCOL 0
#define COL_INFO 1

extern int proto_msnip;
extern int ett_msnip;
extern int hf_type;
extern const char* msnip_types[];

#define MSNIP_GM 0
#define MSNIP_IS 1
#define MSNIP_RMR 2

extern int dissect_msnip_gm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);
extern int dissect_msnip_is(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);
extern int dissect_msnip_rmr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);

static inline guint32 g_htonl(guint32 hostlong) {
    return htonl(hostlong);
}

static inline void col_set_str(void* cinfo, int column, const char* str) {}
static inline void col_clear(void* cinfo, int column) {}
static inline void col_add_str(void* cinfo, int column, const char* str) {}
static inline proto_item* proto_tree_add_item(proto_tree* tree, int proto, tvbuff_t* tvb, int offset, int length, int encoding) { return NULL; }
static inline proto_tree* proto_item_add_subtree(proto_item* item, int ett) { return NULL; }
static inline guint8 tvb_get_guint8(tvbuff_t* tvb, int offset) { return 0; }
static inline void proto_tree_add_uint(proto_tree* tree, int hf, tvbuff_t* tvb, int offset, int length, guint32 value) {}
static inline void proto_item_set_len(proto_item* item, int length) {}