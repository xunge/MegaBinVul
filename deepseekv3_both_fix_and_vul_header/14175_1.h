#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct gatt_db_attribute;
struct bt_att;
struct btd_device;
struct external_chrc {
    struct gatt_db_attribute *attrib;
    void *proxy;
    void *pending_reads;
};

enum {
    BT_ATT_ERROR_UNLIKELY = 0x0E
};

bool send_read_att(struct bt_att *att, struct gatt_db_attribute *attrib,
                  void *proxy, void *pending_reads, unsigned int id,
                  uint16_t offset);
bool send_read_device(struct btd_device *device, struct gatt_db_attribute *attrib,
                     void *proxy, void *pending_reads, unsigned int id,
                     uint16_t offset, uint8_t link_type);
struct btd_device *att_get_device(struct bt_att *att);
uint8_t bt_att_get_link_type(struct bt_att *att);
void gatt_db_attribute_read_result(struct gatt_db_attribute *attrib,
                                 unsigned int id, uint8_t error,
                                 const uint8_t *value, size_t length);
void error(const char *msg);