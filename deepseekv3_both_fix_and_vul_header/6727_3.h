#include <stdint.h>

typedef struct {
    int picture;
    int nbytes;
} xRenderSetPictureFilterReq;

typedef struct {
    xRenderSetPictureFilterReq *stuff;
    int req_len;
} *ClientPtr;

typedef int PicturePtr;
typedef int32_t xFixed;
typedef int DixSetAttrAccess;
#define BadLength (-1)

#define REQUEST(x) xRenderSetPictureFilterReq *stuff = ((ClientPtr)client)->stuff
#define REQUEST_AT_LEAST_SIZE(x)
#define VERIFY_PICTURE(a, b, c, d)
#define pad_to_int32(x) ((x + 3) & ~3)

int SetPictureFilter(PicturePtr pPicture, char *name, int nbytes, xFixed *params, int nparams);