#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    struct {
        int num;
    } *fd;
} packet_info;

typedef struct _address {
    int type;
    int len;
    uint8_t *data;
} address;

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

enum {
    TLV_TYPE_FIXED,
    TLV_TYPE_T,
    TLV_TYPE_TV,
    TLV_TYPE_TLV,
    TLV_TYPE_TL16V,
    TLV_TYPE_UNKNOWN
};

struct tlv_def {
    int type;
    unsigned int fixed_len;
};

struct {
    struct tlv_def def[256];
} rsl_att_tlvdef;

enum {
    RSL_IE_CH_NO,
    RSL_IE_FRAME_NO,
    RSL_IE_MS_POW,
    RSL_IE_IPAC_REMOTE_IP,
    RSL_IE_IPAC_REMOTE_PORT,
    RSL_IE_IPAC_LOCAL_IP,
    RSL_IE_IPAC_LOCAL_PORT,
    RSL_IE_IPAC_SPEECH_MODE,
    RSL_IE_IPAC_RTP_PAYLOAD,
    RSL_IE_IPAC_RTP_PAYLOAD2,
    RSL_IE_IPAC_RTP_CSD_FMT,
    RSL_IE_IPAC_CONN_ID,
    RSL_IE_IPAC_CONN_STAT
};

enum {
    RSL_MSG_TYPE_IPAC_CRCX_ACK
};

#define AT_IPv4 1
#define ENC_BIG_ENDIAN 0
#define DISSECTOR_ASSERT_NOT_REACHED() do {} while(0)
#define FALSE 0

extern int hf_rsl_ie_id;
extern int hf_rsl_remote_ip;
extern int hf_rsl_remote_port;
extern int hf_rsl_local_ip;
extern int hf_rsl_local_port;
extern int hf_rsl_speech_mode_s;
extern int hf_rsl_speech_mode_m;
extern int hf_rsl_rtp_payload;
extern int hf_rsl_rtp_csd_fmt_d;
extern int hf_rsl_rtp_csd_fmt_ir;
extern int hf_rsl_conn_id;
extern int hf_rsl_cstat_tx_pkts;
extern int hf_rsl_cstat_tx_octs;
extern int hf_rsl_cstat_rx_pkts;
extern int hf_rsl_cstat_rx_octs;
extern int hf_rsl_cstat_lost_pkts;
extern int hf_rsl_cstat_ia_jitter;
extern int hf_rsl_cstat_avg_tx_dly;
extern int ett_ie_local_port;

guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint32 tvb_get_ipv4(tvbuff_t *tvb, int offset);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
void dissect_rsl_ie_ch_no(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int hidden);
void dissect_rsl_ie_frame_no(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int hidden);
void dissect_rsl_ie_ms_pow(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int hidden);
void rtp_add_address(packet_info *pinfo, address *addr, guint16 port, guint32 ssrc, const char *comment, guint32 setup_frame_num, guint32 flags, void *data);
void rtcp_add_address(packet_info *pinfo, address *addr, guint16 port, guint32 ssrc, const char *comment, guint32 setup_frame_num);