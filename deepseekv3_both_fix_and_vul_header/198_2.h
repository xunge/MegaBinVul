#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct edid {
    // minimal stub definition
};

struct drm_connector {
    const char *name;
};

#define GFP_KERNEL 0
#define ERR_PTR(err) ((void *)(long)(err))
#define ENOENT 2
#define ENOMEM 12

extern char edid_firmware[];

static inline char *kstrdup(const char *s, int gfp) {
    return strdup(s);
}

static inline void kfree(void *p) {
    free(p);
}

static inline struct edid *edid_load(struct drm_connector *connector, 
                                   const char *name, 
                                   const char *connector_name) {
    return NULL;
}