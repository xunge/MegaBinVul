#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct libxl__gc libxl__gc;

typedef struct {
    uint8_t bytes[16];
} libxl_uuid;

typedef struct {
    uint32_t mtu;
    char *model;
    uint8_t mac[6];
    char *bridge;
    char *script;
    char *backend_domname;
    uint32_t backend_domid;
    int nictype;
    bool trusted;
} libxl_device_nic;

#define LIBXL_DEVICE_NIC_MTU_DEFAULT 1500
#define ERROR_NOMEM (-1)
#define ERROR_FAIL (-2)
#define ERROR_INVAL (-3)

enum libxl_domain_type {
    LIBXL_DOMAIN_TYPE_INVALID,
    LIBXL_DOMAIN_TYPE_HVM,
    LIBXL_DOMAIN_TYPE_PVH,
    LIBXL_DOMAIN_TYPE_PV
};

enum libxl_nic_type {
    LIBXL_NIC_TYPE_VIF,
    LIBXL_NIC_TYPE_VIF_IOEMU
};

#define LOGD(level, domid, fmt, ...) 

static int libxl__mac_is_default(const uint8_t *mac);
static void libxl_uuid_generate(libxl_uuid *uuid);
static const uint8_t *libxl_uuid_bytearray(const libxl_uuid *uuid);
static char *libxl__xen_script_dir_path(void);
static int libxl__resolve_domid(libxl__gc *gc, const char *name, uint32_t *domid);
static enum libxl_domain_type libxl__domain_type(libxl__gc *gc, uint32_t domid);
static void libxl_defbool_setdefault(bool *b, bool def);