#include <stdint.h>

typedef unsigned long Atom;
typedef int Bool;
#define TRUE 1

typedef struct {
    unsigned char *requestBuffer;
    int errorValue;
} _ClientRec;
typedef _ClientRec *ClientPtr;

typedef struct {
    Atom property;
    Atom type;
    unsigned char format;
    unsigned char mode;
    unsigned long nUnits;
    unsigned long output;
} xRRChangeOutputPropertyReq;

typedef struct {
    // minimal definition needed for size calculation
} xChangePropertyReq;

typedef struct _RROutputRec *RROutputPtr;

#define REQUEST(x) x *stuff = (x *)client->requestBuffer
#define REQUEST_AT_LEAST_SIZE(x)
#define REQUEST_FIXED_SIZE(x, y)
#define VERIFY_RR_OUTPUT(a, b, c)
#define DixReadAccess 0
#define BadValue 2
#define BadLength 16
#define BadAtom 5
#define Success 0
#define PropModeReplace 0
#define PropModeAppend 1
#define PropModePrepend 2

extern void UpdateCurrentTime();
extern int RRChangeOutputProperty(RROutputPtr output, Atom property, Atom type, int format, int mode, unsigned long len, void *value, Bool s1, Bool s2);
extern Bool ValidAtom(Atom atom);
extern int bytes_to_int32(unsigned long val);