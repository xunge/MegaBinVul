#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct bt_att;
struct btd_device;
struct gatt_db_attribute;
struct queue;

struct pending_op {
    struct queue *owner_queue;
    union {
        struct bt_att *att;
        struct btd_device *device;
    };
    struct gatt_db_attribute *attrib;
    unsigned int id;
    uint16_t offset;
    uint8_t link_type;
    unsigned int disconn_id;
};

#define new0(type, count) (type *)calloc(count, sizeof(type))

static struct bt_att *bt_att_ref(struct bt_att *att) { return att; }
static uint8_t bt_att_get_link_type(struct bt_att *att) { return 0; }
static unsigned int bt_att_register_disconnect(struct bt_att *att, void (*cb)(void *), void *user_data, void *user_data_free) { return 0; }
static void pending_disconnect_cb(void *user_data) {}
static void queue_push_tail(struct queue *queue, void *data) {}