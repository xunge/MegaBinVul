#include <stdint.h>
#include <assert.h>

#define g_assert assert

typedef struct _GVariant GVariant;
typedef struct _GVariantTypeInfo GVariantTypeInfo;
typedef void* gpointer;
typedef unsigned long gsize;

typedef struct {
    GVariantTypeInfo *type_info;
    gsize size;
    gpointer data;
    gsize depth;
    unsigned int ordered_offsets_up_to;
} GVariantSerialised;

struct _GVariant {
    GVariantTypeInfo *type_info;
    gsize size;
    gsize depth;
    unsigned int state;
    union {
        struct {
            gpointer *children;
            gsize n_children;
        } tree;
    } contents;
};

enum {
    STATE_SERIALISED = 1 << 0,
    STATE_LOCKED = 1 << 1
};

void g_variant_serialiser_serialise(GVariantSerialised serialised,
                                   void (*g_variant_fill_gvs)(void),
                                   gpointer *children,
                                   gsize n_children);

void g_variant_fill_gvs(void);