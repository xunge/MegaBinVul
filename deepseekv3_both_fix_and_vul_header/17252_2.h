#include <stdint.h>
#include <stdbool.h>

typedef bool gboolean;
typedef int32_t gint;
typedef uint32_t guint;

#define FALSE false
#define TRUE true

typedef struct tvbuff_t {
    gboolean initialized;
} tvbuff_t;

extern int check_offset_length_no_exception(const tvbuff_t *tvb, gint offset, gint length, guint *abs_offset, guint *abs_length);

#define DISSECTOR_ASSERT(expr)