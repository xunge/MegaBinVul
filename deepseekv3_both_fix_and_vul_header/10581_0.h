#include <stdlib.h>
#include <string.h>

typedef struct {
    char *d_memory;
    char *d_memory_end;
    char *d_read;
    char *d_write;
} Queue;

#define BLOCK_QUEUE 1024

enum MSG_LEVEL {
    MSG_INFO
};

int message_show(enum MSG_LEVEL level);
void message(const char *format, ...);
void *new_memory(size_t size, size_t type_size);