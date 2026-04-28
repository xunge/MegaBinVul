#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef uint8_t guint8;
typedef uint32_t guint32;

typedef struct tvbuff_t {
    // dummy structure for compilation
} tvbuff_t;

typedef struct packet_info {
    guint32 num;
    guint32 curr_layer_num;
} packet_info;

typedef struct bluetooth_data_t {
    int interface_id;
    int adapter_id;
} bluetooth_data_t;

typedef struct request_data_t {
    guint32 request_in_frame;
    guint8 opcode;
} request_data_t;

typedef struct wmem_tree_t {
    // dummy structure for compilation
} wmem_tree_t;

typedef struct wmem_tree_key_t {
    unsigned length;
    void *key;
} wmem_tree_key_t;

extern wmem_tree_t *requests;
extern void *wmem_tree_lookup32_array(wmem_tree_t *tree, wmem_tree_key_t *key);
extern void *wmem_tree_lookup32_le(wmem_tree_t *tree, guint32 frame_number);
extern gint tvb_captured_length_remaining(tvbuff_t *tvb, gint offset);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);