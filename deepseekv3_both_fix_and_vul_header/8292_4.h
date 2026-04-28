#include <stdint.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;

typedef struct {
    void *cinfo;
    struct {
        int num;
    } *fd;
    int fragmented;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct fragment_head {
    int len;
    struct fragment_head *next;
    void *tvb_data;
    unsigned frame;
} fragment_head;

typedef fragment_head fragment_item;

struct ieee_802_11_phdr {
    int fcs_len;
    int decrypted;
    int datapad;
    int phy;
    int presence_flags;
};

struct eth_phdr {
    int fcs_len;
};

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gint;
typedef unsigned int guint;
typedef int gboolean;
typedef char gchar;

#define COL_PROTOCOL 0
#define COL_INFO 0
#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 0
#define TRUE 1
#define FALSE 0
#define PPI_V0_HEADER_LEN 8
#define PADDING4(x) 0
#define AGGREGATE_MAX 0
#define DOT11N_IS_AGGREGATE(x) 0
#define DOT11N_MORE_AGGREGATES(x) 0
#define IS_PPI_FLAG_ALIGN(x) 0
#define ReportedBoundsError 0

enum {
    PPI_80211_COMMON,
    PPI_80211N_MAC,
    PPI_80211N_MAC_PHY,
    PPI_SPECTRUM_MAP,
    PPI_PROCESS_INFO,
    PPI_CAPTURE_INFO,
    PPI_AGGREGATION_EXTENSION,
    PPI_8023_EXTENSION,
    PPI_GPS_INFO,
    PPI_VECTOR_INFO,
    PPI_SENSOR_INFO,
    PPI_ANTENNA_INFO,
    FNET_PRIVATE
};

enum {
    PHDR_802_11_PHY_UNKNOWN
};

#define ADD_BASIC_TAG(x) 

extern int proto_ppi;
extern int ett_ppi_pph;
extern int ett_ppi_flags;
extern int ett_ampdu_segments;
extern int ett_ampdu;
extern int ett_ampdu_segment;
extern int hf_ppi_head_version;
extern int hf_ppi_head_flags;
extern int hf_ppi_head_flag_alignment;
extern int hf_ppi_head_flag_reserved;
extern int hf_ppi_head_len;
extern int hf_ppi_head_dlt;
extern int hf_spectrum_map;
extern int hf_process_info;
extern int hf_capture_info;
extern int hf_ppi_gps;
extern int hf_ppi_vector;
extern int hf_ppi_harris;
extern int hf_ppi_antenna;
extern int hf_ppi_fnet;
extern int hf_ppi_reserved;
extern int hf_ampdu_segment;
extern int hf_ampdu_reassembled_in;
extern int hf_ampdu_count;
extern int ei_ppi_invalid_length;

extern void *ppi_gps_handle;
extern void *ppi_vector_handle;
extern void *ppi_sensor_handle;
extern void *ppi_antenna_handle;
extern void *ppi_fnet_handle;
extern void *ieee80211_radio_handle;
extern void *data_handle;

extern fragment_head ampdu_reassembly_table;
extern gboolean ppi_ampdu_reassemble;

extern int wtap_pcap_encap_to_wtap_encap(guint32 dlt);
extern void dissect_80211_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int data_len, struct ieee_802_11_phdr *phdr);
extern void dissect_80211n_mac(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int data_len, gboolean b, guint32 *n_ext_flags, guint32 *ampdu_id, struct ieee_802_11_phdr *phdr);
extern void dissect_80211n_mac_phy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int data_len, guint32 *n_ext_flags, guint32 *ampdu_id, struct ieee_802_11_phdr *phdr);
extern void dissect_aggregation_extension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int data_len);
extern void dissect_8023_extension(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int data_len);
extern void call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
extern void call_dissector_with_data(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);
extern void dissector_try_uint_new(void *table, int encap, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean b, void *data);
extern fragment_head *fragment_get(fragment_head *table, packet_info *pinfo, guint32 id, void *data);
extern void fragment_add_seq_next(fragment_head *table, tvbuff_t *tvb, int offset, packet_info *pinfo, guint32 id, void *data, int len, gboolean b);
extern int proto_get_id_by_filter_name(const char *name);
extern void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *str);
extern tvbuff_t *tvb_new_subset(tvbuff_t *tvb, int offset, int len, int reported_len);
extern tvbuff_t *tvb_new_subset_remaining(tvbuff_t *tvb, int offset);
extern tvbuff_t *tvb_new_chain(tvbuff_t *tvb, tvbuff_t *next);
extern int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern guint16 tvb_get_letohs(tvbuff_t *tvb, int offset);
extern guint32 tvb_get_letohl(tvbuff_t *tvb, int offset);
extern void col_set_str(packet_info *pinfo, int col, const char *str);
extern void col_clear(packet_info *pinfo, int col);
extern void col_add_fstr(packet_info *pinfo, int col, const char *fmt, ...);
extern void proto_item_append_text(proto_item *ti, const char *fmt, ...);
extern void PROTO_ITEM_SET_GENERATED(proto_item *ti);
extern void THROW(int error);
extern char *wmem_strdup_printf(void *scope, const char *fmt, ...);
extern void *wmem_packet_scope(void);
extern const char *plurality(int n, const char *singular, const char *plural);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, int encoding);
extern proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int len, const char *format, ...);
extern proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
extern void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, int *ei, tvbuff_t *tvb, int offset, int len, const char *format, ...);
extern proto_tree *proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int offset, int len, int ett, proto_item **ti, const char *format, ...);
extern void proto_tree_add_uint_format(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, guint32 value, const char *format, ...);
extern void proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, guint32 value);
extern proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int len, int ett, proto_item **ti, const char *text);

struct wtap_encap_dissector_table;
extern struct wtap_encap_dissector_table *wtap_encap_dissector_table;

enum {
    WTAP_ENCAP_ETHERNET
};