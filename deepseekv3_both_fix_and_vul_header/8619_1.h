#include <stdint.h>
#include <stdbool.h>

typedef uint8_t guint8;
typedef int8_t gint8;
typedef bool gboolean;

#define FALSE false
#define TRUE true

#define ARG_INVALID 0
#define ARG_ARRAY 1
#define ARG_STRUCT 2
#define ARG_DICT_ENTRY 3
#define ARG_BYTE 4
#define ARG_DOUBLE 5
#define ARG_UINT64 6
#define ARG_INT64 7
#define ARG_SIGNATURE 8
#define ARG_HANDLE 9
#define ARG_INT32 10
#define ARG_UINT32 11
#define ARG_BOOLEAN 12
#define ARG_INT16 13
#define ARG_UINT16 14
#define ARG_STRING 15
#define ARG_VARIANT 16
#define ARG_OBJ_PATH 17