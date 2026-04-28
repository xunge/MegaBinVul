#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

struct pending_op;
struct bt_att;
struct gatt_db_attribute;
struct btd_device;
struct queue;

struct external_chrc {
    struct queue *pending_writes;
    void *proxy;
};

typedef void (*acquire_write_setup_t)(void);
typedef void (*acquire_write_reply_t)(void);

extern acquire_write_setup_t acquire_write_setup;
extern acquire_write_reply_t acquire_write_reply;

struct pending_op *pending_write_new(void *arg1, struct queue *queue,
                    struct gatt_db_attribute *attrib,
                    unsigned int id, const uint8_t *value,
                    size_t len, int arg2, ...);
void pending_op_free(struct pending_op *op);
bool queue_isempty(struct queue *queue);
bool g_dbus_proxy_method_call(void *proxy, const char *method,
                void *setup_func, void *reply_func,
                void *user_data, void *destroy_func);