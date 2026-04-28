#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define DOCSIS_MIN_HEADER_LEN 6
#define FCPARM_QUEUE_DEPTH_REQ_FRM 0
#define EXT_HDR_ON 1
#define FCTYPE_MACSPC 0
#define FCTYPE_PACKET 1
#define FCTYPE_RESERVED 2
#define FCTYPE_ISOLAT 3
#define FCPARM_RQST_FRM 0
#define FCPARM_FRAG_HDR 1
#define FCPARM_TIMING_HDR 2
#define FCPARM_MAC_MGMT_HDR 3
#define FCPARM_QUEUE_DEPTH_REQ_FRM 4
#define FCPARM_CONCAT_HDR 5
#define FRAG_LAST 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 0
#define PROTO_CHECKSUM_VERIFY 0
#define COL_PROTOCOL 0
#define COL_INFO 0
#define TRUE true
#define FALSE false

typedef struct tvbuff_t {
    // Dummy structure for tvbuff_t
} tvbuff_t;

typedef struct {
    void* protocol;
    void* info;
} cinfo_t;

typedef struct packet_info {
    cinfo_t cinfo;
    bool fragmented;
} packet_info;

typedef struct proto_tree {
    // Dummy structure for proto_tree
} proto_tree;

typedef struct proto_item {
    // Dummy structure for proto_item
} proto_item;

typedef struct fragment_item {
    // Dummy structure for fragment_item
} fragment_item;

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int32_t gint;
typedef bool gboolean;

static int proto_docsis;
static int ett_docsis;
static int hf_docsis_fctype;
static int hf_docsis_fcparm;
static int hf_docsis_exthdr;
static int hf_docsis_machdr_fcparm;
static int hf_docsis_mini_slots;
static int hf_docsis_sid;
static int hf_docsis_requested_size;
static int hf_docsis_concat_cnt;
static int hf_docsis_len;
static int hf_docsis_frag_fcs;
static int hf_docsis_frag_fcs_status;
static void *docsis_reassembly_table;
static void *docsis_frag_items;
static void *docsis_mgmt_handle;
static void *docsis_handle;
static void *eth_withoutfcs_handle;
static void *ei_docsis_frag_fcs_bad;
static guint32 frag_sid;
static guint32 frag_seq;
static guint32 frag_flags;

static void dissect_exthdr_length_field(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 exthdr, guint8 mac_parm, guint16 len_sid, guint16 *payload_length);
static void dissect_hcs_field(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 hdrlen);

#define _U_ __attribute__((unused))