#include <stdlib.h>
#include <string.h>

typedef unsigned int guint;
typedef int gint;
typedef unsigned char guint8;
typedef unsigned short guint16;
typedef unsigned long guint32;
typedef unsigned long long guint64;
typedef int gboolean;

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
#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1
#define ZBEE_SEC_CONST_KEYSIZE 16
#define ZBEE_SEC_PC_KEY 0xFFFFFFFF
#define ReportedBoundsError 1

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
    guint8 *key;
    guint frame_num;
    const char *label;
} key_record_t;

typedef struct {
    guint16 src_pan;
    guint16 src;
    key_record_t *nwk;
    key_record_t *link;
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
    struct {
        unsigned visited:1;
    } flags;
    int num;
} fd_struct;

typedef struct {
    fd_struct *fd;
    int current_proto;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t {
    int length;
} tvbuff_t;
typedef struct proto_item proto_item;
typedef struct wmem_allocator_t wmem_allocator_t;
typedef struct dissector_handle_t {
    int dummy;
} dissector_handle_t;
typedef struct GHashTable GHashTable;
typedef struct GSList {
    void *data;
    struct GSList *next;
} GSList;

extern const char *ZBEE_PROTOABBREV_NWK;
extern const char *IEEE802154_PROTOABBREV_WPAN;
extern int ett_zbee_sec;
extern int hf_zbee_sec_field;
extern int ett_zbee_sec_control;
extern int hf_zbee_sec_counter;
extern int hf_zbee_sec_src64;
extern int hf_zbee_sec_key_seqno;
extern int hf_zbee_sec_mic;
extern int hf_zbee_sec_key;
extern int hf_zbee_sec_decryption_key;
extern int hf_zbee_sec_key_origin;
extern int hf_zbee_sec_key_id;
extern int hf_zbee_sec_nonce;
extern void *ei_zbee_sec_extended_source_unknown;
extern void *ei_zbee_sec_encrypted_payload;
extern dissector_handle_t data_handle;
extern GHashTable *zbee_table_nwk_keyring;
extern GSList *zbee_pc_keyring;
extern guint8 gPREF_zbee_sec_level;
extern void *zbee_nwk_map;

/* Function prototypes */
void *p_get_proto_data(wmem_allocator_t *scope, packet_info *pinfo, int proto_id, int data_id);
wmem_allocator_t *wmem_file_scope(void);
int proto_get_id_by_filter_name(const char *name);
proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *text);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint32 tvb_get_letohl(tvbuff_t *tvb, int offset);
guint64 tvb_get_letoh64(tvbuff_t *tvb, int offset);
int tvb_captured_length(tvbuff_t *tvb);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);
tvbuff_t *tvb_new_subset(tvbuff_t *tvb, int offset, int length, int reported_length);
void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, int ett, const int **fields, int encoding);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, void *ei, tvbuff_t *tvb, int start, int length);
void expert_add_info(packet_info *pinfo, proto_tree *tree, void *ei);
void call_dissector(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
void *ieee802154_addr_update(void *map, guint16 short_addr, guint16 pan_id, guint64 long_addr, int proto, int frame_num);
guint8 zbee_get_bit_field(guint8 value, guint8 mask);
void THROW(int error);