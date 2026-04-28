#include <stdint.h>
#include <stddef.h>

#define TLV_HAS_TYPEEXT 0x01
#define TLV_HAS_SINGLEINDEX 0x02
#define TLV_HAS_MULTIINDEX 0x04
#define TLV_HAS_VALUE 0x08
#define TLV_HAS_EXTLEN 0x10
#define TLV_HAS_MULTIVALUE 0x20

#define TLV_CAT_PACKET 0
#define TLV_CAT_MESSAGE 1
#define TLV_CAT_ADDRESS 2

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int8_t gint8;

struct value_string {
    guint32 value;
    const char *strptr;
};
typedef struct value_string value_string;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int hf_packetbb_tlvblock;
extern int hf_packetbb_tlvblock_length;
extern int hf_packetbb_tlv;
extern int hf_packetbb_pkttlv_type;
extern int hf_packetbb_msgtlv_type;
extern int hf_packetbb_addrtlv_type;
extern int hf_packetbb_tlv_flags;
extern int hf_packetbb_tlv_flags_hastypext;
extern int hf_packetbb_tlv_flags_hassingleindex;
extern int hf_packetbb_tlv_flags_hasmultiindex;
extern int hf_packetbb_tlv_flags_hasvalue;
extern int hf_packetbb_tlv_flags_hasextlen;
extern int hf_packetbb_tlv_flags_hasmultivalue;
extern int hf_packetbb_tlv_typeext;
extern int hf_packetbb_tlv_indexstart;
extern int hf_packetbb_tlv_indexend;
extern int hf_packetbb_tlv_length;
extern int hf_packetbb_tlv_value;
extern int hf_packetbb_tlv_multivalue;

extern const value_string pkttlv_type_vals[];
extern const value_string msgtlv_type_vals[];
extern const value_string addrtlv_type_vals[];

extern int ett_packetbb_tlvblock;
extern int* ett_packetbb_tlv;
extern int ett_packetbb_tlv_flags;
extern int ett_packetbb_tlv_value;

extern expert_field ei_packetbb_error;