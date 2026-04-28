#include <stdint.h>
#include <stdbool.h>

#define PropModeReplace 0
#define PropModeAppend 1
#define PropModePrepend 2

#define BadValue 2
#define BadLength 16
#define BadAtom 5
#define Success 0
#define DixReadAccess 0
#define TRUE true
#define FALSE false

typedef struct _Client {
    int errorValue;
} ClientRec, *ClientPtr;

typedef struct _RRProvider {
    // dummy structure
} RRProviderRec, *RRProviderPtr;

typedef struct {
    unsigned char format;
    unsigned char mode;
    unsigned long nUnits;
    unsigned int provider;
    unsigned int property;
    unsigned int type;
} xRRChangeProviderPropertyReq;

typedef struct {
    // dummy structure
} xChangePropertyReq;

#define REQUEST(x) x *stuff = (x *)client
#define REQUEST_AT_LEAST_SIZE(x)
#define REQUEST_FIXED_SIZE(x, y)
#define VERIFY_RR_PROVIDER(id, ptr, access)
#define ValidAtom(x) 1

void UpdateCurrentTime();
int RRChangeProviderProperty(RRProviderPtr provider, unsigned int property, 
                           unsigned int type, int format, int mode, 
                           unsigned long len, void *data, bool b1, bool b2);
int bytes_to_int32(unsigned long x);