#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define TRUE true

struct bt_att;
struct btd_device;
struct gatt_db_attribute;
struct queue;
struct pending_op;
typedef struct _GDBusProxy GDBusProxy;

struct pending_op *pending_read_new_att(struct bt_att *att, struct queue *owner_queue,
                                      struct gatt_db_attribute *attrib, unsigned int id,
                                      uint16_t offset);
struct pending_op *pending_read_new_dev(struct btd_device *device, struct queue *owner_queue,
                                      struct gatt_db_attribute *attrib, unsigned int id,
                                      uint16_t offset, uint8_t link_type);
void pending_op_free(void *op);
bool g_dbus_proxy_method_call(GDBusProxy *proxy, const char *method,
                            void (*setup_cb)(void *), void (*reply_cb)(void *),
                            void *user_data, void (*destroy_cb)(void *));
void read_setup_cb(void *data);
void read_reply_cb(void *data);