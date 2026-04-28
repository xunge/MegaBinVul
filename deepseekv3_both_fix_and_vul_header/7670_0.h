#include <stdio.h>
#include <string.h>

typedef struct {
    float x;
    float y;
    float z;
} stl_vertex;

typedef struct {
    stl_vertex vertex[3];
} stl_facet;

typedef struct {
    int neighbor[3];
    int which_vertex_not[3];
} stl_neighbors;

typedef struct {
    stl_facet *facet_start;
    stl_neighbors *neighbors_start;
    int error;
} stl_file;

void stl_remove_facet(stl_file *stl, int facet);
void stl_update_connects_remove_1(stl_file *stl, int facet);