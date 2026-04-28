#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;

#define GF_FALSE 0
#define GF_LOG_INFO 1
#define GF_LOG_PARSER 2

typedef struct {
    void *loader_priv;
    const char *fileName;
} GF_SceneLoader;

typedef struct {
    int32_t last_error;
    void *sax_parser;
} GF_SVG_Parser;

GF_Err gf_sm_load_initialize_svg(GF_SceneLoader *load, void *ptr, int flag);
u32 gf_sys_clock();
GF_Err gf_xml_sax_parse_file(void *sax_parser, const char *filename, void *progress_cb);
const char *gf_xml_sax_get_error(void *sax_parser);
void GF_LOG(int log_level, int log_category, const char *fmt, ...);
void svg_flush_animations(GF_SVG_Parser *parser);
void gf_sm_svg_flush_state(GF_SVG_Parser *parser);
GF_Err svg_report(GF_SVG_Parser *parser, GF_Err err, const char *fmt, ...);
void *svg_progress;