#include <stdint.h>
#include <stddef.h>
#include <limits.h>

#define H2O_HTTP3_STREAM_TYPE_REQUEST 0
#define H2O_HTTP3_FRAME_TYPE_HEADERS 1
#define H2O_HTTP3_FRAME_TYPE_DATA 2
#define H2O_HTTP3_ERROR_FRAME_UNEXPECTED 1
#define H2O_HTTP3_ERROR_EARLY_RESPONSE 2
#define H2O_HTTP3_ERROR_GENERAL_PROTOCOL 3

struct st_h2o_http3_server_stream_t {
    void *tunnel;
    struct {
        size_t content_length;
        size_t req_body_bytes_received;
    } req;
    struct {
        void (*handle_input)(void);
        size_t bytes_left_in_data_frame;
    } recvbuf;
};

typedef struct {
    uint8_t type;
    size_t length;
} h2o_http3_read_frame_t;

int h2o_http3_read_frame(h2o_http3_read_frame_t *frame, int a, int b, const uint8_t **src, const uint8_t *src_end, const char **err_desc);
void shutdown_stream(struct st_h2o_http3_server_stream_t *stream, int a, int b, int c);
void handle_input_post_trailers(void);
void handle_input_expect_data_payload(void);