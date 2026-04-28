#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef int32_t gint;
typedef unsigned int guint;
typedef int gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    struct {
        struct {
            unsigned int visited;
        } flags;
        int num;
    } *fd;
    int current_proto;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

typedef struct {
    guint8 control;
    guint8 level;
    guint8 key_id;
    guint8 nonce;
    guint32 counter;
    guint64 src64;
    guint8 key_seqno;
} zbee_security_packet;

typedef struct {
    guint16 src_pan;
    guint16 src;
    void *nwk;
    void *link;
    void *map_rec;
} zbee_nwk_hints_t;

typedef struct {
    guint16 src_pan;
    guint16 src16;
    void *map_rec;
} ieee802154_hints_t;

typedef struct {
    guint64 addr64;
} ieee802154_map_rec;

typedef struct {
    guint8 *key;
    guint frame_num;
    const char *label;
} key_record_t;

typedef struct {
    int dummy;
} zbee_nwk_map_t;

#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1

extern const char *ZBEE_PROTOABBREV_NWK;
extern const char *IEEE802154_PROTOABBREV_WPAN;
extern guint8 gPREF_zbee_sec_level;
extern void *zbee_pc_keyring;
extern void *zbee_table_nwk_keyring;
extern void *data_handle;
extern zbee_nwk_map_t zbee_nwk_map;

extern int hf_zbee_sec_field;
extern int hf_zbee_sec_key_id;
extern int hf_zbee_sec_nonce;
extern int hf_zbee_sec_counter;
extern int hf_zbee_sec_src64;
extern int hf_zbee_sec_key_seqno;
extern int hf_zbee_sec_mic;
extern int hf_zbee_sec_key;
extern int hf_zbee_sec_decryption_key;
extern int hf_zbee_sec_key_origin;

extern expert_field ei_zbee_sec_extended_source_unknown;
extern expert_field ei_zbee_sec_encrypted_payload;

extern int ett_zbee_sec;
extern int ett_zbee_sec_control;

#define ZBEE_SEC_CONTROL_LEVEL 0x07
#define ZBEE_SEC_CONTROL_KEY 0x18
#define ZBEE_SEC_CONTROL_NONCE 0x20

#define ZBEE_SEC_KEY_LINK 0
#define ZBEE_SEC_KEY_NWK 1
#define ZBEE_SEC_KEY_TRANSPORT 2
#define ZBEE_SEC_KEY_LOAD 3

#define ZBEE_SEC_ENC 0
#define ZBEE_SEC_NONE 1
#define ZBEE_SEC_ENC_MIC32 2
#define ZBEE_SEC_MIC32 3
#define ZBEE_SEC_ENC_MIC64 4
#define ZBEE_SEC_MIC64 5
#define ZBEE_SEC_ENC_MIC128 6
#define ZBEE_SEC_MIC128 7

#define ZBEE_SEC_CONST_KEYSIZE 16
#define ZBEE_SEC_PC_KEY 0xFFFFFFFF

void *p_get_proto_data(void *scope, packet_info *pinfo, int proto_id, int idx);
void *wmem_file_scope(void);
int proto_get_id_by_filter_name(const char *name);
proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *text);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint32 tvb_get_letohl(tvbuff_t *tvb, int offset);
guint64 tvb_get_letoh64(tvbuff_t *tvb, int offset);
void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_hdr, int ett, const int **fields, int encoding);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int start, int length);
int tvb_captured_length(tvbuff_t *tvb);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);
tvbuff_t *tvb_new_subset(tvbuff_t *tvb, int offset, int length, int reported_length);
void expert_add_info(packet_info *pinfo, proto_tree *tree, expert_field *ef);
void call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
void *g_malloc(size_t size);
void g_free(void *ptr);