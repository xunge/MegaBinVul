#include <stdint.h>
#include <stddef.h>

typedef enum {
    DBUS_VALID,
    DBUS_INVALID_SIGNATURE_TOO_LONG,
    DBUS_INVALID_EXCEEDED_MAXIMUM_ARRAY_RECURSION,
    DBUS_INVALID_EXCEEDED_MAXIMUM_STRUCT_RECURSION,
    DBUS_INVALID_STRUCT_ENDED_BUT_NOT_STARTED,
    DBUS_INVALID_STRUCT_HAS_NO_FIELDS,
    DBUS_INVALID_DICT_ENTRY_NOT_INSIDE_ARRAY,
    DBUS_INVALID_EXCEEDED_MAXIMUM_DICT_ENTRY_RECURSION,
    DBUS_INVALID_DICT_ENTRY_ENDED_BUT_NOT_STARTED,
    DBUS_INVALID_DICT_ENTRY_HAS_NO_FIELDS,
    DBUS_INVALID_DICT_ENTRY_HAS_ONLY_ONE_FIELD,
    DBUS_INVALID_DICT_ENTRY_HAS_TOO_MANY_FIELDS,
    DBUS_INVALID_UNKNOWN_TYPECODE,
    DBUS_INVALID_MISSING_ARRAY_ELEMENT_TYPE,
    DBUS_INVALID_DICT_KEY_MUST_BE_BASIC_TYPE,
    DBUS_INVALID_STRUCT_STARTED_BUT_NOT_ENDED,
    DBUS_INVALID_DICT_ENTRY_STARTED_BUT_NOT_ENDED,
    DBUS_VALIDITY_UNKNOWN_OOM_ERROR
} DBusValidity;

typedef struct DBusString DBusString;
typedef struct DBusList DBusList;

#define DBUS_MAXIMUM_SIGNATURE_LENGTH 255
#define DBUS_MAXIMUM_TYPE_RECURSION_DEPTH 32

#define DBUS_TYPE_INVALID ((int) '\0')
#define DBUS_TYPE_BYTE ((int) 'y')
#define DBUS_TYPE_BOOLEAN ((int) 'b')
#define DBUS_TYPE_INT16 ((int) 'n')
#define DBUS_TYPE_UINT16 ((int) 'q')
#define DBUS_TYPE_INT32 ((int) 'i')
#define DBUS_TYPE_UINT32 ((int) 'u')
#define DBUS_TYPE_UNIX_FD ((int) 'h')
#define DBUS_TYPE_INT64 ((int) 'x')
#define DBUS_TYPE_UINT64 ((int) 't')
#define DBUS_TYPE_DOUBLE ((int) 'd')
#define DBUS_TYPE_STRING ((int) 's')
#define DBUS_TYPE_OBJECT_PATH ((int) 'o')
#define DBUS_TYPE_SIGNATURE ((int) 'g')
#define DBUS_TYPE_VARIANT ((int) 'v')
#define DBUS_TYPE_ARRAY ((int) 'a')
#define DBUS_TYPE_STRUCT ((int) 'r')
#define DBUS_TYPE_DICT_ENTRY ((int) 'e')
#define DBUS_STRUCT_BEGIN_CHAR ((int) '(')
#define DBUS_STRUCT_END_CHAR ((int) ')')
#define DBUS_DICT_ENTRY_BEGIN_CHAR ((int) '{')
#define DBUS_DICT_ENTRY_END_CHAR ((int) '}')

#define _DBUS_INT_TO_POINTER(i) ((void*) (intptr_t) (i))
#define _DBUS_POINTER_TO_INT(p) ((int) (intptr_t) (p))
#define _DBUS_INT32_MAX (2147483647)

int dbus_type_is_valid(int typecode);
int dbus_type_is_basic(int typecode);

const unsigned char *_dbus_string_get_const_udata_len(const DBusString *str, int start, int len);
void _dbus_list_clear(DBusList **list);
void *_dbus_list_pop_last(DBusList **list);
int _dbus_list_append(DBusList **list, void *data);
void _dbus_assert(const char *condition);