#include <stddef.h>
#include <stdint.h>

typedef short             FT_Int;
typedef unsigned short    FT_UShort;
typedef signed long       FT_F26Dot6;
typedef int               TT_Error;
typedef int64_t           FT_Int64;

enum {
    TT_Err_Invalid_Reference = 1
};

typedef struct  FT_Vector_
{
  FT_F26Dot6  x;
  FT_F26Dot6  y;
} FT_Vector;

typedef struct  TT_GraphicsState_
{
  FT_UShort      rp0;
  FT_UShort      rp1;
  FT_UShort      rp2;
  FT_UShort      loop;
  FT_F26Dot6     minimum_distance;
  FT_UShort      round_state;
  FT_Int         phase;
  FT_Int         threshold;
  FT_F26Dot6     period;
  FT_Int         single_step_value;
  FT_Int         single_step_width;
  FT_Int         control_value_cutin;
  FT_F26Dot6     delta_base;
  FT_F26Dot6     delta_shift;
  FT_Int         instruct_control;
  FT_UShort      scan_control;
  FT_Int         scan_type;
  FT_UShort      gep0;
  FT_UShort      gep1;
  FT_UShort      gep2;
} TT_GraphicsState;

typedef struct  TT_Size_Metrics_
{
  FT_F26Dot6  x_scale;
  FT_F26Dot6  y_scale;
} TT_Size_Metrics;

typedef struct  TT_ExecContextRec_
{
  TT_GraphicsState  GS;
  TT_Size_Metrics   metrics;
  FT_UShort         opcode;
  FT_Int            pedantic_hinting;
  TT_Error          error;
  FT_F26Dot6        (*CUR_Func_project)(FT_Vector*, FT_Vector*);
  FT_F26Dot6        (*CUR_Func_dualproj)(FT_Vector*, FT_Vector*);
  FT_F26Dot6        (*CUR_fast_dualproj)(FT_Vector*);
  struct
  {
    FT_UShort   n_points;
    FT_Vector*  cur;
    FT_Vector*  orus;
  } zp0, zp1;
} TT_ExecContextRec, *TT_ExecContext;

#define CUR  (*exec)
#define BOUNDS(l, n)  ((FT_UShort)(l) >= (n))
#define TT_MULFIX(a, b)  ((FT_F26Dot6)(((FT_Int64)(a) * (b)) >> 6))
#define INS_ARG  TT_ExecContext  exec, FT_F26Dot6*  args