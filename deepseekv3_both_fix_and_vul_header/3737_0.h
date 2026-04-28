#include <stdint.h>
#include <stddef.h>

#define BASE64_SUCCESS 0
#define BASE64_ERROR_DATA_IN -1
#define BASE64_ERROR_DATA_IN_SIZE -2
#define BASE64_ERROR_BUFFER_OUT_SIZE -3
#define BASE64_ERROR_BUFFER_OUT -4
#define BASE64_NOT_DEFINED -5
#define BASE64_EQUALS -6

size_t base64_estimate_decode_size(size_t base64_in_size);
int getcode(unsigned char c);