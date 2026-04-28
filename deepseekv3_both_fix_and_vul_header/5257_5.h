#include <stdint.h>
#include <stddef.h>

#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0
#define PROTO_ITEM_SET_GENERATED(x)

typedef int gint;
typedef uint8_t guint8;
typedef uint32_t guint32;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t tvbuff_t;

typedef struct dof_api_data {
    struct dof_session_data *session;
} dof_api_data;

typedef struct dof_packet_data {
    uint32_t sender_id;
} dof_packet_data;

typedef struct dof_session_data {
    uint32_t session_id;
} dof_session_data;

typedef struct oap_1_binding {
    uint8_t *iid;
    uint8_t iid_length;
    uint8_t *oid;
    uint8_t oid_length;
    uint32_t frame;
} oap_1_binding;

typedef struct oap_1_alias_key {
    uint32_t session;
    uint32_t sender;
    uint32_t alias;
} oap_1_alias_key;

typedef struct oap_1_packet_data oap_1_packet_data;

extern int hf_oap_1_alias;
extern int hf_oap_1_interfaceid;
extern int hf_oap_1_objectid;
extern int hf_oap_1_alias_frame;
extern int ett_oap_1_alias;

extern uint8_t tvb_get_guint8(tvbuff_t *tvb, int offset);
extern proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding);
extern proto_item *proto_tree_add_bytes_format_value(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, const uint8_t *bytes, const char *format, ...);
extern void proto_tree_add_uint_format(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, uint32_t value, const char *format, ...);
extern oap_1_binding* oap_1_resolve_alias(oap_1_alias_key* key);
extern char* dof_iid_create_standard_string(uint8_t length, const uint8_t* iid);
extern char* dof_oid_create_standard_string(uint8_t length, const uint8_t* oid);