#include <stddef.h>
#include <stdbool.h>

int base64_encode_base(const void *data_in, size_t data_in_size,
                      unsigned char *base64_out, size_t *base64_out_size, bool padding);