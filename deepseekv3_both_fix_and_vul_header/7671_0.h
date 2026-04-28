#include <stdlib.h>

typedef struct {
    int neighbor[3];
} stl_neighbor;

typedef struct {
    int connected_facets_3_edge;
    int connected_facets_2_edge;
    int connected_facets_1_edge;
} stl_stats;

typedef struct {
    stl_neighbor *neighbors_start;
    stl_stats stats;
    int error;
} stl_file;