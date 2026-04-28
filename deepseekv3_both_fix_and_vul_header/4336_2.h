#include <stdint.h>

#define TAG_COUNTRY_INFO 0
#define TAG_WIDE_BW_CHANNEL_SWITCH 0
#define TAG_VHT_TX_PWR_ENVELOPE 0
#define G_N_ELEMENTS(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;

typedef uint32_t guint32;
typedef uint8_t guint8;

int add_tagged_field(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, int arg, ...);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);