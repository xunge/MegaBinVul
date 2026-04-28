#include <stdint.h>
#include <stdbool.h>

struct btd_adapter {
    uint32_t current_settings;
    uint32_t pending_settings;
    const char *path;
    bool discovery_discoverable;
    void *adv_manager;
};

extern void *dbus_conn;
extern bool powering_down;
extern int adapter_remaining;

#define ADAPTER_INTERFACE "org.bluez.Adapter1"
#define DBG(fmt, ...) 
#define MGMT_SETTING_POWERED (1 << 0)
#define MGMT_SETTING_LE (1 << 1)
#define MGMT_SETTING_DISCOVERABLE (1 << 2)
#define MGMT_SETTING_BONDABLE (1 << 3)

void g_dbus_emit_property_changed(void *conn, const char *path, const char *interface, const char *property);
void adapter_start(struct btd_adapter *adapter);
void adapter_stop(struct btd_adapter *adapter);
void btd_exit(void);
bool btd_adapter_get_powered(struct btd_adapter *adapter);
void trigger_passive_scanning(struct btd_adapter *adapter);
void store_adapter_info(struct btd_adapter *adapter);
void btd_adv_manager_refresh(void *manager);
void trigger_pairable_timeout(struct btd_adapter *adapter);