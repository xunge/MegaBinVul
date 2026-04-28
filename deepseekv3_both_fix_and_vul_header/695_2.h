#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef int gboolean;

#define RESPONSE_FLAGS 0
#define GRYPHON_FRAME_HEADER_LEN 8
#define MSG_HDR_SZ 8
#define GY_FT_CMD 1
#define GY_FT_RESP 2
#define GY_FT_DATA 3
#define GY_FT_EVENT 4
#define GY_FT_MISC 5
#define GY_FT_TEXT 6
#define GY_FT_SIG 7
#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

struct tvbuff;
struct packet_info {
    struct {
        char* cinfo;
    } cinfo[2];
};
struct proto_tree;
struct proto_item;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    int value;
    const char *strptr;
} value_string;

static const value_string frame_type[] = {
    {GY_FT_CMD, "Command"},
    {GY_FT_RESP, "Response"},
    {GY_FT_DATA, "Data"},
    {GY_FT_EVENT, "Event"},
    {GY_FT_MISC, "Misc"},
    {GY_FT_TEXT, "Text"},
    {GY_FT_SIG, "Signal"},
    {0, NULL}
};

extern int proto_gryphon;
extern int ett_gryphon;
extern int ett_gryphon_header;
extern int ett_gryphon_body;
extern int ett_gryphon_flags;
extern int hf_gryphon_data;
extern int hf_gryphon_src;
extern int hf_gryphon_srcchanclient;
extern int hf_gryphon_srcchan;
extern int hf_gryphon_dest;
extern int hf_gryphon_destchanclient;
extern int hf_gryphon_destchan;
extern int hf_gryphon_data_length;
extern int hf_gryphon_type;
extern int hf_gryphon_wait_resp;
extern int hf_gryphon_wait_prev_resp;
extern int hf_gryphon_wait_flags;
extern int hf_gryphon_reserved;
extern int hf_gryphon_padding;

static gboolean is_special_client(unsigned int client) { return 0; }
static int decode_command(tvbuff_t*,int,int,unsigned int,proto_tree*) { return 0; }
static int decode_response(tvbuff_t*,int,unsigned int,proto_tree*) { return 0; }
static int decode_data(tvbuff_t*,int,proto_tree*) { return 0; }
static int decode_event(tvbuff_t*,int,proto_tree*) { return 0; }
static int decode_misc(tvbuff_t*,int,proto_tree*) { return 0; }
static int decode_text(tvbuff_t*,int,int,proto_tree*) { return 0; }
static void col_set_str(packet_info*,int,const char*) {}
static void col_clear(packet_info*,int) {}
static proto_item* proto_tree_add_item(proto_tree*,int,tvbuff_t*,int,int,int) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item*,int) { return NULL; }
static guint8 tvb_get_guint8(tvbuff_t*,int) { return 0; }
static guint16 tvb_get_ntohs(tvbuff_t*,int) { return 0; }
static void set_actual_length(tvbuff_t*,int) {}
static const char* val_to_str_const(unsigned int,const value_string*,const char*) { return NULL; }
static const char* try_val_to_str(unsigned int,const value_string*) { return NULL; }
static proto_tree* proto_tree_add_subtree(proto_tree*,tvbuff_t*,int,int,int,proto_item**,const char*) { return NULL; }
static void proto_tree_add_bitmask(proto_tree*,tvbuff_t*,int,int,int,const int**,int) {}