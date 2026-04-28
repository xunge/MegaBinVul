#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define BDADDR_BREDR 0x00

struct btd_adapter {
    bool filtered_discovery;
    bool no_scan_restart_delay;
    void *current_discovery_filter;
    bool discovering;
    struct {
        void *data;
        struct btd_adapter *next;
    } *connections;
    uint8_t dev_class;
    const char *path;
};

struct btd_device;

extern void *dbus_conn;
#define ADAPTER_INTERFACE "org.bluez.Adapter1"

uint8_t btd_device_get_bdaddr_type(struct btd_device *device);
void adapter_remove_connection(struct btd_adapter *adapter, struct btd_device *device, uint8_t addr_type);
void reply_pending_requests(struct btd_adapter *adapter);
void cancel_passive_scanning(struct btd_adapter *adapter);
void remove_discovery_list(struct btd_adapter *adapter);
void discovery_cleanup(struct btd_adapter *adapter, int cleanup_type);
void g_dbus_emit_property_changed(void *conn, const char *path, const char *interface, const char *property);
#define g_free free
#define DBG(fmt, ...)