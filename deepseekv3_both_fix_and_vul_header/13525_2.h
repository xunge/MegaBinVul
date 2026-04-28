#include <stdint.h>

#define XRA_TLV_CW_INFO_NR_OF_INFO_BYTES 0
#define XRA_TLV_CW_INFO_BCH_DECODING_SUCCESFUL 1
#define XRA_TLV_CW_INFO_PROFILE_PARITY 2
#define XRA_TLV_CW_INFO_BCH_NUMBER_OF_CORRECTED_BITS 3
#define XRA_TLV_CW_INFO_LDPC_NUMBER_OF_CODE_BITS 4
#define XRA_TLV_CW_INFO_LDPC_DECODING_SUCCESSFUL 5
#define XRA_TLV_CW_INFO_LDPC_NUMBER_OF_CORRECTED_BITS 6
#define XRA_TLV_CW_INFO_LDPC_NUMBER_OF_ITERATIONS 7
#define XRA_TLV_CW_INFO_RS_DECODING_SUCCESFUL 8
#define XRA_TLV_CW_INFO_RS_NUMBER_OF_CORRECTED_SYMBOLS 9

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define _U_ __attribute__((unused))

extern int hf_xra_tlv_cw_info;
extern int hf_xra_tlv_cw_info_nr_of_info_bytes;
extern int hf_xra_tlv_cw_info_bch_decoding_successful;
extern int hf_xra_tlv_cw_info_profile_parity;
extern int hf_xra_tlv_cw_info_bch_number_of_corrected_bits;
extern int hf_xra_tlv_cw_info_ldpc_nr_of_code_bits;
extern int hf_xra_tlv_cw_info_ldpc_decoding_successful;
extern int hf_xra_tlv_cw_info_ldpc_number_of_corrected_bits;
extern int hf_xra_tlv_cw_info_ldpc_number_of_iterations;
extern int hf_xra_tlv_cw_info_rs_decoding_successful;
extern int hf_xra_tlv_cw_info_rs_number_of_corrected_symbols;
extern int hf_xra_unknown;
extern int ett_xra_tlv_cw_info;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1