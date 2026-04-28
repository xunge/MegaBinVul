#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef struct header_field_info {
    int type;
} header_field_info;

#define IS_FT_INT(type) ((type) == FT_INT32 || (type) == FT_INT16 || (type) == FT_INT8)
#define FT_INT32 0
#define FT_INT16 1
#define FT_INT8 2

#define BASE_DEC 0
#define BASE_DEC_HEX 1
#define BASE_OCT 2
#define BASE_HEX 3
#define BASE_HEX_DEC 4

#define DISSECTOR_ASSERT_NOT_REACHED() assert(0)

typedef uint32_t guint32;
typedef int32_t gint32;
typedef bool gboolean;

static int _hfinfo_type_hex_octet(int type) {
    return 0;
}

static char* int_to_str_back(char* ptr, gint32 value) {
    return ptr;
}

static char* uint_to_str_back(char* ptr, guint32 value) {
    return ptr;
}

static char* hex_to_str_back(char* ptr, int hex_octet, guint32 value) {
    return ptr;
}

static char* oct_to_str_back(char* ptr, guint32 value) {
    return ptr;
}