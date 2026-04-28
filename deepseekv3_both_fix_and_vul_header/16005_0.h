#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t size;
    size_t len;
} linebuffer;

typedef struct {
    char *buffer;
    size_t size;
    size_t len;
} filebuffer_t;

extern filebuffer_t filebuf;
extern bool need_filebuf;

void *mempcpy(void *dest, const void *src, size_t n);
void xrnew(void *ptr, size_t old_size, size_t factor);