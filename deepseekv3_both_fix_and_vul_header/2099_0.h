#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FFABS(a) ((a) >= 0 ? (a) : -(a))

static float ff_vorbis_floor1_inverse_db_table[256];

static void render_line_unrolled(int x0, int y0, int x1, int sy, int ady, int adx, float *buf);