#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0

struct bt_att;
struct btd_device;
struct gatt_db_attribute;
struct pending_op;
struct queue;
typedef struct _GDBusProxy GDBusProxy;

typedef int (*GDBusProxyMethodCallFunc)(GDBusProxy *proxy, const char *method_name,
                                      void (*setup_cb)(GDBusProxy *proxy, void *user_data),
                                      void (*reply_cb)(GDBusProxy *proxy, void *user_data),
                                      void *user_data, void (*free_func)(void *user_data));

extern GDBusProxyMethodCallFunc g_dbus_proxy_method_call;

struct pending_op *pending_write_new_att(struct bt_att *att, struct queue *owner_queue,
                                      struct gatt_db_attribute *attrib, unsigned int id,
                                      const uint8_t *value, size_t len, uint16_t offset,
                                      bool is_characteristic, bool prep_authorize);

struct pending_op *pending_write_new_device(struct btd_device *device, struct queue *owner_queue,
                                      struct gatt_db_attribute *attrib, unsigned int id,
                                      const uint8_t *value, size_t len, uint16_t offset,
                                      uint8_t link_type, bool is_characteristic,
                                      bool prep_authorize);

void pending_op_free(struct pending_op *op);
void write_setup_cb(GDBusProxy *proxy, void *user_data);
void write_reply_cb(GDBusProxy *proxy, void *user_data);