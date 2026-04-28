#include <stdlib.h>
#include <string.h>

typedef struct jas_iccattrval_s {
    struct {
        struct {
            char *string;
        } txt;
    } data;
} jas_iccattrval_t;

typedef struct jas_icctxt_s {
    char *string;
} jas_icctxt_t;

typedef struct jas_stream_s jas_stream_t;

void *jas_malloc(size_t size);
int jas_stream_read(jas_stream_t *in, void *buf, unsigned cnt);
void jas_icctxt_destroy(jas_iccattrval_t *attrval);