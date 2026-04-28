#include <stddef.h>

typedef struct gif_t {
    struct {
        int prefix;
        unsigned char suffix;
    } *codes;
    int cur_x;
    int cur_y;
    int max_x;
    int max_y;
    int start_x;
    int start_y;
    int step;
    int parse;
    size_t line_size;
    unsigned char *out;
    int actual_width;
    int actual_height;
} gif_t;