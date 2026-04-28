#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct tvbuff {
    uint8_t *data;
    size_t length;
} tvbuff_t;

typedef struct packet_info {
    // dummy structure
} packet_info;

typedef struct proto_tree {
    // dummy structure
} proto_tree;

typedef struct proto_item {
    // dummy structure
} proto_item;

typedef struct expert_field {
    // dummy structure
} expert_field;

#define ENC_BIG_ENDIAN 0
#define _U_ __attribute__((unused))

int hf_mp4_full_box_ver;
int hf_mp4_full_box_flags;
int hf_mp4_mvhd_creat_time;
int hf_mp4_mvhd_mod_time;
int hf_mp4_mvhd_timescale;
int hf_mp4_mvhd_duration;
int hf_mp4_mvhd_rate;
int hf_mp4_mvhd_vol;
int hf_mp4_mvhd_next_tid;
expert_field ei_mp4_mvhd_next_tid_unknown;

#define gint int
#define guint8 uint8_t
#define guint16 uint16_t
#define guint32 uint32_t
#define guint unsigned int
#define G_MAXUINT32 UINT32_MAX

static inline uint8_t tvb_get_guint8(tvbuff_t *tvb, int offset) {
    return tvb->data[offset];
}

static inline uint16_t tvb_get_ntohs(tvbuff_t *tvb, int offset) {
    uint16_t val;
    memcpy(&val, &tvb->data[offset], sizeof(val));
    return ntohs(val);
}

static inline uint32_t tvb_get_ntohl(tvbuff_t *tvb, int offset) {
    uint32_t val;
    memcpy(&val, &tvb->data[offset], sizeof(val));
    return ntohl(val);
}

static inline double make_fract(uint16_t fract) {
    return fract / 65536.0;
}

static inline proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, 
        tvbuff_t *tvb, int start, int length, int encoding) {
    return NULL;
}

static inline void proto_tree_add_double(proto_tree *tree, int hfindex, 
        tvbuff_t *tvb, int start, int length, double value) {
    // dummy implementation
}

static inline void expert_add_info(packet_info *pinfo, proto_item *item, 
        expert_field *expert) {
    // dummy implementation
}