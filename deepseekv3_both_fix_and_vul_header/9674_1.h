#include <stdint.h>

typedef int32_t FT_Long;
typedef uint32_t FT_ULong;
typedef int FT_Error;
typedef int FT_Bool;

typedef struct {
    FT_Long* stack;
    FT_ULong args;
    FT_ULong new_top;
    FT_Error error;
    struct {
        FT_ULong delta_base;
        FT_ULong delta_shift;
    } GS;
    FT_Bool pedantic_hinting;
    FT_ULong cvtSize;
    struct {
        FT_Bool unpatented_hinting;
    } *face;
    FT_ULong opcode;
} TT_ExecContext;

#define CUR (*exec)
#define CURRENT_Ppem() (0)
#define CUR_Func_move_cvt(a, b) (void)(a), (void)(b)
#define BOUNDS(a, b) ((a) >= (b))
#define TT_Err_Too_Few_Arguments 1
#define TT_Err_Invalid_Reference 2

static TT_ExecContext* exec;
static FT_Long* args;