#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef unsigned short ushort;

struct term {
    int csi_argv[3];
    int csi_argc;
    int csi_argv_defined[3];
    int rows;
    int cols;
    int rows0;
    int cols0;
};

struct config {
    char *suppress_win;
};

static struct term term;
static struct config cfg;

static int cell_height;
static int cell_width;

#define when case