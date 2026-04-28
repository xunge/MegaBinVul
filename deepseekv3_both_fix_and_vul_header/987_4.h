#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef int Jsi_RC;
typedef double Jsi_Number;
typedef int64_t Jsi_Wide;

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;

#define JSI_OK 0
#define JSI_ERROR 1

#define Jsi_ValueIsNumber(interp, v) (0)
#define Jsi_GetNumberFromValue(interp, v, d) (0)
#define Jsi_ValueString(interp, v, NULL) (NULL)
#define Jsi_ValueToNumberInt3(interp, v, b) (0)
#define Jsi_ValueToNumberInt4(interp, v, b, d) (0)
#define Jsi_GetIntFromValue(interp, v, b) (0)
#define Jsi_NumberIsNaN(d) (isnan(d))
#define Jsi_NumberIsFinite(d) (isfinite(d))
#define Jsi_GetDoubleFromValue(interp, v, d) (0)
#define Jsi_ValueDup2(interp, ret, nan) (0)
#define Jsi_ValueMakeNumber(interp, ret, num) (0)
#define Jsi_ValueArrayIndex(interp, args, idx) (NULL)

struct Jsi_Interp {
    Jsi_Value *NaNValue;
};