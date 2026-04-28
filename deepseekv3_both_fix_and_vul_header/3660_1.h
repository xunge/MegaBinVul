#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct FepClient {
    int control;
    bool filter_running;
    void *messages;
} FepClient;

enum {
    FEP_LOG_LEVEL_WARNING
};

static void *xzalloc(size_t size) {
    void *ptr = calloc(1, size);
    return ptr;
}

static void fep_log(int level, const char *format, ...) {
    // Implementation not provided
}