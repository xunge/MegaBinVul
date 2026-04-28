#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint;
typedef uint32_t guint32;
typedef uint8_t guint8;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;
typedef struct proto_registrar {
    const char *name;
} proto_registrar;

#define AMQP_1_0_TYPE_ARRAY8 0xe0
#define AMQP_1_0_TYPE_ARRAY32 0xf0
#define FT_NONE 0
#define ENC_BIG_ENDIAN 0

#define AMQP_INCREMENT(offset, incr, bound) \
    do { \
        offset += (incr); \
        if (offset > bound) { \
            ; \
        } \
    } while (0)

extern int hf_amqp_1_0_list;
extern int ett_amqp_1_0_array;
extern expert_field ei_amqp_unknown_amqp_type;
extern expert_field ei_amqp_invalid_number_of_params;
extern const char *element_suffix[];

guint32 get_amqp_1_0_type_formatter(tvbuff_t *tvb, int offset, int bound, int *hf_amqp_type, 
                                   const char **type_name, guint32 *subtype_count, 
                                   const int ***subtypes, guint32 *decoded_size);
void get_amqp_1_0_value_formatter(tvbuff_t *tvb, packet_info *pinfo, guint32 type, 
                                 int offset, int bound, int hf_item, const char *name,
                                 guint32 subtype_count, const int **subtypes, 
                                 guint32 *decoded_size, proto_item *tree);
int proto_registrar_get_ftype(int hf_index);
const char* proto_registrar_get_name(int hf_index);
proto_registrar* proto_registrar_get_nth(int hf_index);
void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ef, 
                          const char *fmt, ...);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_none_format(proto_item *parent, int hfindex, tvbuff_t *tvb, 
                                     int start, int length, const char *format, ...);
proto_item* proto_tree_add_item(proto_item *parent, int hfindex, tvbuff_t *tvb, 
                              int start, int length, int encoding);
void proto_item_set_text(proto_item *item, const char *format, ...);
proto_item* proto_item_add_subtree(proto_item *item, int ett_subtree);
void proto_item_append_text(proto_item *item, const char *format, ...);