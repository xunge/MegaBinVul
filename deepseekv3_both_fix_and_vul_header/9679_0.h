#include <stdint.h>

typedef int32_t FT_F26Dot6;
typedef uint16_t FT_UShort;
typedef uint32_t FT_ULong;
typedef uint32_t FT_UInt32;

typedef struct {
    FT_F26Dot6 x;
    FT_F26Dot6 y;
} FT_Vector;

typedef struct {
    FT_Vector* org;
    FT_Vector* cur;
    uint16_t n_points;
} GlyphZone;

typedef struct {
    FT_F26Dot6 single_width_value;
    FT_F26Dot6 single_width_cutin;
    FT_F26Dot6 control_value_cutin;
    FT_F26Dot6 minimum_distance;
    FT_Vector freeVector;
    uint8_t gep0;
    uint8_t gep1;
    uint8_t auto_flip;
    uint16_t rp0;
    uint16_t rp1;
    uint16_t rp2;
} GraphicsState;

typedef struct {
    FT_F26Dot6 compensations[4];
} TT_Metrics;

typedef struct {
    GlyphZone zp0;
    GlyphZone zp1;
    GraphicsState GS;
    TT_Metrics tt_metrics;
    FT_F26Dot6* cvt;
    uint32_t cvtSize;
    uint8_t pedantic_hinting;
    int error;
    uint8_t opcode;
} T1_ExecContext;

#define BOUNDS(a, b) ((a) >= (b))
#define CUR (*(T1_ExecContext*)exec)
#define INS_ARG void* exec, FT_F26Dot6* args
#define TT_Err_Invalid_Reference 1
#define ROUND_None(a, b) (a)
#define FT_ABS(x) ((x) < 0 ? -(x) : (x))