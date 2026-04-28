#include <stdint.h>
#include <stddef.h>

#define BLIP_BODY_CHECKSUM_SIZE 4
#define FT_VARINT_MAX_LEN 10
#define _U_
#define TRUE 1
#define FALSE 0

#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_VARINT_PROTOBUF 1
#define ENC_UTF_8 2
#define ENC_BIG_ENDIAN 3
#define G_GUINT64_FORMAT "lu"

typedef uint64_t guint64;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int32_t gint;
typedef unsigned int guint;
typedef int gboolean;
typedef char gchar;

typedef struct blip_conversation_entry {
    guint64 last_message_num;
} blip_conversation_entry_t;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    struct {
        int cinfo;
    } *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef void* wmem_allocator_t;

extern int proto_blip;
extern int ett_blip;
extern int hf_blip_message_number;
extern int hf_blip_frame_flags;
extern int hf_blip_properties_length;
extern int hf_blip_properties;
extern int hf_blip_message_body;
extern int hf_blip_checksum;

static wmem_allocator_t* wmem_packet_scope();
static gchar* wmem_strdup_printf(wmem_allocator_t* alloc, const char* fmt, ...);
static gchar* wmem_strconcat(wmem_allocator_t* alloc, ...);
static void col_set_str(int cinfo, int col, const char* str);
static void col_clear(int cinfo, int col);
static void col_add_str(int cinfo, int col, const char* str);
static proto_item* proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, int encoding);
static proto_tree* proto_item_add_subtree(proto_item* item, int ett);
static guint tvb_get_varint(tvbuff_t* tvb, gint offset, gint max_len, guint64* value, int encoding);
static void proto_tree_add_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, guint32 value);
static void proto_tree_add_string(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, const char* str);
static guint8* tvb_get_string_enc(wmem_allocator_t* alloc, tvbuff_t* tvb, gint offset, gint length, int encoding);
static gint tvb_reported_length_remaining(const tvbuff_t* tvb, gint offset);
static gint tvb_reported_length(const tvbuff_t* tvb);
static gint tvb_captured_length(const tvbuff_t* tvb);

static const gchar* get_message_type(guint64 flags);
static gboolean is_ack_message(guint64 flags);
static int handle_ack_message(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, gint offset, guint64 flags);
static blip_conversation_entry_t* get_blip_conversation(packet_info* pinfo);
static gboolean is_first_frame_in_msg(blip_conversation_entry_t* entry, packet_info* pinfo, guint64 flags, guint64 message_num);
static gboolean is_compressed(guint64 flags);
#ifdef HAVE_ZLIB
static tvbuff_t* decompress(packet_info* pinfo, tvbuff_t* tvb, gint offset, gint length);
#endif