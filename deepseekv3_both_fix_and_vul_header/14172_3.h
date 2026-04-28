#include <stdint.h>
#include <stddef.h>

struct gatt_db_attribute;
struct bt_att;
struct btd_device;

struct external_desc {
    struct gatt_db_attribute *attrib;
    void *proxy;
    void *pending_reads;
};

enum {
    BT_ATT_ERROR_UNLIKELY = 0x0E
};

int send_read_att(struct bt_att *att, struct gatt_db_attribute *attrib, 
                 void *proxy, void *pending_reads, unsigned int id, 
                 uint16_t offset);
int send_read_device(struct btd_device *device, struct gatt_db_attribute *attrib,
                    void *proxy, void *pending_reads, unsigned int id,
                    uint16_t offset, int link_type);

void gatt_db_attribute_read_result(struct gatt_db_attribute *attrib,
                                 unsigned int id, uint8_t error,
                                 const void *data, size_t length);
struct btd_device *att_get_device(struct bt_att *att);
int bt_att_get_link_type(struct bt_att *att);
void error(const char *msg);