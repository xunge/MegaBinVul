#include <stdint.h>

struct st_h2o_http3_server_stream_t;

typedef struct {
    int type;
} h2o_http3_read_frame_t;

#define H2O_HTTP3_STREAM_TYPE_REQUEST 0
#define H2O_HTTP3_FRAME_TYPE_HEADERS 1
#define H2O_HTTP3_FRAME_TYPE_DATA 2
#define H2O_HTTP3_ERROR_FRAME_UNEXPECTED -1

int h2o_http3_read_frame(h2o_http3_read_frame_t *frame, int flags, int stream_type, const uint8_t **src, const uint8_t *src_end, const char **err_desc);