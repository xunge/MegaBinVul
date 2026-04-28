#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    void *cinfo;
    int num;
} packet_info;

typedef struct {
    struct wg_session_t *session;
} wg_packet_info_t;

typedef struct wg_session_t {
    int stream;
    int initiator_frame;
    int response_frame;
} wg_session_t;

#define AUTH_TAG_LENGTH 16
#define PINFO_FD_VISITED(pinfo) 0
#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 0
#define COL_INFO 0
#define FALSE 0

typedef uint32_t guint32;

extern int hf_wg_receiver;
extern int hf_wg_nonce;
extern int hf_wg_encrypted_cookie;
extern int hf_wg_stream;
extern int hf_wg_response_to;

wg_session_t *wg_sessions_lookup_initiation(packet_info *pinfo, guint32 receiver_id);
void wg_session_update_address(wg_session_t *session, packet_info *pinfo, int is_initiator);
void proto_tree_add_item_ret_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, guint32 *retval);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
void proto_item_set_generated(proto_item *item);
void col_append_fstr(void *cinfo, int column, const char *format, ...);