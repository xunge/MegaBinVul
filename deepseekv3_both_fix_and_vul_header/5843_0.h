#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    STRINGPREP_OK,
    STRINGPREP_ICONV_ERROR,
    STRINGPREP_MALLOC_ERROR,
    STRINGPREP_TOO_SMALL_BUFFER
} Stringprep_profile_flags;

typedef struct {
    // Add necessary fields for Stringprep_profile
} Stringprep_profile;

extern uint32_t *stringprep_utf8_to_ucs4(const char *str, ssize_t len, size_t *items_written);
extern char *stringprep_ucs4_to_utf8(const uint32_t *str, size_t len, size_t *items_read, size_t *items_written);
extern int stringprep_4i(uint32_t *ucs4, size_t *ucs4len, size_t maxucs4len, Stringprep_profile_flags flags, const Stringprep_profile *profile);