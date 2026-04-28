#include <stdint.h>
#include <stdbool.h>
#include <sys/uio.h>
#include <stdlib.h>

struct pending_op {
    struct iovec data;
    union {
        struct bt_att *att;
        struct btd_device *device;
    };
    struct queue *owner_queue;
    struct gatt_db_attribute *attrib;
    unsigned int id;
    uint16_t offset;
    uint8_t link_type;
    bool is_characteristic;
    bool prep_authorize;
};

struct bt_att;
struct btd_device;
struct queue;
struct gatt_db_attribute;

struct bt_att *bt_att_ref(struct bt_att *att);
uint8_t bt_att_get_link_type(struct bt_att *att);
void bt_att_register_disconnect(struct bt_att *att, void (*cb)(void *, void *), void *user_data, void *user_data2);
void queue_push_tail(struct queue *queue, void *data);
void pending_disconnect_cb(void *user_data, void *user_data2);

#define new0(type, count) calloc(count, sizeof(type))