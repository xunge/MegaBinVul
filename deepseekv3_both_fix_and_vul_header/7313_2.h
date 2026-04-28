#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct discovery_client;
struct btd_adapter;

#define MGMT_OP_STOP_DISCOVERY 0
#define ADAPTER_INTERFACE "org.bluez.Adapter1"
#define EINPROGRESS 115

struct mgmt_cp_stop_discovery {
    uint8_t type;
};

struct btd_adapter {
    void *discovery_list;
    bool discovery_discoverable;
    uint8_t discovery_enable;
    bool discovering;
    uint8_t discovery_type;
    void *mgmt;
    uint16_t dev_id;
    struct discovery_client *client;
    const char *path;
};

struct discovery_client {
    struct btd_adapter *adapter;
};

void *g_slist_next(void *list);
void discovery_remove(struct discovery_client *client);
void update_discovery_filter(struct btd_adapter *adapter);
void set_discovery_discoverable(struct btd_adapter *adapter, bool enable);
void trigger_passive_scanning(struct btd_adapter *adapter);
void mgmt_send(void *mgmt, uint16_t opcode, uint16_t index, uint16_t length, const void *param, void *callback, void *user_data, void *destroy);
void stop_discovery_complete(void *user_data);
void g_dbus_emit_property_changed(void *conn, const char *path, const char *interface, const char *property);

extern void *dbus_conn;