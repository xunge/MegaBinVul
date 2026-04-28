#include <stdint.h>
#include <stddef.h>

#define AUTH_TAG_LENGTH 16
#define G_GUINT64_FORMAT "lu"

typedef struct wg_packet_info_t {
    struct wg_session_t *session;
    int receiver_is_initiator;
} wg_packet_info_t;

typedef struct wg_session_t {
    int stream;
    void *hs;
} wg_session_t;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int hf_wg_receiver;
extern int hf_wg_counter;
extern int hf_wg_encrypted_packet;
extern int hf_wg_stream;
extern expert_field ei_wg_bad_packet_length;
extern expert_field ei_wg_keepalive;

#define PINFO_FD_VISITED(pinfo) (0)
#define COL_INFO 0
#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 0

typedef uint32_t guint32;
typedef uint64_t guint64;
typedef int gint;
typedef int gboolean;