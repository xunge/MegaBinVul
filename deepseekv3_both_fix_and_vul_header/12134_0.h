#include <stdbool.h>

enum es_result {
    ES_OK
};

struct es_em_ctxt;

enum es_result vc_read_mem(struct es_em_ctxt *ctxt, void *src, char *dst, unsigned int size);