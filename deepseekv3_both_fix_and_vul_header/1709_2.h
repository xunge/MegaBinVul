#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct DBusTypeReader DBusTypeReader;
typedef struct DBusString DBusString;

#define DBUS_TYPE_INVALID 0
#define DBUS_TYPE_BYTE 1
#define DBUS_TYPE_INT16 2
#define DBUS_TYPE_UINT16 3
#define DBUS_TYPE_BOOLEAN 4
#define DBUS_TYPE_INT32 5
#define DBUS_TYPE_UINT32 6
#define DBUS_TYPE_INT64 7
#define DBUS_TYPE_UINT64 8
#define DBUS_TYPE_DOUBLE 9
#define DBUS_TYPE_ARRAY 10
#define DBUS_TYPE_STRING 11
#define DBUS_TYPE_OBJECT_PATH 12
#define DBUS_TYPE_SIGNATURE 13
#define DBUS_TYPE_VARIANT 14
#define DBUS_TYPE_STRUCT 15
#define DBUS_TYPE_DICT_ENTRY 16
#define DBUS_TYPE_UNIX_FD 17

#define DBUS_MAXIMUM_ARRAY_LENGTH (256 * 1024 * 1024)
#define TRUE true
#define FALSE false

typedef uint16_t dbus_uint16_t;
typedef uint32_t dbus_uint32_t;
typedef uint64_t dbus_uint64_t;
typedef bool dbus_bool_t;

#define DBUS_UINT16_SWAP_LE_BE(val) ((uint16_t)(((val) << 8) | ((val) >> 8)))
#define DBUS_UINT32_SWAP_LE_BE(val) ((uint32_t)((((val) & 0xff000000) >> 24) | \
                                               (((val) & 0x00ff0000) >> 8)  | \
                                               (((val) & 0x0000ff00) << 8)  | \
                                               (((val) & 0x000000ff) << 24)))
#define DBUS_UINT64_SWAP_LE_BE(val) ((uint64_t)((((val) & 0xff00000000000000ULL) >> 56) | \
                                               (((val) & 0x00ff000000000000ULL) >> 40) | \
                                               (((val) & 0x0000ff0000000000ULL) >> 24) | \
                                               (((val) & 0x000000ff00000000ULL) >> 8)  | \
                                               (((val) & 0x00000000ff000000ULL) << 8)  | \
                                               (((val) & 0x0000000000ff0000ULL) << 24) | \
                                               (((val) & 0x000000000000ff00ULL) << 40) | \
                                               (((val) & 0x00000000000000ffULL) << 56)))

#define _DBUS_ALIGN_ADDRESS(p, alignment) \
    ((unsigned char *)((((uintptr_t)(p)) + ((alignment)-1)) & ~((uintptr_t)((alignment)-1))))

struct DBusTypeReader {
    int dummy;
};

struct DBusString {
    const char *str;
    size_t len;
};

static inline void _dbus_assert(bool condition) {
    if (!condition) __builtin_trap();
}

static inline void _dbus_assert_not_reached(const char *message) {
    (void)message;
    __builtin_trap();
}