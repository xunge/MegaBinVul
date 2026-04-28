#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define TRUE true
#define FALSE false

struct DBusError {
    const char *name;
    const char *message;
    unsigned int dummy1;
    unsigned int dummy2;
};

struct DBusMessageIter {
    void *dummy1;
    void *dummy2;
    unsigned int dummy3;
    unsigned int dummy4;
    unsigned int dummy5;
    unsigned int dummy6;
    unsigned int dummy7;
    unsigned int dummy8;
};

typedef struct DBusMessage DBusMessage;
typedef struct DBusError DBusError;
typedef struct DBusMessageIter DBusMessageIter;

struct pending_op {
    void *owner_queue;
    bool prep_authorize;
    bool is_characteristic;
    void *attrib;
    unsigned int id;
    void *att;
};

struct external_chrc {
    bool prep_authorized;
};

struct external_desc {
    bool prep_authorized;
};

#define DBG(fmt, ...)
#define error(fmt, ...)

#define BT_ATT_ERROR_WRITE_NOT_PERMITTED 0
#define BT_ATT_ERROR_REQUEST_NOT_SUPPORTED 0

void *gatt_db_attribute_get_user_data(void *attrib);
void gatt_db_attribute_write_result(void *attrib, unsigned int id, uint8_t ecode);
uint8_t dbus_error_to_att_ecode(const char *name, uint8_t default_ecode);
void dbus_error_init(DBusError *err);
bool dbus_set_error_from_message(DBusError *err, DBusMessage *message);
void dbus_error_free(DBusError *err);
void dbus_message_iter_init(DBusMessage *message, DBusMessageIter *iter);
bool dbus_message_iter_has_next(DBusMessageIter *iter);
bool bt_att_get_fd(void *att);