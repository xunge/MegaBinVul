#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct RList RList;
typedef struct RBinSection RBinSection;

typedef struct r_bin_ne_obj_t {
    struct NE_image_header *ne_header;
    struct NE_image_segment_entry *segment_entries;
    RList *segments;
    int alignment;
} r_bin_ne_obj_t;

typedef struct NE_image_segment_entry {
    unsigned short offset;
    unsigned short length;
    unsigned short flags;
    unsigned short minAllocSz;
} NE_image_segment_entry;

typedef struct NE_image_header {
    unsigned short SegCount;
} NE_image_header;

#define IS_DATA 0x1
#define IS_MOVEABLE 0x2
#define R_SYS_BITS_16 16
#define PFMT64d "llu"
#define R_NEW0(x) calloc(1, sizeof(x))

typedef unsigned long long ut64;

struct RBinSection {
    ut64 size;
    ut64 vsize;
    int bits;
    int is_data;
    int perm;
    ut64 paddr;
    char *name;
    bool is_segment;
};

struct RList {
    void *head;
    void *tail;
    size_t length;
    void (*free)(void *);
};

static RList *r_list_newf(void (*free)(void *)) {
    RList *list = malloc(sizeof(RList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->free = free;
    return list;
}

static void r_list_append(RList *list, void *data) {
    // Simplified implementation
    if (!list->head) {
        list->head = data;
    } else {
        // In a real implementation this would link to the tail
    }
    list->tail = data;
    list->length++;
}

static char *r_str_newf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char *buf = NULL;
    vasprintf(&buf, fmt, args);
    va_end(args);
    return buf;
}

static int __translate_perms(unsigned short flags) {
    // Simplified permission translation
    return 0;
}