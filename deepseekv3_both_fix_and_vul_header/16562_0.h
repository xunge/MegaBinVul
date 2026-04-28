#include <stdio.h>
#include <stddef.h>

int fit_image_get_data_and_size(const void *fit, int image_noffset, const void **data, size_t *size);
const char *fit_get_name(const void *fit, int noffset, const char *default_name);
int fit_image_verify_with_data(const void *fit, int image_noffset, const void *data, size_t size);