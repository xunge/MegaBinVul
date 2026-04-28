#include <string.h>

struct mqtt_conn {
    unsigned char *buf;
    size_t buf_pos;
    size_t buf_len;
    size_t buf_frame_end;
};