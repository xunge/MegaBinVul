#include <stdint.h>
#include <stddef.h>

#define AMQP_1_0_TYPE_LIST0 0x45
#define AMQP_1_0_TYPE_LIST8 0xC0
#define AMQP_1_0_TYPE_LIST32 0xD0
#define FT_NONE 0
#define ENC_BIG_ENDIAN 0

#define AMQP_INCREMENT(offset, incr, bound) \
    do { \
        offset += (incr); \
        if (offset > bound) { \
            return bound-orig_offset; \
        } \
    } while (0)

typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint32_t guint32;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct expert_field expert_field;

extern int hf_amqp_1_0_list;
extern int ett_amqp_1_0_list;
extern const char *element_suffix[];
extern expert_field ei_amqp_unknown_amqp_type;
extern expert_field ei_amqp_invalid_number_of_params;

int proto_registrar_get_ftype(int hf_index);
const char* proto_registrar_get_name(int hf_index);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *expert, const char *format, ...);
proto_item* proto_tree_add_none_format(proto_item *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *format, ...);
proto_item* proto_tree_add_item(proto_item *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_item_set_text(proto_item *item, const char *format, ...);
proto_item* proto_item_add_subtree(proto_item *item, int tree_type);
void proto_item_append_text(proto_item *item, const char *format, ...);
void get_amqp_1_0_type_value_formatter(tvbuff_t *tvb, packet_info *pinfo, int offset, int bound, int hf_amqp_item, void *data, guint32 *decoded_element_size, proto_item *tree);