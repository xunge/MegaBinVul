#include <stdint.h>

typedef uint64_t guint64;
typedef int64_t gint64;
typedef int gboolean;

#define IS_FT_INT(type) ((type) == FT_INT32 || (type) == FT_INT64)
#define FT_INT32 1
#define FT_INT64 2

#define BASE_DEC 0
#define BASE_DEC_HEX 1
#define BASE_OCT 2
#define BASE_HEX 3
#define BASE_HEX_DEC 4

#define DISSECTOR_ASSERT_NOT_REACHED() abort()

typedef struct {
    int type;
} header_field_info;

static int _hfinfo_type_hex_octet(int type);

static const char *int64_to_str_back(char *ptr, gint64 value);
static const char *uint64_to_str_back(char *ptr, guint64 value);
static const char *hex64_to_str_back(char *ptr, int hex_octet, guint64 value);
static const char *oct64_to_str_back(char *ptr, guint64 value);