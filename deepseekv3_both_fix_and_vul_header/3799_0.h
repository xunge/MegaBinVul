#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gs_param_list_s gs_param_list;
typedef struct gs_param_float_array_s {
    float *data;
    size_t size;
} gs_param_float_array;
typedef struct gs_param_int_array_s {
    int *data;
    size_t size;
} gs_param_int_array;

#define gs_error_rangecheck 1
#define return_error(code) return code

int param_read_float_array(gs_param_list *plist, const char *param_name, gs_param_float_array *array);
int param_read_int_array(gs_param_list *plist, const char *param_name, gs_param_int_array *array);
int is_supported_resolution(float *data);