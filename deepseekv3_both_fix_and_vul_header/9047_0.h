#include <stdint.h>

typedef struct DWTContext {
    int ndeclevels;
    int type;
} DWTContext;

#define FF_DWT97   0
#define FF_DWT97_INT 1
#define FF_DWT53   2

void dwt_decode97_float(DWTContext *s, void *t);
void dwt_decode97_int(DWTContext *s, void *t);
void dwt_decode53(DWTContext *s, void *t);