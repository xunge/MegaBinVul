#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct bt_att_chan {
    // placeholder structure
};

struct bt_gatt_server {
    void *prep_queue;
    size_t max_prep_queue_len;
    void *db;
    void *debug_callback;
    void *debug_data;
    void *att;
};

struct gatt_db_attribute {
    // placeholder structure
};

struct prep_write_complete_data {
    struct bt_att_chan *chan;
    void *pdu;
    uint16_t length;
    struct bt_gatt_server *server;
};

#define BT_ATT_ERROR_INVALID_PDU 0x04
#define BT_ATT_ERROR_PREPARE_QUEUE_FULL 0x09
#define BT_ATT_ERROR_INVALID_HANDLE 0x01
#define BT_ATT_ERROR_UNLIKELY 0x0E
#define BT_ATT_PERM_WRITE_MASK 0x02
#define BT_ATT_OP_PREP_WRITE_REQ 0x16

static inline uint16_t get_le16(const void *p) {
    const uint8_t *u8p = p;
    return (uint16_t)(u8p[0] | (u8p[1] << 8));
}

static inline size_t queue_length(void *queue) {
    return 0; // placeholder implementation
}

static inline void *gatt_db_get_attribute(void *db, uint16_t handle) {
    return NULL; // placeholder implementation
}

static inline uint8_t check_permissions(struct bt_gatt_server *server, 
                                      struct gatt_db_attribute *attr, 
                                      uint8_t mask) {
    return 0; // placeholder implementation
}

static inline uint8_t gatt_db_attribute_write(struct gatt_db_attribute *attr,
                                            uint16_t offset,
                                            const void *value,
                                            size_t len,
                                            uint8_t opcode,
                                            void *att,
                                            void (*callback)(void *),
                                            void *user_data) {
    return 0; // placeholder implementation
}

static inline void prep_write_complete_cb(void *user_data) {
    // placeholder implementation
}

static inline void bt_att_chan_send_error_rsp(struct bt_att_chan *chan,
                                            uint8_t opcode,
                                            uint16_t handle,
                                            uint8_t ecode) {
    // placeholder implementation
}

static inline void util_debug(void *debug_callback, void *debug_data,
                            const char *format, ...) {
    // placeholder implementation
}

#define new0(type, count) ((type *)calloc(count, sizeof(type)))