#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct _XDisplay Display;
typedef void* XLCd;
typedef unsigned long Font;

struct _XFontStruct {
    Font fid;
    void* per_char;
    void* ext_data;
    void* properties;
};

typedef struct _XFontStruct XFontStruct;

#define XLC_PUBLIC(lcd, field) ((const char*)0)
#define _Xconst const

int _XlcNCompareISOLatin1(const char *s1, const char *s2, int n);
XLCd _XlcCurrentLC(void);
XFontStruct *XLoadQueryFont(Display *display, const char *name);
void XFreeFont(Display *display, XFontStruct *font_struct);
void _XFreeExtData(void *ext_data);
void Xfree(void *ptr);