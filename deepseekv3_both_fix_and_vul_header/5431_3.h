#include <stddef.h>

typedef short Short;
typedef long Long;
typedef unsigned long ULong;
typedef unsigned char Byte;
typedef unsigned char* PByte;

typedef struct {
    Long rows;
    Long pitch;
} Target;

typedef struct {
    Target target;
    PByte bTarget;
    Long precision;
} RAS_ARGS;

typedef void* PProfile;
typedef long FT_F26Dot6;
#define FT_UNUSED(x) (void)(x)
#define CEILING(x) (((x) + 63) & -64)
#define FLOOR(x) ((x) & -64)
#define TRUNC(x) ((x) >> 6)

#define RAS_ARGS RAS_ARGS ras,