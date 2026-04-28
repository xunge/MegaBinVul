#include <stdint.h>

typedef int32_t gint;
typedef uint8_t guint8;
typedef uint32_t guint32;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct packet_info packet_info;
typedef struct tvbuff_t tvbuff_t;

struct value_string {
    guint32 value;
    const char *strptr;
};

struct expert_field {
    int dummy;
};

extern int hf_data_element;
extern int hf_data_element_type;
extern int hf_data_element_size;
extern int hf_data_element_var_size;
extern int hf_data_element_value;
extern int ett_btsdp_data_element;
extern int ett_btsdp_data_element_value;
extern struct expert_field ei_data_element_value_large;
extern const struct value_string vs_data_element_type[];
extern const struct value_string vs_data_element_size[];

#define ENC_BIG_ENDIAN 0
#define ENC_NA 0