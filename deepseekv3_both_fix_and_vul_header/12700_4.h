#include <limits.h>
#include <string.h>

#define _Xconst const
typedef unsigned long Font;
typedef unsigned short CARD16;
typedef struct _Display Display;
typedef struct XFontStruct XFontStruct;

typedef struct {
    CARD16 nbytes;
    Font fid;
    unsigned int length;
} xOpenFontReq;

#define OpenFont 1

Font _XF86LoadQueryLocaleFont(Display*, const char*, XFontStruct**, Font*);
void LockDisplay(Display*);
void GetReq(int, void*);
Font XAllocID(Display*);
void Data(Display*, const char*, long);
void UnlockDisplay(Display*);
void SyncHandle(void);