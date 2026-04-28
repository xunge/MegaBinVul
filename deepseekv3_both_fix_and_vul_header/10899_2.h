#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;

typedef struct tvbuff_t {
    // dummy structure
} tvbuff_t;

typedef struct packet_info {
    struct {
        int num;
        void* cinfo;
    };
} packet_info;

typedef struct proto_tree {
    // dummy structure
} proto_tree;

typedef struct proto_item {
    // dummy structure
} proto_item;

typedef struct wg_packet_info_t {
    struct wg_session_t* session;
} wg_packet_info_t;

typedef struct wg_session_t {
    struct {
        int response_frame;
        int stream;
        int initiator_frame;
        struct {
            int empty_ok;
        } *hs;
    };
} wg_session_t;

typedef struct wg_skey_t {
    // dummy structure
} wg_skey_t;

#define FALSE 0
#define TRUE 1
#define NULL ((void*)0)

extern int hf_wg_sender;
extern int hf_wg_receiver;
extern int hf_wg_encrypted_empty;
extern int hf_wg_handshake_ok;
extern int hf_wg_mac1;
extern int hf_wg_mac2;
extern int hf_wg_stream;
extern int hf_wg_response_to;

#define WG_DECRYPTION_SUPPORTED
#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 0
#define COL_INFO 0
#define PINFO_FD_VISITED(pinfo) 0

void wg_keylog_read(void);
wg_skey_t* wg_mac1_key_probe(tvbuff_t *tvb, int b);
void wg_prepare_handshake_responder_keys(void *hs, tvbuff_t *tvb);
void wg_process_response(tvbuff_t *tvb, void *hs);
void wg_dissect_pubkey(proto_tree *tree, tvbuff_t *tvb, int offset, int b);
void wg_dissect_mac1_pubkey(proto_tree *tree, tvbuff_t *tvb, const wg_skey_t *skey);
wg_session_t* wg_sessions_lookup_initiation(packet_info *pinfo, guint32 id);
void wg_session_update_address(wg_session_t *session, packet_info *pinfo, int b);
void wg_sessions_insert(guint32 id, wg_session_t *session);

void col_append_fstr(void *cinfo, int col, const char *format, ...);
void proto_item_set_generated(proto_item *ti);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_item* proto_tree_add_item_ret_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, guint32 *retval);
proto_item* proto_tree_add_boolean(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int value);
proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);