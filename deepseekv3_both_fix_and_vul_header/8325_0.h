#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define IDNA_MALLOC_ERROR 1
#define IDNA_STRINGPREP_ERROR 2
#define IDNA_CONTAINS_NON_LDH 3
#define IDNA_CONTAINS_MINUS 4
#define IDNA_CONTAINS_ACE_PREFIX 5
#define IDNA_PUNYCODE_ERROR 6
#define IDNA_INVALID_LENGTH 7
#define IDNA_SUCCESS 0

#define IDNA_ALLOW_UNASSIGNED 1
#define IDNA_USE_STD3_ASCII_RULES 2

#define STRINGPREP_TOO_SMALL_BUFFER 1
#define STRINGPREP_OK 0

#define PUNYCODE_SUCCESS 0

extern char *stringprep_ucs4_to_utf8(const uint32_t *in, ssize_t inlen, size_t *items_read, size_t *items_written);
extern int stringprep_nameprep(char *p, size_t len);
extern int stringprep_nameprep_no_unassigned(char *p, size_t len);
extern uint32_t *stringprep_utf8_to_ucs4(const char *p, ssize_t len, size_t *items_written);
extern int punycode_encode(size_t input_len, const uint32_t input[], const unsigned char case_flags[], size_t *output_len, char output[]);

static const char IDNA_ACE_PREFIX[] = "xn--";