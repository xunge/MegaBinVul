#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

struct bt_att_chan;
struct gatt_db_attribute;

struct bt_gatt_server {
    void *db;
    void *debug_callback;
    void *debug_data;
    void *att;
};

struct async_write_op {
    struct bt_att_chan *chan;
    struct bt_gatt_server *server;
    uint8_t opcode;
};

uint8_t BT_ATT_ERROR_INVALID_PDU;
uint8_t BT_ATT_ERROR_INVALID_HANDLE;
uint8_t BT_ATT_ERROR_UNLIKELY;
uint8_t BT_ATT_OP_WRITE_REQ;
uint8_t BT_ATT_OP_WRITE_CMD;
uint8_t BT_ATT_PERM_WRITE_MASK;

uint8_t authorize_req(struct bt_gatt_server *server, uint8_t opcode, uint16_t handle);
uint16_t get_le16(const void *pdu);
void util_debug(void *debug_callback, void *debug_data, const char *format, ...);
uint8_t check_permissions(struct bt_gatt_server *server, struct gatt_db_attribute *attr, uint8_t mask);
struct bt_gatt_server *bt_gatt_server_ref(struct bt_gatt_server *server);
bool gatt_db_attribute_write(struct gatt_db_attribute *attr, uint16_t offset, const void *value, uint16_t length, uint8_t opcode, void *att, void (*write_complete_cb)(void *), struct async_write_op *op);
void async_write_op_destroy(struct async_write_op *op);
void bt_att_chan_send_error_rsp(struct bt_att_chan *chan, uint8_t opcode, uint16_t handle, uint8_t ecode);
void write_complete_cb(void *op);
struct gatt_db_attribute *gatt_db_get_attribute(void *db, uint16_t handle);

#define new0(type, count) calloc(count, sizeof(type))