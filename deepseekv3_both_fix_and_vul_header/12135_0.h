#include <stdbool.h>

enum es_result {
    ES_OK
};

struct es_em_ctxt;

enum es_result vc_write_mem(struct es_em_ctxt *ctxt, void *d, char *b, unsigned int data_size);