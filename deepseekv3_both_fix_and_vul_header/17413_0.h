#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct map_tile {
    int frames_left;
    int tile_index;
};

struct map_trigger {
    int x;
    int y;
};

struct map_zone {
    struct {
        int x1;
        int y1;
        int x2;
        int y2;
    } bounds;
};

struct map_layer {
    struct map_tile* tilemap;
    int width;
    int height;
    bool is_parallax;
};

struct map {
    struct map_layer* layers;
    int num_layers;
    void* tileset;
    int width;
    int height;
    void* zones;
    void* triggers;
};

extern struct map* s_map;

void* vector_get(void* vector, int index);
size_t vector_len(void* vector);
void vector_remove(void* vector, int index);
void tileset_get_size(void* tileset, int* width, int* height);
int tileset_get_delay(void* tileset, int index);