#include <stdint.h>
#include <stdlib.h>

#define SCIDX_END_SENTINAL -1
#define _U_
#define ENC_LITTLE_ENDIAN 0
#define BMT_NO_APPEND 0

typedef uint64_t guint64;
typedef uint32_t guint;
typedef int8_t gint8;
typedef uint8_t guint8;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct expert_field expert_field;

extern int hf_ieee80211_he_mimo_control_field;
extern int hf_ieee80211_he_compressed_beamforming_report_snr;
extern int ett_ff_he_mimo_control;
extern int ett_ff_he_mimo_beamforming_report_snr;
extern int ett_ff_he_mimo_feedback_matrices;
extern expert_field ei_ieee80211_bad_length;
extern const int* he_mimo_control_headers;

static guint64 tvb_get_letoh40(tvbuff_t *tvb, int offset);
static void proto_tree_add_bitmask_with_flags(proto_tree *tree, tvbuff_t *tvb, int offset, int hf, int ett, const int* headers, int encoding, int flags);
static proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, void* null, const char* desc);
static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
static void proto_tree_add_uint_format(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, gint8 value, const char* format, ...);
static void proto_item_set_len(proto_tree *tree, int length);
static int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
static void expert_add_info(packet_info *pinfo, proto_tree *tree, expert_field *ef);

static int next_he_scidx(int scidx, int bw, int grouping, int feedback, int ru_start_index, int ru_end_index);
static int dissect_he_feedback_matrix(proto_tree *tree, tvbuff_t *tvb, int offset, int bit_offset, int scidx, int nr, int nc, int phi_bits, int psi_bits);