#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <sys/socket.h>

typedef struct memcached_instance_st memcached_instance_st;
typedef struct Memcached Memcached;
typedef struct memcached_result_st memcached_result_st;
typedef struct memcached_callback_st memcached_callback_st;

enum memcached_return_t {
    MEMCACHED_SUCCESS,
    MEMCACHED_PROTOCOL_ERROR,
    MEMCACHED_UNKNOWN_READ_FAILURE,
    MEMCACHED_READ_FAILURE,
    MEMCACHED_TIMEOUT
};

#define INVALID_SOCKET (-1)
#define MEMCACHED_WRITE_FAILURE 0
#define MEMCACHED_AT 0

struct memcached_instance_st {
    Memcached *root;
    int fd;
    size_t io_bytes_sent;
};

struct Memcached {
    size_t io_msg_watermark;
    size_t io_bytes_watermark;
    memcached_callback_st *callbacks;
};

struct memcached_result_st {
};

struct memcached_callback_st {
    uint32_t number_of_callback;
    memcached_return_t (**callback)(Memcached*, memcached_result_st*, void*);
    void *context;
};

class Purge {
public:
    Purge(Memcached*);
    ~Purge();
};

class PollTimeout {
public:
    PollTimeout(Memcached*);
    ~PollTimeout();
};

#define WATCHPOINT_ASSERT(expr) assert(expr)
#define WATCHPOINT_ERROR(rc)

bool memcached_is_purging(Memcached*);
uint32_t memcached_server_response_count(memcached_instance_st*);
bool memcached_io_write(memcached_instance_st*);
void memcached_io_reset(memcached_instance_st*);
void memcached_set_error(memcached_instance_st, int, int);
memcached_result_st* memcached_result_create(Memcached*, memcached_result_st*);
void memcached_result_reset(memcached_result_st*);
memcached_return_t memcached_read_one_response(memcached_instance_st*, memcached_result_st*);
void memcached_result_free(memcached_result_st*);
bool memcached_success(memcached_return_t);
bool memcached_fatal(memcached_return_t);