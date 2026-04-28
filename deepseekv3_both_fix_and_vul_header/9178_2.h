#include <stdint.h>
#include <string.h>

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gboolean;
typedef char gchar;
#define TRUE 1
#define FALSE 0
#define GPOINTER_TO_UINT(p) ((guint32)(uintptr_t)(p))

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void *layers;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct wmem_list_frame_t wmem_list_frame_t;

typedef struct _sctp_fragment {
    guint32 tsn;
    guint16 stream_id;
    guint32 stream_seq_num;
    guint8 b_bit;
    guint8 e_bit;
    guint8 u_bit;
    guint32 ppi;
    gboolean is_idata;
    tvbuff_t *tvb;
    packet_info *pinfo;
    proto_tree *chunk_tree;
} sctp_fragment;

extern int exported_pdu_tap;
extern size_t tvb_reported_length(tvbuff_t *tvb);
extern size_t tvb_captured_length(tvbuff_t *tvb);
extern sctp_fragment *add_fragment(tvbuff_t *payload_tvb, packet_info *pinfo, proto_tree *chunk_tree, guint32 tsn, guint16 stream_id, guint32 stream_seq_num, guint8 b_bit, guint8 e_bit, guint8 u_bit, guint32 ppi, gboolean is_idata);
extern tvbuff_t *fragment_reassembly(tvbuff_t *payload_tvb, sctp_fragment *fragment, packet_info *pinfo, proto_tree *chunk_tree, guint16 stream_id, guint32 stream_seq_num, guint8 u_bit);
extern gboolean dissect_payload(tvbuff_t *new_tvb, packet_info *pinfo, proto_tree *tree, guint32 ppi);
extern const char *proto_get_protocol_filter_name(guint32 proto_id);
extern gboolean have_tap_listener(int tap_id);
extern void export_sctp_data_chunk(packet_info *pinfo, tvbuff_t *payload_tvb, const char *proto_name);

extern wmem_list_frame_t *wmem_list_tail(void *list);
extern wmem_list_frame_t *wmem_list_frame_next(wmem_list_frame_t *frame);
extern void *wmem_list_frame_data(wmem_list_frame_t *frame);