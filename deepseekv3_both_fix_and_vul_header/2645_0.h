#include <stdlib.h>

typedef struct Image Image;
typedef struct sixel_output_t sixel_output_t;
typedef struct sixel_node_t sixel_node_t;

struct sixel_output_t {
    int has_8bit_control;
    int save_pixel;
    int save_count;
    int active_palette;
    sixel_node_t *node_top;
    sixel_node_t *node_free;
    Image *image;
    size_t pos;
};

#define SIXEL_OUTPUT_PACKET_SIZE 1024
#define AcquireQuantumMemory(size, count) calloc(count, size)