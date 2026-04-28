#include <stdint.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef int gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct dissector_handle_t dissector_handle_t;

extern int hf_plc_mb_mc_reserved;
extern int hf_plc_mb_mc_pspf_present;
extern int hf_plc_mb_mc_psp;
extern dissector_handle_t* docsis_handle;

#define ENC_BIG_ENDIAN 0
#define FALSE 0
#define COL_INFO 0

struct packet_info {
    struct {
        char* info;
    } *cinfo;
};

void proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
void proto_tree_add_item_ret_boolean(proto_tree*, int, tvbuff_t*, int, int, int, gboolean*);
void proto_tree_add_item_ret_uint(proto_tree*, int, tvbuff_t*, int, int, int, guint*);
guint8 tvb_get_guint8(tvbuff_t*, int);
tvbuff_t* tvb_new_subset_length(tvbuff_t*, int, int);
void call_dissector(dissector_handle_t*, tvbuff_t*, packet_info*, proto_tree*);
void col_append_str(void*, int, const char*);
void col_set_fence(void*, int);