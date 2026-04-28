#include <stdlib.h>

typedef struct Error Error;
typedef struct V9fsState {
    struct {
        void (*cleanup)(void *);
    } *ops;
    char *tag;
    struct {
        char *fs_root;
    } ctx;
} V9fsState;

void g_free(void *ptr);