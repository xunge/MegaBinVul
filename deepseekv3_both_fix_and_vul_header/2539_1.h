#include <stdint.h>
#include <string.h>
#include <sys/types.h>

#define NFSX_V3FHMAX 64

typedef unsigned int u_int;
typedef unsigned char u_char;

typedef struct {
    int Major;
    int Minor;
} Fsid_dev;

typedef struct {
    Fsid_dev Fsid_dev;
    char Opaque_Handle[NFSX_V3FHMAX];
} my_fsid;

typedef struct netdissect_options {
    int ndo_uflag;
} netdissect_options;

#define ND_PRINT(args)