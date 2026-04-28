#include <stddef.h>

typedef struct CF2_Outline_* CF2_Outline;
typedef struct CF2_CallbackParams_* CF2_CallbackParams;
typedef struct CF2_OutlineCallbacks_* CF2_OutlineCallbacks;
typedef int FT_Error;

enum {
    CF2_PathOpLineTo
};

struct CFF_Builder {
    int path_begun;
};

struct CF2_Decoder {
    struct CFF_Builder builder;
};

struct CF2_Outline_ {
    struct CF2_Decoder* decoder;
};

struct CF2_CallbackParams_ {
    int op;
    struct {
        int x;
        int y;
    } pt0, pt1;
};

struct CF2_OutlineCallbacks_ {
    FT_Error* error;
};

typedef struct CFF_Builder CFF_Builder;

extern FT_Error cff_builder_start_point(CFF_Builder* builder, int x, int y);
extern FT_Error cff_builder_add_point1(CFF_Builder* builder, int x, int y);

#define FT_ASSERT(cond) ((void)0)