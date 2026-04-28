#include <stdint.h>
#include <string.h>

#define BITS_PER_BYTE 8
#define CHUNK_LENGTH_MIN 5
#define TAG_END_OF_ATTRIBUTES 0x03
#define PRINT_JOB 0x02
#define SEND_DOCUMENT 0x04
#define HTTP 80
#define NEWLINE '\n'
#define RETURN_NEWLINE "\r\n"
#define CHUNKED_END "0\r\n\r\n"
#define ENDPOINT_TCP 0
#define COL_INFO 0
#define TRUE 1
#define FALSE 0

#define MSP_HAS_DOCUMENT 0x01
#define MSP_DOCUMENT_TRUNCATED 0x02

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned char guchar;
typedef int gboolean;
typedef char gchar;

typedef struct {
    int num;
    struct {
        int visited;
    } *fd;
    int fragmented;
    int can_desegment;
    void *cinfo;
    void *src;
    void *dst;
    int srcport;
    int destport;
} packet_info;

typedef struct {
    int last_frame;
} conversation_t;

typedef struct ippusb_analysis {
    void *multisegment_pdus;
} ippusb_analysis;

typedef struct ippusb_multisegment_pdu {
    guint32 first_frame;
    guint32 nxtpdu;
    gboolean is_ipp;
    gboolean finished;
    gboolean reassembled;
    guint8 document;
    guint32 running_size;
} ippusb_multisegment_pdu;

typedef struct {
    int dummy;
} fragment_head;

typedef struct {
    int dummy;
} tvbuff_t;

typedef struct {
    int dummy;
} proto_tree;

static int ippusb_last_pdu = -1;
static gboolean global_ippusb_reassemble = TRUE;
static void *ippusb_dissector_table;
static proto_tree *proto_ippusb;
static fragment_head ippusb_reassembly_table;
static const gchar *ippusb_frag_items[] = { NULL };
static tvbuff_t *return_newline_tvb;

/* Function prototypes */
static gint tvb_reported_length(tvbuff_t *tvb);
static gint tvb_captured_length(tvbuff_t *tvb);
static conversation_t *find_conversation_pinfo(packet_info *pinfo, int arg);
static conversation_t *conversation_new(int num, void *src, void *dst, int type, 
                                       int srcport, int destport, int arg);
static ippusb_analysis *get_ippusb_conversation_data(conversation_t *conv, packet_info *pinfo);
static guint tvb_find_line_end(tvbuff_t *tvb, gint offset, gint length, gint *next_offset, gboolean arg);
static const guchar *tvb_get_ptr(tvbuff_t *tvb, gint offset, gint length);
static guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
static guint8 tvb_get_bits8(tvbuff_t *tvb, gint bit_offset, gint no_of_bits);
static gboolean is_http_header(guint length, const guchar *line);
static void proto_tree_add_item(proto_tree *tree, proto_tree *proto, tvbuff_t *tvb, 
                              gint offset, gint length, gint encoding);
static int dissector_try_uint_new(void *dissector_table, int proto, tvbuff_t *tvb,
                                packet_info *pinfo, proto_tree *tree, gboolean arg, void *data);
static ippusb_multisegment_pdu *pdu_store(packet_info *pinfo, void *tree, int num, 
                                        gboolean is_ipp, int document);
static fragment_head *fragment_add_check(fragment_head *table, tvbuff_t *tvb, gint offset,
                             packet_info *pinfo, guint32 id, void *data, 
                             guint32 fragment_offset, guint32 fragment_length,
                             gboolean more_frags);
static void *wmem_tree_lookup32_le(void *tree, guint32 key);
static tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, gint offset, gint length);
static fragment_head *fragment_get_reassembled_id(fragment_head *table, 
                                                packet_info *pinfo, guint32 id);
static tvbuff_t *process_reassembled_data(tvbuff_t *tvb, gint offset, 
                                        packet_info *pinfo, const char *name,
                                        fragment_head *head, const gchar **items,
                                        void *arg, proto_tree *tree);
static void col_append_fstr(void *cinfo, int column, const char *format);

/* Helper macros */
#define GUINT_TO_POINTER(u) ((void *)(uintptr_t)(u))