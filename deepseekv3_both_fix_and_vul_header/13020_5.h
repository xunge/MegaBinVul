#include <stddef.h>

typedef struct memcached_instance_st memcached_instance_st;
typedef struct Memcached Memcached;
typedef struct memcached_result_st memcached_result_st;

typedef enum {
    MEMCACHED_FETCH_NOTFINISHED,
    MEMCACHED_TIMEOUT,
} memcached_return_t;

struct memcached_result_st {
    int dummy;
};

struct memcached_instance_st {
    Memcached *root;
};

struct Memcached {
    struct memcached_result_st result;
};

memcached_return_t binary_read_one_response(memcached_instance_st *instance, char *buffer, size_t buffer_length, struct memcached_result_st *result);
memcached_return_t textual_read_one_response(memcached_instance_st *instance, char *buffer, size_t buffer_length, struct memcached_result_st *result);
void memcached_server_response_decrement(memcached_instance_st *instance);
int memcached_is_binary(Memcached *root);
int memcached_fatal(memcached_return_t rc);
void memcached_io_reset(memcached_instance_st *instance);