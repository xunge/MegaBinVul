#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int32_t gint;
typedef int16_t gint16;
typedef unsigned int guint;
typedef int gboolean;
#define TRUE 1
#define FALSE 0
#define NULL ((void*)0)

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    struct {
        gboolean fragmented;
    } *cinfo;
    gboolean fragmented;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct fragment_head {
    guint32 len;
} fragment_head;

typedef struct {
    guint8 subframe1;
    guint8 subframe2;
} opensafety_frame_info;

typedef struct {
    struct {
        gboolean toggle;
        gboolean abort_transfer;
        gboolean preload;
        gboolean read_access;
        gboolean initiate;
        gboolean segmented;
        gboolean end_segment;
    } sacmd;
} opensafety_ssdo_payload;

typedef struct {
    gboolean scm_udid_valid;
    guint8 scm_udid[5];
    opensafety_frame_info frame;
    struct {
        opensafety_ssdo_payload *ssdo;
    } payload;
} opensafety_packet_info;

extern int hf_oss_ssdo_sacmd_end_segment;
extern int hf_oss_ssdo_sacmd_initiate;
extern int hf_oss_ssdo_sacmd_toggle;
extern int hf_oss_ssdo_sacmd_segmentation;
extern int hf_oss_ssdo_sacmd_abort_transfer;
extern int hf_oss_ssdo_sacmd_preload;
extern int hf_oss_ssdo_sacmd_access_type;
extern int hf_oss_ssdo_client;
extern int hf_oss_ssdo_server;
extern int hf_oss_ssdo_sano;
extern int hf_oss_ssdo_preload_queue;
extern int hf_oss_ssdo_preload_error;
extern int hf_oss_ssdo_sod_index;
extern int hf_oss_ssdo_sod_subindex;
extern int hf_oss_ssdo_abort_code;
extern int hf_oss_ssdo_payload_size;
extern int hf_oss_ssdo_payload;
extern int hf_oss_sod_par_timestamp;
extern int hf_oss_sod_par_checksum;
extern int hf_oss_ssdo_sacmd;

extern int ett_opensafety_ssdo;
extern int ett_opensafety_ssdo_sacmd;
extern int ett_opensafety_ssdo_payload;

extern struct expert_field ei_payload_length_not_positive;

extern struct reassembly_table os_reassembly_table;
extern const struct fragment_items oss_frag_items;

extern const char* opensafety_ssdo_sacmd_values[];
extern struct value_string_ext opensafety_sod_idx_names_ext;
extern struct value_string_ext opensafety_abort_codes_ext;

#define OSS_FRAME_POS_LEN 0
#define OSS_FRAME_POS_DATA 4
#define OSS_FRAME_ID_T(tvb, offset) tvb_get_guint8(tvb, offset)
#define OSS_FRAME_ADDR_T(tvb, offset) tvb_get_guint16(tvb, offset, 0)
#define OSS_FRAME_ADDR_T2(tvb, offset, a, b) tvb_get_guint16(tvb, offset, 0)
#define OPENSAFETY_SSDO_SACMD_TGL 0x80
#define OPENSAFETY_SSDO_SACMD_ABRT 0x40
#define OPENSAFETY_SSDO_SACMD_PRLD 0x20
#define OPENSAFETY_SSDO_DOWNLOAD 0x10
#define OPENSAFETY_SSDO_SACMD_INI 0x08
#define OPENSAFETY_SSDO_SACMD_SEG 0x04
#define OPENSAFETY_SSDO_SACMD_ENSG 0x02
#define OPENSAFETY_SOD_DVI 0x101A
#define COL_INFO 0
#define ENC_NA 0

static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
static guint16 tvb_get_guint16(tvbuff_t *tvb, int offset, int endianness);
static guint32 tvb_get_letohl(tvbuff_t *tvb, int offset);
static guint16 tvb_get_letohs(tvbuff_t *tvb, int offset);
static void dissect_opensafety_ssdo_payload(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree, guint8 db0);
static void opensafety_packet_sendreceiv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, opensafety_packet_info *packet, guint16 taddr, guint8 offset2, guint16 saddr, guint8 offset1, guint8 offset2_2, guint16 sdn);
static void opensafety_packet_sender(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, opensafety_packet_info *packet, guint16 saddr, guint8 offset1, guint8 offset2, gint16 sdn);
static void opensafety_packet_receiver(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *item, opensafety_packet_info *packet, guint16 saddr, guint8 offset1, guint8 offset2, gint16 sdn);
static proto_tree *opensafety_packet_payloadtree(tvbuff_t *tvb, proto_tree *tree, opensafety_packet_info *packet, int ett);
static void opensafety_packet_response(tvbuff_t *tvb, proto_tree *tree, opensafety_packet_info *packet, gboolean isResponse);
static void opensafety_packet_node(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int hf, guint16 addr, guint8 offset1, guint8 offset2, guint16 sdn);