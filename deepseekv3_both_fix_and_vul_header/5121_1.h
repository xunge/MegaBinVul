#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef int GF_Err;

#define GF_EXPORT
#define GF_NOT_SUPPORTED 1
#define GF_BAD_PARAM 2
#define GF_LOG_ERROR 1
#define GF_LOG_SCENE 2
#define GF_SM_LOAD_FOR_PLAYBACK 1
#define GF_SM_LOAD_BT 1
#define GF_SM_LOAD_VRML 2
#define GF_SM_LOAD_X3DV 3
#define GF_SM_LOAD_XMTA 4
#define GF_SM_LOAD_X3D 5
#define GF_SM_LOAD_SWF 6
#define GF_SM_LOAD_QT 7
#define GF_SM_LOAD_SVG 8
#define GF_SM_LOAD_XSR 9
#define GF_SM_LOAD_XBL 10
#define GF_SM_LOAD_DIMS 11
#define GF_SM_LOAD_MP4 12

struct GF_SceneGraph;
struct GF_ISOFile;

typedef struct {
    struct GF_Context *ctx;
    struct GF_SceneGraph *scene_graph;
    char *fileName;
    struct GF_ISOFile *isom;
    int flags;
    int type;
    void (*process)(void*);
    void (*done)(void*);
} GF_SceneLoader;

typedef struct GF_Context {
    struct GF_SceneGraph *scene_graph;
} GF_Context;

void GF_LOG(int level, int category, const char *format, ...);
char *gf_xml_get_root_type(const char *filename, GF_Err *e);
void gf_free(void *ptr);
int stricmp(const char *s1, const char *s2);
char *strlwr(char *str);

GF_Err gf_sm_load_init_bt(GF_SceneLoader *load);
GF_Err gf_sm_load_init_xmt(GF_SceneLoader *load);
GF_Err gf_sm_load_init_svg(GF_SceneLoader *load);
GF_Err gf_sm_load_init_xbl(GF_SceneLoader *load);
GF_Err gf_sm_load_run_xbl(GF_SceneLoader *load);
GF_Err gf_sm_load_done_xbl(GF_SceneLoader *load);
GF_Err gf_sm_load_init_swf(GF_SceneLoader *load);
GF_Err gf_sm_load_init_isom(GF_SceneLoader *load);
GF_Err gf_sm_load_init_qt(GF_SceneLoader *load);