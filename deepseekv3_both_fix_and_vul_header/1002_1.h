#include <stddef.h>
#include <stdint.h>

struct h2o_buffer_t {
    uint8_t *bytes;
    size_t size;
};

struct h2o_iovec_t {
    void *base;
    size_t len;
};

struct st_h2o_http3_server_stream_t {
    struct {
        size_t bytes_left_in_data_frame;
        int (*handle_input)(struct st_h2o_http3_server_stream_t *, const uint8_t **, const uint8_t *, const char **);
    } recvbuf;
    struct h2o_buffer_t *req_body;
    struct {
        struct h2o_iovec_t entity;
        size_t req_body_bytes_received;
    } req;
};

#define H2O_HTTP3_ERROR_INTERNAL (-1)

extern const void *h2o_socket_buffer_prototype;

void h2o_buffer_init(struct h2o_buffer_t **, const void *);
int h2o_buffer_try_append(struct h2o_buffer_t **, const void *, size_t);
struct h2o_iovec_t h2o_iovec_init(const void *, size_t);
int handle_input_expect_data(struct st_h2o_http3_server_stream_t *, const uint8_t **, const uint8_t *, const char **);