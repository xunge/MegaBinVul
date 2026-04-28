#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

typedef unsigned long long ut64;
typedef unsigned int ut32;
typedef unsigned short ut16;
typedef unsigned char ut8;

typedef void (*RListFree)(void *);
typedef struct RList {
    void *head;
    void *tail;
    int length;
    RListFree free;
} RList;

typedef struct HtPU {
    void *table;
} HtPU;

typedef struct RBinFile RBinFile;

typedef struct RDyldBinImage {
    ut64 header_at;
    ut64 hdr_offset;
    ut64 symbols_off;
    ut64 va;
    char *file;
} RDyldBinImage;

typedef struct cache_hdr_t {
    ut32 imagesCount;
    ut32 mappingCount;
    void *maps;
} cache_hdr_t;

typedef struct cache_img_t {
    ut64 address;
    ut64 pathFileOffset;
} cache_img_t;

typedef struct cache_imgxtr_t {
    ut32 dependentsStartArrayIndex;
} cache_imgxtr_t;

typedef struct cache_accel_t {
    ut32 depListCount;
    ut64 depListOffset;
} cache_accel_t;

typedef struct RDyldCache {
    void *buf;
    cache_hdr_t *hdr;
    ut64 *hdr_offset;
    ut32 *maps_index;
    ut32 n_hdr;
    ut32 n_maps;
    void *maps;
    cache_accel_t *accel;
} RDyldCache;

#define MH_MAGIC_64 0xfeedfacf
#define UT64_MAX UINT64_MAX
#define R_NEWS0(x, y) calloc(y, sizeof(x))
#define R_FREE(x) free(x)
#define R_NEW0(x) calloc(1, sizeof(x))

static RList *r_list_newf(RListFree free) {
    RList *list = R_NEW0(RList);
    if (list) {
        list->free = free;
    }
    return list;
}

static void r_list_free(RList *list) {
    if (!list) return;
    void *iter = list->head;
    while (iter) {
        void *next = *(void **)iter;
        if (list->free) {
            list->free(iter);
        }
        iter = next;
    }
    free(list);
}

static int r_list_append(RList *list, void *data) {
    if (!list) return 0;
    void **tail = &list->tail;
    void **new_node = R_NEW0(void *);
    if (!new_node) return 0;
    *new_node = data;
    if (list->tail) {
        *(void **)list->tail = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
    list->length++;
    return 1;
}

static int r_list_empty(RList *list) {
    return !list || !list->head;
}

static void *r_list_find(RList *list, const void *data, bool (*cmp)(const void *, const void *)) {
    if (!list || !cmp) return NULL;
    void *iter = list->head;
    while (iter) {
        if (cmp(*(void **)iter, data)) {
            return *(void **)iter;
        }
        iter = *(void **)iter;
    }
    return NULL;
}

static char *r_sys_getenv(const char *var) {
    return getenv(var);
}

static RList *r_str_split_list(const char *str, const char *delim, int limit) {
    RList *list = r_list_newf(free);
    if (!str || !delim || !list) return NULL;
    
    char *copy = strdup(str);
    char *token = strtok(copy, delim);
    while (token) {
        r_list_append(list, strdup(token));
        token = strtok(NULL, delim);
    }
    free(copy);
    return list;
}

static int r_buf_fread_at(void *buf, ut64 addr, ut8 *data, const char *fmt, int count) {
    memcpy(data, (ut8 *)buf + addr, count);
    return count;
}

static int r_buf_read_at(void *buf, ut64 addr, ut8 *data, int len) {
    memcpy(data, (ut8 *)buf + addr, len);
    return len;
}

static ut32 r_read_le32(const ut8 *buf) {
    return buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
}

static void eprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

static void ht_pu_free(HtPU *ht) {
    if (ht) {
        free(ht->table);
        free(ht);
    }
}

static void free_bin(void *bin) {
    RDyldBinImage *b = bin;
    if (b) {
        free(b->file);
        free(b);
    }
}

static bool string_contains(const char *a, const char *b) {
    return strstr(a, b) != NULL;
}