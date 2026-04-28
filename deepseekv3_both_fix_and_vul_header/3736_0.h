#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define BASE64_SUCCESS 0
#define BASE64_ERROR_DATA_IN -1
#define BASE64_ERROR_BUFFER_OUT_SIZE -2
#define BASE64_ERROR_BUFFER_OUT -3

static size_t base64_estimate_encode_size(size_t data_in_size);
static char getsymbol(uint8_t n_num, bool urlsafe);