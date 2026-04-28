#include <stddef.h>
#include <stdint.h>

#define TRUE 1
#define FALSE 0
typedef int dbus_bool_t;

typedef struct DBusList DBusList;
typedef struct DBusConnection DBusConnection;
typedef struct DBusError DBusError;
typedef struct DBusMessage DBusMessage;

struct DBusList {
    void *data;
    DBusList *next;
    DBusList *prev;
};

struct DBusError {
    const char *name;
    const char *message;
    unsigned int dummy1 : 1;
    unsigned int dummy2 : 1;
    unsigned int dummy3 : 1;
    unsigned int dummy4 : 1;
    unsigned int dummy5 : 1;
    void *padding1;
};

typedef struct BusActivation {
    void *pending_activations;
} BusActivation;

typedef struct BusService BusService;
typedef struct BusTransaction BusTransaction;

typedef struct BusPendingActivation {
    DBusList entries;
} BusPendingActivation;

typedef struct BusPendingActivationEntry {
    dbus_bool_t auto_activation;
    DBusConnection *connection;
    DBusMessage *activation_message;
} BusPendingActivationEntry;

static inline DBusList* _dbus_list_get_first_link(DBusList *list) { return list; }
static inline DBusList* _dbus_list_get_next_link(DBusList *list, DBusList *link) { return link->next; }
static inline void* _dbus_hash_table_lookup_string(void *table, const char *key) { return NULL; }
static inline void _dbus_hash_table_remove_string(void *table, const char *key) {}
static inline int dbus_connection_get_is_connected(DBusConnection *conn) { return 1; }
static inline DBusConnection* bus_service_get_primary_owners_connection(BusService *service) { return NULL; }
static inline const char* bus_service_get_name(BusService *service) { return NULL; }
static inline int bus_dispatch_matches(BusTransaction *t, DBusConnection *c1, DBusConnection *c2, DBusMessage *m, DBusError *e) { return 1; }
static inline int add_restore_pending_to_transaction(BusTransaction *t, BusPendingActivation *p) { return 1; }
static inline void dbus_error_init(DBusError *error) {}
static inline int bus_transaction_send_error_reply(BusTransaction *t, DBusConnection *c, DBusError *e, DBusMessage *m) { return 1; }
static inline void bus_connection_send_oom_error(DBusConnection *c, DBusMessage *m) {}

#define _DBUS_ASSERT_ERROR_IS_CLEAR(e) do {} while (0)
#define BUS_SET_OOM(e) do { (e)->name = "org.freedesktop.DBus.Error.NoMemory"; } while (0)
#define _dbus_verbose(...) do {} while (0)