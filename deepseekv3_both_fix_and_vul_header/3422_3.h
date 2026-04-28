#include <stdlib.h>
#include <string.h>

struct stop {
    float offset;
    int index;
    float r;
    float g;
    float b;
    float a;
};

typedef struct xps_document {
    void *ctx;
} xps_document;

typedef struct fz_xml {
    const char *(*tag)(struct fz_xml *);
    const char *(*att)(struct fz_xml *, const char *);
    struct fz_xml *(*next)(struct fz_xml *);
} fz_xml;

typedef struct fz_colorspace fz_colorspace;

#define FZ_MAX_COLORS 32

static int cmp_stop(const void *a, const void *b) {
    const struct stop *sa = a;
    const struct stop *sb = b;
    return sa->offset < sb->offset ? -1 : sa->offset > sb->offset;
}

static float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

static float fz_atof(const char *s) {
    return atof(s);
}

static void *fz_device_rgb(void *ctx) {
    return NULL;
}

static void fz_convert_color(void *ctx, void *dev, float *dest, void *src, float *src_color) {
    for (int i = 0; i < 3; i++) dest[i] = src_color[i];
}

static void fz_warn(void *ctx, const char *msg) {
}

static const char *fz_xml_tag(fz_xml *node) {
    return node ? node->tag(node) : NULL;
}

static const char *fz_xml_att(fz_xml *node, const char *att) {
    return node ? node->att(node, att) : NULL;
}

static fz_xml *fz_xml_next(fz_xml *node) {
    return node ? node->next(node) : NULL;
}