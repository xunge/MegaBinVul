#include <stddef.h>

typedef unsigned int guint;
typedef struct tvbuff_t tvbuff_t;

struct GList {
    void *data;
    struct GList *next;
    struct GList *prev;
};

struct tvb_composite {
    struct {
        struct GList *tvbs;
    } composite;
};

#define _U_ __attribute__((unused))

guint tvb_offset_from_real_beginning_counter(const tvbuff_t *tvb, const guint counter);