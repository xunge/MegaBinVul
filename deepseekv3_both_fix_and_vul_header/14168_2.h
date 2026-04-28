#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct DBusMessageIter DBusMessageIter;

#define DBUS_TYPE_OBJECT_PATH 0
#define DBUS_TYPE_UINT16 0
#define DBUS_TYPE_STRING 0
#define DBUS_TYPE_BOOLEAN 0

enum bt_att_type {
    BT_ATT_BREDR,
    BT_ATT_LE
};

struct pending_op {
    void *att;
    struct btd_device *device;
    uint16_t offset;
    enum bt_att_type link_type;
    bool prep_authorize;
};

struct btd_device;
struct bt_gatt_server;

const char *device_get_path(struct btd_device *device);
struct bt_gatt_server *btd_device_get_gatt_server(struct btd_device *device);
uint16_t bt_gatt_server_get_mtu(struct bt_gatt_server *server);
void dict_append_entry(DBusMessageIter *iter, const char *key, int type, void *value);