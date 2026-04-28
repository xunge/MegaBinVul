#include <stdbool.h>
#include <stddef.h>

#define gs_error_ioerror (-1)

typedef struct gx_device_s gx_device;
typedef struct gs_param_list_s gs_param_list;
typedef struct gx_device_ijs_s gx_device_ijs;
typedef struct gs_memory_s gs_memory;
typedef struct gs_lib_ctx_s gs_lib_ctx;
typedef struct gs_lib_ctx_core_s gs_lib_ctx_core;

struct gs_lib_ctx_core_s {
    bool path_control_active;
};

struct gs_lib_ctx_s {
    gs_lib_ctx_core *core;
};

struct gs_memory_s {
    gs_lib_ctx *gs_lib_ctx;
};

struct gx_device_ijs_s {
    int Duplex_set;
    int Duplex;
    char IjsServer[256];
    char *DeviceManufacturer;
    size_t DeviceManufacturer_size;
    char *DeviceModel;
    size_t DeviceModel_size;
    char *IjsParams;
    size_t IjsParams_size;
    int BitsPerSample;
    bool IjsUseOutputFD;
    char *ColorSpace;
    size_t ColorSpace_size;
    bool IjsTumble;
    bool IjsTumble_set;
    gs_memory *memory;
    bool LockSafetyParams;
};

struct gx_device_s {
    bool is_open;
    bool LockSafetyParams;
};

extern int gsijs_read_string(gs_param_list *plist, const char *key, char *value, size_t size, bool path_control_active, bool is_open);
extern int gsijs_read_string_malloc(gs_param_list *plist, const char *key, char **value, size_t *size, bool is_open);
extern int gsijs_read_int(gs_param_list *plist, const char *key, int *value, int min, int max, bool is_open);
extern int gsijs_read_bool(gs_param_list *plist, const char *key, bool *value, bool is_open);
extern int gsijs_set_color_format(gx_device_ijs *ijsdev);
extern int gdev_prn_put_params(gx_device *dev, gs_param_list *plist);
extern int gsijs_set_generic_params(gx_device_ijs *ijsdev);
extern int gsijs_set_margin_params(gx_device_ijs *ijsdev);
extern int gs_note_error(int code);