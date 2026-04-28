#include <limits.h>
#include <string.h>

typedef unsigned long CARD16;
typedef unsigned long Font;
typedef struct _XDisplay {
    unsigned long request;
} Display;
typedef struct _XFontStruct XFontStruct;
typedef struct _xOpenFontReq {
    CARD16 nbytes;
    Font fid;
    unsigned long length;
} xOpenFontReq;
typedef struct _XF86BigfontCodes XF86BigfontCodes;

#define _Xconst const
#define OpenFont 1

int _XF86LoadQueryLocaleFont(Display*, const char*, XFontStruct**, Font*);
void LockDisplay(Display*);
void GetReq(int, xOpenFontReq*);
Font XAllocID(Display*);
void Data(Display*, const char*, long);
XFontStruct* _XQueryFont(Display*, Font, unsigned long);
void UnlockDisplay(Display*);
void SyncHandle();