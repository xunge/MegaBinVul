#include <stdio.h>

struct subprocess_info {
    void *data;
    int retval;
};

struct umd_info {
    FILE *pipe_to_umh;
    FILE *pipe_from_umh;
    int *tgid;
};