#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct mpa_state_t mpa_state_t;
typedef struct tcpinfo tcpinfo;

struct mpa_state_t {
    struct {
        int valid;
    } minfo[2];
};

#define MPA_MARKER_LEN 4
#define MPA_ULPDU_LENGTH_LEN 2
#define MPA_CRC_LEN 4
#define MPA_FPDU 0
#define ENC_NA 0

extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding);
extern void proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, guint32 value);
extern void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, void *ei, tvbuff_t *tvb, int offset, int length, const char *format, ...);
extern guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);

extern int proto_iwarp_mpa;
extern int ett_mpa;
extern int hf_mpa_fpdu;
extern int hf_mpa_ulpdu_length;
extern int hf_mpa_pad;
extern void *ei_mpa_bad_length;

static guint16 get_first_marker_offset(mpa_state_t *state, struct tcpinfo *tcpinfo, guint8 endpoint);
static guint32 number_of_markers(mpa_state_t *state, struct tcpinfo *tcpinfo, guint8 endpoint);
static guint16 expected_ulpdu_length(mpa_state_t *state, struct tcpinfo *tcpinfo, guint8 endpoint);
static guint8 fpdu_pad_length(guint16 ulpdu_length);
static guint32 fpdu_total_length(struct tcpinfo *tcpinfo);
static int pad_offset(struct tcpinfo *tcpinfo, guint32 total_length, guint8 pad_length);
static void dissect_fpdu_crc(tvbuff_t *tvb, proto_tree *tree, mpa_state_t *state, guint32 offset, guint32 length);
static void dissect_fpdu_markers(tvbuff_t *tvb, proto_tree *tree, mpa_state_t *state, struct tcpinfo *tcpinfo, guint8 endpoint);
static void mpa_packetlist(packet_info *pinfo, guint8 type);