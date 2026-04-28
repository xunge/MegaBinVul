#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/time.h>

typedef uint32_t guint32;
typedef uint64_t guint64;
typedef uint8_t guint8;
typedef int8_t gint8;
typedef int gboolean;
typedef unsigned int guint;
typedef int gint;
typedef uint16_t guint16;
#define TRUE 1
#define FALSE 0

typedef struct {
    guint32 addr;
} address;

typedef struct {
    time_t secs;
    int nsecs;
} nstime_t;

typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info {
    void *cinfo;
    guint32 num;
    address src;
    address dst;
    guint16 srcport;
    guint16 destport;
    nstime_t abs_ts;
    gboolean can_desegment;
    guint32 desegment_offset;
    guint32 desegment_len;
} packet_info;

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _conversation conversation_t;
typedef struct _expert_field expert_field;

typedef struct tcpinfo {
    guint32 seq;
    guint32 lastackseq;
} tcpinfo_t;

typedef enum {
    DIGEST_TYPE_MD5,
    DIGEST_TYPE_SHA1,
    DIGEST_TYPE_SHA256,
    DIGEST_TYPE_UNKNOWN
} digest_type_t;

#define DIGEST_LEN 32
#define COMPRESSION_GZIP 1
#define PT_TCP 0
#define DESEGMENT_UNTIL_FIN 0
#define ENC_NA 0
#define ENC_ASCII 0

typedef struct ldss_file {
    digest_type_t digest_type;
    guint8 *digest;
} ldss_file_t;

typedef struct ldss_file_request {
    guint64 size;
    guint64 offset;
    gint8 compression;
    guint32 num;
    nstime_t ts;
    ldss_file_t *file;
} ldss_file_request_t;

typedef enum {
    MESSAGE_ID_WILLSEND
} message_id_t;

typedef struct ldss_broadcast {
    message_id_t message_id;
    guint64 size;
    guint64 offset;
    gint8 compression;
    guint32 num;
    nstime_t ts;
    ldss_file_t *file;
} ldss_broadcast_t;

typedef struct ldss_transfer_info {
    ldss_broadcast_t *broadcast;
    ldss_file_request_t *req;
    ldss_file_t *file;
    guint32 resp_num;
    nstime_t resp_ts;
} ldss_transfer_info_t;

typedef struct {
    guint8 *data;
    guint32 len;
} GByteArray;

#define DISSECTOR_ASSERT(expr)
#define PROTO_ITEM_SET_GENERATED(ti)
#define COL_PROTOCOL 0
#define COL_INFO 0

extern int proto_ldss;
extern int hf_ldss_size;
extern int hf_ldss_offset;
extern int hf_ldss_compression;
extern int hf_ldss_digest_type;
extern int hf_ldss_digest;
extern int hf_ldss_file_data;
extern int hf_ldss_response_in;
extern int hf_ldss_response_to;
extern int hf_ldss_transfer_response_time;
extern int hf_ldss_initiated_by;
extern int hf_ldss_transfer_completed_in;
extern int ett_ldss_transfer;
extern int ett_ldss_transfer_req;
extern expert_field ei_ldss_unrecognized_line;

static inline guint MIN(guint a, guint b) { return a < b ? a : b; }

void *wmem_file_scope(void);
void *wmem_packet_scope(void);
void *wmem_alloc0(void *scope, size_t size);
void *wmem_new0(void *scope, size_t size);
guint32 tvb_reported_length(const tvbuff_t *tvb);
guint32 tvb_captured_length(const tvbuff_t *tvb);
gboolean tvb_offset_exists(const tvbuff_t *tvb, gint offset);
gint tvb_find_line_end(const tvbuff_t *tvb, gint offset, gint maxlength, gint *next_offset, gboolean want_cr);
const guint8 *tvb_memdup(void *scope, const tvbuff_t *tvb, gint offset, gint length);
const guint8 *tvb_get_ptr(const tvbuff_t *tvb, gint offset, gint length);
const char *tvb_format_text(const tvbuff_t *tvb, gint offset, gint length);
const guint8 *tvb_get_string_enc(void *scope, const tvbuff_t *tvb, gint offset, gint length, int encoding);
proto_item *proto_tree_add_item(proto_tree *tree, int proto, const tvbuff_t *tvb, gint offset, gint length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
proto_item *proto_tree_add_subtree(proto_tree *tree, const tvbuff_t *tvb, gint offset, gint length, int ett, proto_item **ti, const char *text);
proto_item *proto_tree_add_uint(proto_tree *tree, int hf, const tvbuff_t *tvb, gint offset, gint length, guint32 value);
proto_item *proto_tree_add_uint64(proto_tree *tree, int hf, const tvbuff_t *tvb, gint offset, gint length, guint64 value);
proto_item *proto_tree_add_bytes(proto_tree *tree, int hf, const tvbuff_t *tvb, gint offset, gint length, const guint8 *value);
proto_item *proto_tree_add_bytes_format(proto_tree *tree, int hf, const tvbuff_t *tvb, gint offset, gint length, const guint8 *value, const char *fmt, ...);
proto_item *proto_tree_add_time(proto_tree *tree, int hf, const tvbuff_t *tvb, gint offset, gint length, const nstime_t *value);
proto_item *proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, const tvbuff_t *tvb, gint offset, gint length);
conversation_t *find_conversation(guint32 num, const address *src, const address *dst, int proto, guint16 srcport, guint16 destport, guint32 options);
void *conversation_get_proto_data(conversation_t *conv, int proto);
void col_set_str(void *cinfo, int column, const char *str);
void col_add_fstr(void *cinfo, int column, const char *fmt, ...);
void nstime_delta(nstime_t *dst, const nstime_t *a, const nstime_t *b);
guint64 g_ascii_strtoull(const char *nptr, char **endptr, int base);
GByteArray *g_byte_array_new(void);
void g_byte_array_free(GByteArray *array, gboolean free_segment);
void hex_str_to_bytes(const guint8 *hex_str, GByteArray *bytes, gboolean require_even);
void prepare_ldss_transfer_conv(ldss_broadcast_t *broadcast);
void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *name);
tvbuff_t *tvb_child_uncompress(tvbuff_t *parent, tvbuff_t *tvb, int offset, int length);
#define wmem_new0(scope, type) ((type *)wmem_alloc0(scope, sizeof(type)))