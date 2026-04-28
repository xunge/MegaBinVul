#include <stdint.h>
#include <string.h>

typedef uint8_t lit_utf8_byte_t;
typedef size_t lit_utf8_size_t;
typedef uint32_t lit_code_point_t;

#define LIT_UTF16_FIRST_SURROGATE_CODE_POINT 0xD800
#define JERRY_ASSERT(x) ((void)0)

lit_utf8_size_t lit_read_code_point_from_cesu8(const lit_utf8_byte_t *cesu8_cursor_p,
                                              const lit_utf8_byte_t *cesu8_end_p,
                                              lit_code_point_t *cp);

void lit_code_point_to_utf8(lit_code_point_t cp, lit_utf8_byte_t *utf8_cursor_p);