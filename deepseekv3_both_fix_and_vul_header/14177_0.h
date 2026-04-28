#include <stdlib.h>

struct pending_op {
    void *owner_queue;
    void *att;
    unsigned int disconn_id;
};