#include <stddef.h>
#include <stdint.h>

typedef struct gs_client_color_s gs_client_color;
typedef struct gs_gstate_s gs_gstate;
typedef struct gs_pattern2_instance_s gs_pattern2_instance_t;
typedef struct gs_color_space_s gs_color_space;
typedef struct gs_shading_s gs_shading_s;

typedef uint8_t uchar;

struct gs_client_color_s {
    void *pattern;
};

struct gs_shading_s {
    struct {
        gs_color_space *ColorSpace;
    } params;
};

struct gs_pattern2_instance_s {
    struct {
        struct {
            gs_shading_s *Shading;
        } templat;
        struct {
            struct {
                uchar color_map[256];
            } color_component_map;
            int overprint_mode;
            int overprint;
        } *saved;
    };
};

struct gs_color_space_s {
    struct {
        int (*set_overprint)(gs_color_space *, gs_gstate *);
    } *type;
};

struct gs_gstate_s {
    int overprint_mode;
    int overprint;
    struct {
        struct {
            uchar num_components;
        } color_info;
    } *device;
    struct {
        uchar color_map[256];
    } color_component_map;
};