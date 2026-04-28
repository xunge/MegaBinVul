#include <stdlib.h>
#include <math.h>

#define STB_VORBIS_DIVIDE_TABLE
#define DIVTAB_DENOM 256
#define DIVTAB_NUMER 256
#define LINE_OP(a,b) (a) = (b)
#define __forceinline inline

static int integer_divide_table[DIVTAB_NUMER][DIVTAB_DENOM];
static float inverse_db_table[256];