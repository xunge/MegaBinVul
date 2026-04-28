#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define WG_TYPE_HANDSHAKE_INITIATION 1
#define WG_TYPE_HANDSHAKE_RESPONSE 2
#define WG_TYPE_COOKIE_REPLY 3
#define WG_TYPE_TRANSPORT_DATA 4

typedef uint32_t guint32;
typedef bool gboolean;
#define FALSE false
#define TRUE true

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct conversation_t conversation_t;
typedef void* dissector_handle_t;

extern size_t tvb_reported_length(tvbuff_t *tvb);
extern uint8_t tvb_get_guint8(tvbuff_t *tvb, int offset);
extern uint32_t tvb_get_ntoh24(tvbuff_t *tvb, int offset);
extern conversation_t *find_or_create_conversation(packet_info *pinfo);
extern void conversation_set_dissector(conversation_t *conversation, dissector_handle_t handle);
extern void dissect_wg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);

extern dissector_handle_t wg_handle;

#define _U_ __attribute__((unused))