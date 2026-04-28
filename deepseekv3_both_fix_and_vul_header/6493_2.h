#include <stdint.h>
#include <stddef.h>

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff tvbuff_t;

typedef struct {
    void* data;
} address;

typedef struct {
    address dst;
    void* cinfo;
} packet_info;

typedef struct _wmem_allocator_t wmem_allocator_t;

typedef enum enip_connid_type {
    ECIDT_UNKNOWN,
    ECIDT_O2T,
    ECIDT_T2O
} enip_connid_type;

typedef enum cip_safety_format_type {
    CIP_SAFETY_BASE_FORMAT,
    CIP_SAFETY_EXTENDED_FORMAT
} cip_safety_format_type;

typedef struct {
    enip_connid_type conn_type;
    cip_safety_format_type format;
    int server_dir;
} cip_safety_info_t;

typedef int gboolean;
#define FALSE 0
#define TRUE 1

#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1
#define COL_PROTOCOL 0

extern int hf_cipsafety_consumer_time_value;
extern int hf_cipsafety_ack_byte2;
extern int hf_cipsafety_crc_s3;
extern int hf_cipsafety_crc_s5_0;
extern int hf_cipsafety_crc_s5_1;
extern int hf_cipsafety_crc_s5_2;
extern int hf_cipsafety_data;
extern int hf_cipsafety_crc_s1;
extern int hf_cipsafety_crc_s2;
extern int hf_cipsafety_timestamp;
extern int hf_cipsafety_mcast_byte2;
extern int hf_cipsafety_time_correction;
extern int hf_cipsafety_complement_data;
extern int ei_mal_io;
extern int proto_cipsafety;

extern uint32_t pntoh32(const void* data);
extern void* p_get_proto_data(wmem_allocator_t* allocator, packet_info* pinfo, int proto, int index);
extern void col_set_str(void* cinfo, int column, const char* str);
extern void proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, int encoding);
extern void dissect_ack_byte(proto_tree* tree, tvbuff_t* tvb, int offset, packet_info* pinfo);
extern void dissect_mode_byte(proto_tree* tree, tvbuff_t* tvb, int offset, packet_info* pinfo);
extern void dissect_mcast_byte(proto_tree* tree, tvbuff_t* tvb, int offset, packet_info* pinfo);
extern void expert_add_info(packet_info* pinfo, proto_item* item, int* expert_info);
extern wmem_allocator_t* wmem_file_scope(void);