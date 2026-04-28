#include <stdint.h>
#include <stddef.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>

struct bt_att;
struct gatt_db_attribute;
struct btd_device;

struct pending_op {
    struct iovec data;
    struct bt_att *att;
    struct gatt_db_attribute *attrib;
    struct btd_device *device;
    uint8_t link_type;
};

struct bt_att *bt_att_ref(struct bt_att *att);
void bt_att_register_disconnect(struct bt_att *att,
                               void (*callback)(void *),
                               void *user_data,
                               void *destroy);
struct btd_device *att_get_device(struct bt_att *att);
void pending_disconnect_cb(void *user_data);

#define UINT_TO_PTR(x) ((void *)(uintptr_t)(x))
#define error(fmt) fprintf(stderr, fmt "\n")
#define new0(type, count) calloc(count, sizeof(type))