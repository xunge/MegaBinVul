#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct gatt_db_attribute;
struct bt_att;
struct btd_device;
struct external_desc;

enum {
    BT_ATT_OP_PREP_WRITE_REQ,
    BT_ATT_OP_EXEC_WRITE_REQ,
    BT_ATT_ERROR_UNLIKELY
};

struct external_desc {
    struct gatt_db_attribute *attrib;
    bool prep_authorized;
    bool req_prep_authorization;
    void *proxy;
    void *pending_writes;
};

struct btd_device *att_get_device(struct bt_att *att);
bool device_is_trusted(struct btd_device *device);
bool send_write(void *device_or_att, struct gatt_db_attribute *attrib, void *proxy,
                void *pending_writes, unsigned int id, const uint8_t *value,
                size_t len, uint16_t offset, ...);
void gatt_db_attribute_write_result(struct gatt_db_attribute *attrib,
                                   unsigned int id, int error);
void error(const char *message);
bool bt_att_get_link_type(struct bt_att *att);