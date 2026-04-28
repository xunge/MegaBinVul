#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct rw {
    char *name;
};

struct command;

typedef struct {
    int (*callback)(void *, int *);
    void *user_data;
} nbd_completion_callback;