#include <stdlib.h>

typedef struct hb_buffer_t hb_buffer_t;
typedef struct hb_unicode_funcs_t hb_unicode_funcs_t;

struct hb_buffer_t {
    hb_unicode_funcs_t *unicode;
};

extern hb_unicode_funcs_t _hb_unicode_funcs_nil;
extern hb_buffer_t _hb_buffer_nil;

#define HB_OBJECT_DO_CREATE(type, obj) ((obj = malloc(sizeof(type))) != NULL)

void hb_buffer_ensure(hb_buffer_t *buffer, unsigned int size);