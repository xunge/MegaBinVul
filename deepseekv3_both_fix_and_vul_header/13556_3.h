#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define TRUE true
#define FALSE false

typedef bool dbus_bool_t;
typedef uint32_t dbus_uint32_t;

typedef struct DBusError {
    const char *name;
    const char *message;
    bool dummy;
} DBusError;

typedef struct DBusConnection DBusConnection;
typedef struct DBusMessage DBusMessage;

typedef struct BusContext BusContext;

typedef struct BusTransaction {
    BusContext *context;
} BusTransaction;

#define DBUS_SERVICE_DBUS "org.freedesktop.DBus"
#define DBUS_SYSTEM_LOG_WARNING 4
#define DBUS_ERROR_INIT { NULL, NULL, false }

extern void _dbus_verbose(const char *format, ...);
extern dbus_uint32_t _dbus_connection_get_next_client_serial(DBusConnection *connection);
extern const char *dbus_message_get_interface(DBusMessage *message);
extern const char *dbus_message_get_member(DBusMessage *message);
extern const char *dbus_message_get_error_name(DBusMessage *message);
extern dbus_bool_t dbus_message_set_sender(DBusMessage *message, const char *sender);
extern dbus_uint32_t dbus_message_get_serial(DBusMessage *message);
extern void dbus_message_set_serial(DBusMessage *message, dbus_uint32_t serial);
extern dbus_bool_t bus_connection_is_active(DBusConnection *connection);
extern const char *bus_connection_get_name(DBusConnection *connection);
extern dbus_bool_t dbus_message_set_destination(DBusMessage *message, const char *destination);
extern void dbus_message_set_no_reply(DBusMessage *message, dbus_bool_t no_reply);
extern dbus_bool_t bus_transaction_capture(BusTransaction *transaction, void *unused, DBusConnection *connection, DBusMessage *message);
extern BusContext *bus_transaction_get_context(BusTransaction *transaction);
extern dbus_bool_t bus_context_check_security_policy(BusContext *context, BusTransaction *transaction, void *unused1, DBusConnection *sender, DBusConnection *receiver, DBusMessage *message, void *unused2, DBusError *error);
extern dbus_bool_t bus_transaction_capture_error_reply(BusTransaction *transaction, DBusConnection *connection, DBusError *error, DBusMessage *message);
extern void bus_context_log(BusContext *context, int level, const char *format, ...);
extern void dbus_error_free(DBusError *error);
extern dbus_bool_t bus_transaction_send(BusTransaction *transaction, void *unused, DBusConnection *connection, DBusMessage *message);