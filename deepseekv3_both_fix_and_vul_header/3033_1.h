#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define LINE_SZ 256
#define AV_CLASS_CATEGORY_NA 0

typedef struct AVClass {
    const char* (*item_name)(void*);
    int parent_log_context_offset;
} AVClass;

static int get_category(void *ptr) {
    return 0;
}