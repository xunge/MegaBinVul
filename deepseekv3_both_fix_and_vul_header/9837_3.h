#include <stdint.h>
#include <string.h>
#include <assert.h>

#define FALSE 0
#define TRUE 1

#define DBUS_MAXIMUM_TYPE_RECURSION_DEPTH 32
#define DBUS_MAXIMUM_MESSAGE_LENGTH (128 * 1024 * 1024)
#define DBUS_INTERFACE_LOCAL "org.freedesktop.DBus.Local"
#define DBUS_PATH_LOCAL "/org/freedesktop/DBus/Local"
#define TYPE_OFFSET 0
#define BODY_LENGTH_OFFSET 4
#define FIELDS_ARRAY_LENGTH_OFFSET 8
#define DBUS_TYPE_INVALID 0
#define DBUS_TYPE_ARRAY 97
#define DBUS_TYPE_INT32 105
#define DBUS_TYPE_STRING 115
#define DBUS_TYPE_SIGNATURE 103
#define DBUS_STRUCT_BEGIN_CHAR 40
#define DBUS_STRUCT_END_CHAR 41
#define DBUS_DICT_ENTRY_BEGIN_CHAR 123
#define DBUS_DICT_ENTRY_END_CHAR 125
#define DBUS_HEADER_FIELD_SIGNATURE 1
#define DBUS_HEADER_FIELD_SENDER 2
#define DBUS_HEADER_FIELD_REPLY_SERIAL 3
#define DBUS_MESSAGE_TYPE_INVALID 0

typedef int dbus_bool_t;
typedef int32_t dbus_int32_t;

typedef enum {
    DBUS_VALID,
    DBUS_INVALID_UNKNOWN_TYPECODE,
    DBUS_INVALID_EXCEEDED_MAXIMUM_ARRAY_RECURSION,
    DBUS_INVALID_EXCEEDED_MAXIMUM_STRUCT_RECURSION,
    DBUS_INVALID_STRUCT_STARTED_BUT_NOT_ENDED,
    DBUS_INVALID_STRUCT_ENDED_BUT_NOT_STARTED,
    DBUS_INVALID_STRUCT_HAS_NO_FIELDS,
    DBUS_INVALID_BAD_MESSAGE_TYPE,
    DBUS_INVALID_MESSAGE_TOO_LONG,
    DBUS_INVALID_BAD_SENDER,
    DBUS_INVALID_USES_LOCAL_INTERFACE,
    DBUS_INVALID_USES_LOCAL_PATH,
    DBUS_INVALID_MISSING_INTERFACE,
    DBUS_INVALID_MISSING_REPLY_SERIAL,
    DBUS_INVALID_MISSING_ERROR_NAME,
    DBUS_INVALID_EXCEEDED_MAXIMUM_DICT_ENTRY_RECURSION,
    DBUS_INVALID_DICT_ENTRY_STARTED_BUT_NOT_ENDED,
    DBUS_INVALID_DICT_ENTRY_ENDED_BUT_NOT_STARTED,
    DBUS_INVALID_DICT_ENTRY_HAS_NO_FIELDS,
    DBUS_INVALID_NESTED_TOO_DEEPLY
} DBusValidity;

typedef struct {
    int length;
    char *data;
} DBusString;

typedef struct {
    int dummy;
} DBusHeader;

typedef struct {
    DBusHeader header;
    int byte_order;
} DBusMessage;

typedef struct {
    int sequence;
} DBusMessageDataIter;

static inline int _dbus_string_get_length(DBusString *str) { return str->length; }
static inline void _dbus_string_set_byte(DBusString *str, int pos, char byte) { str->data[pos] = byte; }
static inline int iter_get_sequence(DBusMessageDataIter *iter) { return iter->sequence; }
static inline void iter_next(DBusMessageDataIter *iter) { iter->sequence++; }
static inline DBusMessage *simple_method_call() { return NULL; }
static inline DBusMessage *simple_signal() { return NULL; }
static inline DBusMessage *simple_method_return() { return NULL; }
static inline DBusMessage *simple_error() { return NULL; }
static inline DBusMessage *message_with_nesting_levels(int levels) { return NULL; }
static inline dbus_bool_t dbus_message_append_args(DBusMessage *msg, ...) { return 0; }
static inline dbus_bool_t dbus_message_set_interface(DBusMessage *msg, const char *iface) { return 0; }
static inline dbus_bool_t dbus_message_set_path(DBusMessage *msg, const char *path) { return 0; }
static inline dbus_bool_t dbus_message_set_error_name(DBusMessage *msg, const char *name) { return 0; }
static inline void dbus_message_unref(DBusMessage *msg) {}
static inline dbus_bool_t _dbus_header_set_field_basic(DBusHeader *header, int field, int type, const void *value) { return 0; }
static inline dbus_bool_t _dbus_header_get_field_raw(DBusHeader *header, int field, void *value, int *pos) { return 0; }
static inline dbus_bool_t _dbus_header_delete_field(DBusHeader *header, int field) { return 0; }
static inline void _dbus_marshal_set_uint32(DBusString *str, int pos, uint32_t value, int byte_order) {}
static inline void generate_from_message(DBusString *data, DBusValidity *validity, DBusMessage *msg) {}

#define _dbus_assert(expr) assert(expr)
#define _dbus_assert_not_reached(msg) assert(0 && msg)