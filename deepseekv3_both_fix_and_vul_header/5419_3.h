typedef int FT_Error;

typedef struct CF2_OutlineRec_* CF2_Outline;
typedef struct CF2_CallbackParamsRec_* CF2_CallbackParams;
typedef struct CF2_OutlineCallbacksRec_* CF2_OutlineCallbacks;
typedef struct CFF_Builder_ CFF_Builder;

struct CF2_CallbackParamsRec_ {
    int op;
    struct {
        int x;
        int y;
    } pt0, pt1, pt2, pt3;
};

struct CF2_OutlineCallbacksRec_ {
    FT_Error* error;
};

struct CFF_Builder_ {
    int path_begun;
};

struct CF2_OutlineRec_ {
    struct {
        CFF_Builder builder;
    }* decoder;
};

enum {
    CF2_PathOpCubeTo
};

#define FT_ASSERT(cond) ((void)0)

static FT_Error cff_builder_start_point(CFF_Builder* builder, int x, int y) { return 0; }
static FT_Error cff_check_points(CFF_Builder* builder, int n) { return 0; }
static void cff_builder_add_point(CFF_Builder* builder, int x, int y, int on_curve) {}