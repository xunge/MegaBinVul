#include <stdint.h>

typedef uint16_t guint16;
typedef uint8_t guint8;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

typedef struct {
    void *assoc;
} sccp_decode_context_t;

#define PARAMETER_CALLED_PARTY_ADDRESS 0
#define PARAMETER_CALLING_PARTY_ADDRESS 1
#define PARAMETER_DATA 2
#define PARAMETER_LONG_DATA 3
#define PARAMETER_SOURCE_LOCAL_REFERENCE 4
#define PARAMETER_DESTINATION_LOCAL_REFERENCE 5
#define PARAMETER_RELEASE_CAUSE 6
#define PARAMETER_RETURN_CAUSE 7
#define PARAMETER_RESET_CAUSE 8
#define PARAMETER_ERROR_CAUSE 9
#define PARAMETER_REFUSAL_CAUSE 10
#define PARAMETER_END_OF_OPTIONAL_PARAMETERS 11
#define PARAMETER_CLASS 12
#define PARAMETER_SEGMENTING_REASSEMBLING 13
#define PARAMETER_RECEIVE_SEQUENCE_NUMBER 14
#define PARAMETER_SEQUENCING_SEGMENTING 15
#define PARAMETER_CREDIT 16
#define PARAMETER_SEGMENTATION 17
#define PARAMETER_HOP_COUNTER 18
#define PARAMETER_IMPORTANCE 19
#define PARAMETER_ISNI 20

#define ANSI_STANDARD 0
#define ENC_NA 0

extern int hf_sccp_end_optional_param;
extern int decode_mtp3_standard;

extern tvbuff_t* tvb_new_subset_length(tvbuff_t* tvb, guint16 offset, guint16 length);
extern void proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, guint16 start, guint16 length, int encoding);

extern void dissect_sccp_dlr_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length, sccp_decode_context_t* sccp_info);
extern void dissect_sccp_slr_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length, sccp_decode_context_t* sccp_info);
extern void dissect_sccp_called_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length, sccp_decode_context_t* sccp_info);
extern void dissect_sccp_calling_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length, sccp_decode_context_t* sccp_info);
extern void dissect_sccp_class_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length, sccp_decode_context_t* sccp_info);
extern void dissect_sccp_segmenting_reassembling_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_receive_sequence_number_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_sequencing_segmenting_param(tvbuff_t* tvb, proto_tree* tree, guint16 length);
extern void dissect_sccp_credit_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_release_cause_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_return_cause_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_reset_cause_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_error_cause_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_refusal_cause_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_data_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* assoc);
extern void dissect_sccp_segmentation_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_hop_counter_param(tvbuff_t* tvb, proto_tree* tree, guint16 length);
extern void dissect_sccp_importance_param(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, guint16 length);
extern void dissect_sccp_isni_param(tvbuff_t* tvb, proto_tree* tree, guint16 length);
extern void dissect_sccp_unknown_param(tvbuff_t* tvb, proto_tree* tree, guint8 type, guint16 length);