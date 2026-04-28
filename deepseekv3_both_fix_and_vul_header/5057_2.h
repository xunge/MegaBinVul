#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum {
    GATTLIB_SEC_LOW,
    GATTLIB_SEC_MEDIUM,
    GATTLIB_SEC_HIGH
} gattlib_bt_sec_level_t;

typedef struct gattlib_context {
    void* device;
    char* device_object_path;
} gattlib_context_t;

typedef struct gatt_connection {
    gattlib_context_t* context;
} gatt_connection_t;

typedef struct {
    char* message;
} GError;

typedef enum {
    G_BUS_TYPE_SYSTEM
} GBusType;

typedef enum {
    G_DBUS_OBJECT_MANAGER_CLIENT_FLAGS_NONE
} GDBusObjectManagerClientFlags;

typedef void* OrgBluezDevice1;
typedef void* GMainLoop;

#define CONNECT_TIMEOUT 30

OrgBluezDevice1 org_bluez_device1_proxy_new_for_bus_sync(GBusType bus_type, 
    GDBusObjectManagerClientFlags flags, const char* name, const char* object_path, 
    void* cancellable, GError** error);

int org_bluez_device1_call_connect_sync(OrgBluezDevice1 device, 
    void* cancellable, GError** error);

GMainLoop* g_main_loop_new(void* context, int is_running);
void g_main_loop_run(GMainLoop* loop);
void g_main_loop_unref(GMainLoop* loop);

void g_signal_connect(void* instance, const char* detailed_signal, 
    void* c_handler, void* data);

void g_timeout_add_seconds(unsigned int interval, int (*function)(void*), 
    void* data);

void g_object_unref(void* object);

void on_handle_device_property_change(void* device, void* changed_properties, 
    char** invalidated_properties, void* user_data);

int stop_scan_func(void* user_data);