#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JS_SUCCESS 0
#define JS_ERROR -1
#define RRSUB_DLABEL 64
#define RRSUB_TEXT 65
#define RRSUB_VARIABLE 66

typedef struct {
    char *string;
} js_string;

int decomp_get_rrdesc(int type);
int decomp_append_bytes(js_string *compressed, js_string *out, unsigned int offset, int length);
int decomp_append_dlabel(js_string *compressed, js_string *out, unsigned int offset);