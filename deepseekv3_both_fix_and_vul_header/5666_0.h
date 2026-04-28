#include <stdlib.h>

typedef struct x11_conv_data_t x11_conv_data_t;
struct x11_conv_data_t {
    void *eventcode_funcs;
    void *reply_funcs;
    void *seqtable;
    void *valtable;
    x11_conv_data_t *next;
};

extern x11_conv_data_t *x11_conv_data_list;