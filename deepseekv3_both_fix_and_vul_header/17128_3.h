#include <stdint.h>
#include <arpa/inet.h>

#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0

typedef int32_t gint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;

typedef struct tvbuff_t {
    uint8_t* data;
    size_t length;
} tvbuff_t;

typedef struct packet_info {
    // dummy structure
} packet_info;

typedef struct proto_tree {
    // dummy structure
} proto_tree;

static inline guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset) {
    return tvb->data[offset];
}

static inline guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset) {
    return ntohs(*(guint16*)(tvb->data + offset));
}

static inline void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, 
                                     gint offset, gint length, int encoding) {
    // dummy implementation
}

static inline void proto_tree_add_double(proto_tree *tree, int hf, tvbuff_t *tvb,
                                       gint offset, gint length, double value) {
    // dummy implementation
}

static double make_fract(guint16 fract_dec) {
    return fract_dec / 65536.0;
}

extern int hf_mp4_full_box_ver;
extern int hf_mp4_full_box_flags;
extern int hf_mp4_tkhd_creat_time;
extern int hf_mp4_tkhd_mod_time;
extern int hf_mp4_tkhd_track_id;
extern int hf_mp4_tkhd_duration;
extern int hf_mp4_tkhd_width;
extern int hf_mp4_tkhd_height;