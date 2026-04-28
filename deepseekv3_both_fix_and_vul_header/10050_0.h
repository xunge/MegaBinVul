#include <stdlib.h>
#include <string.h>

typedef struct jp2_box_t jp2_box_t;
typedef struct jp2_boxinfo_t jp2_boxinfo_t;

struct jp2_box_t {
    int type;
    unsigned long len;
    jp2_boxinfo_t *info;
    void *ops;
};

struct jp2_boxinfo_t {
    void *ops;
};

void *jas_malloc(size_t size);
jp2_boxinfo_t *jp2_boxinfolookup(int type);