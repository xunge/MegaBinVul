#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

typedef struct jp2_box jp2_box_t;
typedef struct jp2_boxinfo jp2_boxinfo_t;

struct jp2_box {
    uint32_t type;
    uint32_t len;
    struct {
        void (*dumpdata)(jp2_box_t *box, FILE *out);
    } *ops;
};

struct jp2_boxinfo {
    const char *name;
};

jp2_boxinfo_t *jp2_boxinfolookup(uint32_t type);