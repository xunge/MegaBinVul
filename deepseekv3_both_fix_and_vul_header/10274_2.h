#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef bool gboolean;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef const char gchar;

typedef struct {
    uint32_t adapter_id;
    uint32_t chandle;
} bthci_acl_data_t;

typedef struct {
    // Add necessary fields
} btl2cap_data_t;

typedef struct {
    uint32_t psm;
    uint32_t local_service;
    uint32_t interface_id;
    uint32_t adapter_id;
    uint32_t chandle;
    uint32_t remote_cid;
    uint32_t local_cid;
    uint32_t connect_in_frame;
    uint32_t disconnect_in_frame;
} psm_data_t;

typedef struct {
    int length;
    void *key;
} wmem_tree_key_t;

typedef struct {
    uint8_t size;
    uint16_t bt_uuid;
    uint8_t data[2];
} bluetooth_uuid_t;

typedef struct {
    struct {
        struct {
            bool visited;
        } flags;
    } *fd;
    struct {
        uint32_t presence_flags;
        uint32_t interface_id;
    } *phdr;
    uint32_t p2p_dir;
    uint32_t num;
    void *cinfo;
} packet_info;

typedef struct {
    // Add necessary fields
} proto_tree;
typedef struct {
    // Add necessary fields
} proto_item;
typedef struct {
    // Add necessary fields
} tvbuff_t;

#define ENC_LITTLE_ENDIAN 0
#define WTAP_HAS_INTERFACE_ID 0
#define HCI_INTERFACE_DEFAULT 0
#define HCI_ADAPTER_DEFAULT 0
#define P2P_DIR_SENT 0
#define P2P_DIR_RECV 1
#define COL_INFO 0

extern int hf_btl2cap_dcid;
extern int hf_btl2cap_scid;
extern int hf_btl2cap_psm;
extern int hf_btl2cap_service;
extern int hf_btl2cap_connect_in_frame;
extern const char *psm_vals[];
extern const void *bluetooth_uuid_vals_ext;
extern void *cid_to_psm_table;
extern uint32_t max_disconnect_in_frame;

#define PROTO_ITEM_SET_GENERATED(item) (void)0

static inline uint16_t tvb_get_letohs(const tvbuff_t *tvb, int offset) {
    return 0;
}

static inline void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, int encoding) {
    (void)tree; (void)hf; (void)tvb; (void)offset; (void)len; (void)encoding;
}

static inline proto_item* proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, uint32_t value) {
    (void)tree; (void)hf; (void)tvb; (void)offset; (void)len; (void)value;
    return NULL;
}

static inline void *wmem_tree_lookup32_array_le(void *tree, wmem_tree_key_t *key) {
    (void)tree; (void)key;
    return NULL;
}

static inline uint32_t get_service_uuid(packet_info *pinfo, btl2cap_data_t *l2cap_data, uint32_t psm, uint32_t local_service) {
    (void)pinfo; (void)l2cap_data; (void)psm; (void)local_service;
    return 0;
}

static inline const char *val_to_str_ext_const(uint32_t val, const void *vals, const char *def) {
    (void)val; (void)vals;
    return def;
}

static inline const char *val_to_str_const(uint32_t val, const char *const *vals, const char *def) {
    (void)val; (void)vals;
    return def;
}

static inline void col_append_fstr(void *cinfo, int column, const char *format, ...) {
    (void)cinfo; (void)column; (void)format;
}