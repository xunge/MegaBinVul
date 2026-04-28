#include <stdlib.h>
#include <stdio.h>

typedef struct stl_file {
    int error;
    struct {
        int number_of_facets;
        int number_of_parts;
    } stats;
    struct {
        int neighbor[3];
        int which_vertex_not[3];
    } *neighbors_start;
} stl_file;

int stl_check_normal_vector(stl_file *stl, int facet_num, int dummy);
void stl_reverse_facet(stl_file *stl, int facet_num);