#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    struct {
        struct {
            unsigned int visited;
        } flags;
        unsigned int num;
    } *fd;
    int current_proto;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct _zbee_security_packet {
    uint8_t control;
    uint8_t level;
    uint8_t key_id;
    uint8_t nonce;
    uint32_t counter;
    uint64_t src64;
    uint8_t key_seqno;
} zbee_security_packet;

typedef struct _key_record_t {
    uint8_t key[16];
    uint32_t frame_num;
    char *label;
} key_record_t;

typedef struct _zbee_nwk_hints_t {
    uint16_t src;
    uint16_t src_pan;
    key_record_t *nwk;
    key_record_t *link;
    void *map_rec;
} zbee_nwk_hints_t;

typedef struct _ieee802154_hints_t {
    uint16_t src16;
    uint16_t src_pan;
    void *map_rec;
} ieee802154_hints_t;

typedef struct _ieee802154_map_rec {
    uint16_t addr16;
    uint16_t pan;
    uint64_t addr64;
    unsigned proto;
    uint32_t frame_num;
} ieee802154_map_rec;

typedef struct {
    /* dummy structure for zbee_nwk_map */
} zbee_nwk_map_t;

typedef unsigned int guint;
typedef int gint;
typedef uint8_t guint8;
typedef int gboolean;

#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1

extern const char ZBEE_PROTOABBREV_NWK[];
extern const char IEEE802154_PROTOABBREV_WPAN[];
extern int hf_zbee_sec_key_id;
extern int hf_zbee_sec_nonce;
extern int hf_zbee_sec_field;
extern int hf_zbee_sec_counter;
extern int hf_zbee_sec_src64;
extern int hf_zbee_sec_key_seqno;
extern int hf_zbee_sec_mic;
extern int hf_zbee_sec_key;
extern int hf_zbee_sec_decryption_key;
extern int hf_zbee_sec_key_origin;
extern int ett_zbee_sec;
extern int ett_zbee_sec_control;
extern void *ei_zbee_sec_extended_source_unknown;
extern void *ei_zbee_sec_encrypted_payload;
extern void *data_handle;
extern void *zbee_table_nwk_keyring;
extern void *zbee_pc_keyring;
extern uint8_t gPREF_zbee_sec_level;
extern zbee_nwk_map_t zbee_nwk_map;

/* Function prototypes */
void *wmem_file_scope(void);
void *wmem_packet_scope(void);
int proto_get_id_by_filter_name(const char *name);
void *p_get_proto_data(void *scope, packet_info *pinfo, int proto_id, int idx);
proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *text);
uint8_t tvb_get_guint8(tvbuff_t *tvb, int offset);
uint32_t tvb_get_letohl(tvbuff_t *tvb, int offset);
uint64_t tvb_get_letoh64(tvbuff_t *tvb, int offset);
int tvb_captured_length(tvbuff_t *tvb);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);
tvbuff_t *tvb_new_child_real_data(tvbuff_t *tvb, const uint8_t *data, int length, int reported_length);
void tvb_set_free_cb(tvbuff_t *tvb, void (*free_cb)(void *));
void *tvb_memdup(void *scope, tvbuff_t *tvb, int offset, int length);
void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_index, int ett, const int **fields, int encoding);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, uint32_t value);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_bytes(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const uint8_t *value);
void proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *value);
void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, void *ei, tvbuff_t *tvb, int start, int length);
void expert_add_info(packet_info *pinfo, proto_tree *tree, void *ei);
void call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *name);
void *ieee802154_addr_update(zbee_nwk_map_t *map, uint16_t addr16, uint16_t pan, uint64_t addr64, unsigned proto, uint32_t frame_num);
uint8_t zbee_get_bit_field(uint8_t value, uint8_t mask);
void *g_malloc(size_t size);
void g_free(void *ptr);

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