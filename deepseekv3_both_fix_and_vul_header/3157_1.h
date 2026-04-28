#include <stddef.h>

#define READ 0

typedef struct chunk_t chunk_t;
struct chunk_t {
    // Define chunk_t members as needed
};

struct pstore {
    int current_area;
    // Define other pstore members as needed
};

static int area_io(struct pstore *ps, int op);
static int insert_exceptions(struct pstore *ps,
                            int (*callback)(void *, chunk_t, chunk_t),
                            void *callback_context,
                            int *full);