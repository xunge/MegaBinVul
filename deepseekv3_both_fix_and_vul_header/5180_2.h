#include <stdint.h>

typedef uint8_t gboolean;
#define TRUE 1
#define FALSE 0

typedef int gint;
typedef unsigned int guint;

typedef struct _tvbuff_t tvbuff_t;
typedef struct _packet_info {
    unsigned num;
} packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _conversation_t conversation_t;

extern gboolean check_rpcap_heur(tvbuff_t *tvb, gboolean tcp);
extern conversation_t* find_or_create_conversation(packet_info *pinfo);
extern void conversation_set_dissector_from_frame_number(conversation_t *conversation, unsigned num, void *handle);
extern void tcp_dissect_pdus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean desegment, int header_size,
                             guint (*get_pdu_len)(tvbuff_t *, packet_info *, gint, void *),
                             void (*dissect_pdu)(tvbuff_t *, packet_info *, proto_tree *, void *),
                             void *data);

extern void* rpcap_tcp_handle;
extern gboolean rpcap_desegment;
extern guint get_rpcap_pdu_len(tvbuff_t *tvb, packet_info *pinfo, gint offset, void *data);
extern void dissect_rpcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);