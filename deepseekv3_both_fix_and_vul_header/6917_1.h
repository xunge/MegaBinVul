#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

typedef int GF_Err;
#define GF_BAD_PARAM 1
#define GF_OK 0
#define GF_NOT_SUPPORTED 2
#define GF_EOS 3

#define SWF_FREECHARACTER 0
#define GPAC_ENABLE_COVERAGE
#define GPAC_DISABLE_VRML
#define GPAC_DISABLE_SVG
#define GF_MAX_PATH 256
#define GF_PATH_SEPARATOR '/'
#define GF_SM_SWF_SPLIT_TIMELINE 1
#define GF_SM_SWF_USE_SVG 2

#define FLT2FIX(x) ((int)((x)*65536.0))
#define FIX2INT(x) ((x)/65536)

typedef struct GF_SceneLoader {
    struct {
        int scene_width;
        int scene_height;
        int is_pixel_metrics;
    } *ctx;
    void *scene_graph;
    char *fileName;
    char *localPath;
    unsigned int swf_import_flags;
    float swf_flatten_limit;
    void *loader_priv;
    char *svgOutFile;
    void (*done)(struct GF_SceneLoader *);
    void (*process)(struct GF_SceneLoader *);
} GF_SceneLoader;

typedef struct SWFReader {
    GF_SceneLoader *load;
    unsigned int flags;
    int flat_limit;
    int width;
    int height;
    int no_as;
    FILE *svg_file;
    int current_frame;
} SWFReader;

SWFReader *gf_swf_reader_new(char *localPath, char *fileName);
GF_Err gf_swf_read_header(SWFReader *read);
void swf_report(SWFReader *read, GF_Err e, const char *msg);
GF_Err swf_parse_tag(SWFReader *read);
void gf_sm_load_done_swf(GF_SceneLoader *load);
void gf_sm_load_run_swf(GF_SceneLoader *load);
FILE *gf_fopen(const char *filename, const char *mode);
void gf_swf_reader_set_user_mode(SWFReader *read, FILE *file, void (*write_text_sample)(), void (*write_text_header)());
GF_Err swf_to_svg_init(SWFReader *read, unsigned int flags, float flatten_limit);
GF_Err swf_to_bifs_init(SWFReader *read);
int gf_sys_is_cov_mode();
void swf_func_skip(void *);
void swf_def_hdr_jpeg(void *);
void swf_get_tag_name(int);
void swf_unknown_tag(void *);
void swf_io_error(void *);
void swf_svg_write_text_sample();
void swf_svg_write_text_header();