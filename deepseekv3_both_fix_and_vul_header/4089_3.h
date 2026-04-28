#include <stdint.h>
#include <arpa/inet.h>

typedef int32_t gint;
typedef uint8_t guint8;
typedef uint16_t guint16;

typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;
typedef struct ei_register_t ei_register_t;

extern int hf_hiqnet_datatype;
extern int hf_hiqnet_datalen;
extern int hf_hiqnet_string;
extern int hf_hiqnet_value;
extern ei_register_t ei_hiqnet_datatype;
extern const int hiqnet_datasize_per_type[10];

#define ENC_BIG_ENDIAN 0
#define ENC_UCS_2 1
#define ENC_NA 2

static inline guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset) {
    return *(guint8*)((char*)tvb + offset);
}

static inline guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset) {
    return ntohs(*(guint16*)((char*)tvb + offset));
}

static inline proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, 
                                            gint start, gint length, int encoding) {
    return (proto_item*)((char*)tree + start);
}

static inline void expert_add_info(packet_info *pinfo, proto_item *ti, ei_register_t *ei) {
    (void)pinfo;
    (void)ti;
    (void)ei;
}