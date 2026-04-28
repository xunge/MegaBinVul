#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef unsigned int guint;

#define FT_NONE 0
#define FT_UINT 1
#define FT_STRING 2
#define FT_BYTES 3
#define FT_GUID 4

#define IS_FT_UINT(ftype) ((ftype) == FT_UINT)
#define IS_FT_STRING(ftype) ((ftype) == FT_STRING)

struct amqp1_typeinfo {
    int ftype;
    const char *amqp_typename;
    guint (*dissector)(tvbuff_t *tvb, packet_info *pinfo, int offset, int bound, int known_size, proto_item *item, int hf_index);
    guint (*formatter)(tvbuff_t *tvb, int offset, int bound, int known_size, const char **value);
    int known_size;
};

struct amqp_synonym_types_t {
    const int *hf_none;
    const int *hf_uint;
    const int *hf_str;
    const int *hf_bin;
    const int *hf_guid;
};

extern struct amqp_synonym_types_t *amqp_synonym_types;
extern int hf_amqp_1_0_list;
extern expert_field ei_amqp_unknown_amqp_type;

#define AMQP_1_0_TYPE_NULL 0x40
#define AMQP_1_0_TYPE_LIST0 0x45
#define AMQP_1_0_TYPE_LIST8 0xC0
#define AMQP_1_0_TYPE_LIST32 0xD0
#define AMQP_1_0_TYPE_MAP8 0xC1
#define AMQP_1_0_TYPE_MAP32 0xD1
#define AMQP_1_0_TYPE_ARRAY8 0xE0
#define AMQP_1_0_TYPE_ARRAY32 0xF0

int proto_registrar_get_ftype(int hf_index);
const char *proto_registrar_get_name(int hf_index);
void proto_tree_add_none_format(proto_item *item, int hfindex, tvbuff_t *tvb, int start, int length, const char *format, ...);
void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ef, const char *format, ...);

static struct amqp1_typeinfo* decode_fixed_type(guint8 code);
static guint dissect_amqp_1_0_list(tvbuff_t *tvb, packet_info *pinfo, int offset, int bound, proto_item *item, int hf_index, guint32 subtype_count, const int **subtypes, const char *name);
static guint dissect_amqp_1_0_map(tvbuff_t *tvb, packet_info *pinfo, int offset, int bound, proto_item *item, int hf_index, const char *name);
static guint dissect_amqp_1_0_array(tvbuff_t *tvb, packet_info *pinfo, int offset, int bound, proto_item *item, int hf_index, guint32 subtype_count, const int **subtypes, const char *name);