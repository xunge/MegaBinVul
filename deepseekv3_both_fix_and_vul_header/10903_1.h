#include <stdint.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 1
#define AUTH_TAG_LENGTH 16

typedef uint32_t guint32;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    int num;
    void *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct wg_skey_t wg_skey_t;
typedef struct wg_handshake_state_t wg_handshake_state_t;

typedef struct wg_session_t {
    int initiator_frame;
    int response_frame;
    int stream;
    wg_handshake_state_t *hs;
} wg_session_t;

typedef struct wg_packet_info_t {
    wg_session_t *session;
} wg_packet_info_t;

extern int hf_wg_sender;
extern int hf_wg_encrypted_static;
extern int hf_wg_encrypted_timestamp;
extern int hf_wg_mac1;
extern int hf_wg_mac2;
extern int hf_wg_stream;
extern int hf_wg_response_in;

#define PINFO_FD_VISITED(pinfo) (0)
#define COL_INFO 0