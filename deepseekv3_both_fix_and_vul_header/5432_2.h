#include <stddef.h>

typedef long  Long;
typedef int   Int;
typedef short Short;
typedef unsigned long  ULong;
typedef unsigned char  Byte;
typedef unsigned char* PByte;
typedef long  FT_F26Dot6;

#define CEILING(x)  (((x) + 63) & -64)
#define FLOOR(x)    ((x) & -64)
#define TRUNC(x)    ((x) >> 6)

typedef struct Profile_*  PProfile;
typedef struct Profile_ {
    Short       start;
    Short       height;
    PProfile    next;
    Byte        flags;
} Profile;

typedef struct {
    PByte  bTarget;
    struct {
        Int    rows;
        Int    pitch;
    } target;
    Int    precision;
    Int    precision_half;
} RAS_ARGS;

#define Overshoot_Top    0x10
#define Overshoot_Bottom 0x20

extern RAS_ARGS ras;

#define RAS_ARGS /* empty */