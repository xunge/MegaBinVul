#include <stdint.h>
#include <stdbool.h>

typedef struct libxl__gc libxl__gc;

typedef struct {
    bool val;
} libxl_defbool;

typedef struct {
    libxl_defbool discard_enable;
    libxl_defbool colo_enable;
    libxl_defbool colo_restore_enable;
    libxl_defbool trusted;
    bool readwrite;
    bool is_cdrom;
    const char *backend_domname;
    uint32_t backend_domid;
    int backend;
} libxl_device_disk;

static inline void libxl_defbool_setdefault(libxl_defbool *b, bool def) {
    b->val = def;
}

enum {
    LIBXL_DISK_BACKEND_QDISK,
    LIBXL_DISK_BACKEND_UNKNOWN
};

enum {
    LIBXL_DOMAIN_TYPE_HVM
};

#define ERROR_FAIL (-1)
#define LOGD(level, domid, msg)

static int libxl__resolve_domid(libxl__gc *gc, const char *name, uint32_t *domid);
static int libxl__domain_type(libxl__gc *gc, uint32_t domid);
static int libxl__device_disk_set_backend(libxl__gc *gc, libxl_device_disk *disk);