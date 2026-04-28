#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stddef.h>

#define TCP_A_RETRANSMISSION 0x01
#define MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT 0x01
#define TCP_FLOW_REASSEMBLE_UNTIL_FIN 0x01
#define FD_PARTIAL_REASSEMBLY 0x01
#define DESEGMENT_ONE_MORE_SEGMENT (-1)
#define DESEGMENT_UNTIL_FIN (-2)
#define COL_PROTOCOL 0
#define COL_INFO 1
#define FALSE 0
#define TRUE 1

typedef uint32_t guint32;
typedef int32_t gint32;
typedef bool gboolean;
typedef int32_t gint;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    void* cinfo;
    int num;
    struct timeval abs_ts;
    int desegment_offset;
    int desegment_len;
    int can_desegment;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct fragment_head {
    int reassembled_in;
    int flags;
    int datalen;
    void* tvb_data;
} fragment_head;

struct tcp_analysis {
    struct tcp_flow *fwd;
    struct tcp_analysis *ta;
    guint32 flags;
};

struct tcp_flow {
    void *multisegment_pdus;
    guint32 flags;
};

struct tcp_multisegment_pdu {
    guint32 seq;
    guint32 nxtpdu;
    guint32 first_frame;
    guint32 last_frame;
    struct timeval last_frame_time;
    guint32 flags;
};

struct tcpinfo {
    guint32 seq;
    gboolean is_reassembled;
};

extern int col_get_writable(void* cinfo, int column);
extern void col_append_sep_str(void* cinfo, int column, const char* sep, const char* str);
extern void col_set_str(void* cinfo, int column, const char* str);
extern void col_set_fence(void* cinfo, int column);
extern void col_set_writable(void* cinfo, int column, gboolean writable);
extern void* wmem_tree_lookup32(void* tree, guint32 key);
extern void* wmem_tree_lookup32_le(void* tree, guint32 key);
extern fragment_head *fragment_get(void *table, packet_info *pinfo, guint32 id, const void *data);
extern fragment_head *fragment_add(void *table, tvbuff_t *tvb, int offset, packet_info *pinfo, guint32 id, const void *data, guint32 frag_offset, guint32 frag_data_len, gboolean more_frags);
extern void fragment_set_partial_reassembly(void *table, packet_info *pinfo, guint32 id, const void *data);
extern void print_tcp_fragment_tree(fragment_head *ipfd_head, proto_tree *tree, proto_tree *tcp_tree, packet_info *pinfo, tvbuff_t *next_tvb);
extern struct tcp_multisegment_pdu *pdu_store_sequencenumber_of_next_pdu(packet_info *pinfo, guint32 seq, guint32 nxtseq, void *multisegment_pdus);
extern void process_tcp_payload(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, proto_tree *tcp_tree, guint32 sport, guint32 dport, guint32 seq, guint32 nxtseq, gboolean is_tcp_segment, struct tcp_analysis *tcpd, struct tcpinfo *tcpinfo);
extern int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
extern int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
extern tvbuff_t *tvb_new_chain(tvbuff_t *tvb, void *data);
extern void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *name);
extern void remove_last_data_source(packet_info *pinfo);
extern void proto_tree_add_bytes_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const void* data_ptr, const char *format, ...);
extern proto_item *proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
extern void PROTO_ITEM_SET_GENERATED(proto_item *item);
extern const char *plurality(int n, const char *singular, const char *plural);

extern int hf_tcp_reassembled_in;
extern int hf_tcp_segment_data;
extern void *tcp_reassembly_table;