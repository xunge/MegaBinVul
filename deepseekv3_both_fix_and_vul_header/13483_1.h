#include <stdlib.h>
#include <string.h>

typedef struct DBusConnection DBusConnection;
typedef struct DBusMessage DBusMessage;
typedef struct DBusError DBusError;
typedef enum {
    DBUS_HANDLER_RESULT_HANDLED,
    DBUS_HANDLER_RESULT_NOT_YET_HANDLED,
    DBUS_HANDLER_RESULT_NEED_MEMORY
} DBusHandlerResult;

#define DBUS_TYPE_STRING 0
#define DBUS_TYPE_INVALID 0
#define AVAHI_ERR_NOT_FOUND (-1)

char* avahi_alternative_service_name(const char* name);
void avahi_dbus_respond_string(DBusConnection *c, DBusMessage *m, const char *t);
void avahi_free(void *p);
DBusHandlerResult avahi_dbus_respond_error(DBusConnection *c, DBusMessage *m, int error, const char *message);
DBusHandlerResult dbus_parsing_error(const char *message, DBusError *error);
int dbus_message_get_args(DBusMessage *message, DBusError *error, int first_arg_type, ...);