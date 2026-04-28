#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef unsigned int guint;
typedef uint8_t guint8;

typedef struct {
    guint trailer_len;
    int noise_low;
    int noise_med;
    int noise_high;
} f5eth_tap_data_t;

#define F5_OFF_LENGTH 1
#define F5_OFF_VERSION 2
#define F5TYPE_LOW 1
#define F5TYPE_MED 2
#define F5TYPE_HIGH 3
#define F5_MIN_SANE 3
#define F5_MAX_SANE 255
#define F5TRAILER_VER_MAX 1

extern int hf_low_id;
extern int hf_med_id;
extern int hf_high_id;
extern int ett_f5ethtrailer_low;
extern int ett_f5ethtrailer_med;
extern int ett_f5ethtrailer_high;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define ENC_NA 0

guint dissect_low_trailer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint len, guint8 ver, f5eth_tap_data_t *tdata);
guint dissect_med_trailer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint len, guint8 ver, f5eth_tap_data_t *tdata);
guint dissect_high_trailer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint len, guint8 ver, f5eth_tap_data_t *tdata);

proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
void proto_item_set_len(proto_item *item, gint length);
guint tvb_reported_length_remaining(const tvbuff_t *tvb, const gint offset);
guint8 tvb_get_guint8(const tvbuff_t *tvb, const gint offset);