#include <stdint.h>

typedef int32_t XFixed;

struct _ScreenRec {
    int myNum;
};

struct _DrawableRec {
    struct _ScreenRec *pScreen;
};

struct _PictureRec {
    struct _DrawableRec *pDrawable;
};

struct _dmxPictPrivRec {
    void *pict;
};

struct _ClientRec {
    int req_len;
};

struct _DMXScreenInfo {
    void *beDisplay;
};

struct xRenderSetPictureFilterReq {
    int picture;
    int nbytes;
    int renderReqType;
};

typedef struct _ClientRec *ClientPtr;
typedef struct _DMXScreenInfo DMXScreenInfo;
typedef struct _PictureRec *PicturePtr;
typedef struct _dmxPictPrivRec *dmxPictPrivPtr;

extern DMXScreenInfo *dmxScreens;
extern int (*dmxSaveRenderVector[])(ClientPtr);
extern struct xRenderSetPictureFilterReq *stuff;

#define REQUEST(x) 
#define REQUEST_AT_LEAST_SIZE(x) 
#define VERIFY_PICTURE(p, id, c, a) 
#define DixWriteAccess 0
#define BadLength 0
#define DMX_GET_PICT_PRIV(p) ((dmxPictPrivPtr)(p))
#define FALSE 0

int XRenderSetPictureFilter(void *display, void *pict, char *filter, XFixed *params, int nparams);
int dmxSync(DMXScreenInfo *screen, int flag);