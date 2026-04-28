#include <stdlib.h>

#define SC_SUCCESS 0

struct sc_card;
struct sc_path {
    // dummy definition since actual structure is unknown
    int dummy;
};
struct sc_file {
    size_t size;
    // dummy definition since actual structure is unknown
    int dummy;
};

int sc_select_file(struct sc_card *card, struct sc_path *path, struct sc_file **file);
void sc_format_path(char *str_path, struct sc_path *path);
int sc_read_binary(struct sc_card *card, int offset, unsigned char *buf, size_t len, int flags);
void sc_file_free(struct sc_file *file);