#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int fixed;

struct gs_fixed_point {
    fixed x, y;
};

struct gs_fixed_rect {
    struct gs_fixed_point p, q;
};

struct segment {
    int type;
    struct gs_fixed_point pt;
    struct segment *next;
};

struct curve_segment {
    int type;
    struct gs_fixed_point pt;
    struct segment *next;
    struct gs_fixed_point p1, p2;
};

struct subpath {
    struct segment *first_subpath;
};

struct gx_path {
    struct subpath *first_subpath;
};

struct gx_device {
    void *memory;
};

typedef struct gx_device gx_device;
typedef struct gx_path gx_path;
typedef struct gs_fixed_rect gs_fixed_rect;
typedef struct subpath subpath;
typedef struct segment segment;
typedef struct curve_segment curve_segment;

#define fixed2int(x) ((x) >> 16)
#define gs_alloc_bytes(mem, size, desc) malloc(size)
#define gs_free_object(mem, ptr, desc) free(ptr)
#define return_error(code) (code)

enum {
    s_start,
    s_dash,
    s_curve,
    s_gap,
    s_line,
    s_line_close
};

enum {
    gs_error_VMerror = -1
};

#ifdef DEBUG_SCAN_CONVERTER
extern int debugging_scan_converter;
extern int dlprintf(const char *format, ...);
extern int dlprintf1(const char *format, ...);
#endif