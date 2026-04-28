#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct _XDisplay Display;
typedef struct _XExtData XExtData;

typedef struct {
    short lbearing;
    short rbearing;
    short width;
    short ascent;
    short descent;
    unsigned short attributes;
} XCharStruct;

typedef struct {
    unsigned long name;
    unsigned long card32;
} XFontProp;

typedef struct {
    unsigned long name;
    unsigned long card32;
} xFontProp;

typedef struct _XFontStruct {
    XExtData *ext_data;
    unsigned long fid;
    unsigned direction;
    unsigned min_char_or_byte2;
    unsigned max_char_or_byte2;
    unsigned min_byte1;
    unsigned max_byte1;
    int all_chars_exist;
    unsigned default_char;
    int n_properties;
    XFontProp *properties;
    XCharStruct min_bounds;
    XCharStruct max_bounds;
    XCharStruct *per_char;
    int ascent;
    int descent;
} XFontStruct;

typedef struct {
    unsigned char type;
    unsigned char pad1;
    unsigned short sequenceNumber;
    unsigned long length;
    unsigned long nReplies;
    unsigned long pad2;
    unsigned long pad3;
    unsigned long pad4;
    unsigned long pad5;
    unsigned long pad6;
} xGenericReply;

typedef struct {
    xGenericReply hdr;
    unsigned short nameLength;
    unsigned short nFontProps;
    short fontAscent;
    short fontDescent;
    unsigned long minCharOrByte2;
    unsigned long maxCharOrByte2;
    unsigned long defaultChar;
    unsigned long drawDirection;
    unsigned long minByte1;
    unsigned long maxByte1;
    int allCharsExist;
    XCharStruct minBounds;
    XCharStruct maxBounds;
    unsigned long length;
    unsigned long nReplies;
} xListFontsWithInfoReply;

typedef struct {
    unsigned char reqType;
    unsigned char pad;
    unsigned short length;
    unsigned short maxNames;
    unsigned short nbytes;
    unsigned short pad1;
    unsigned long pad2;
} xListFontsReq;

#define None 0L
#define xFalse 0
#define xTrue 1
#define SIZEOF(x) sizeof(x)
#define _Xconst const
#define CARD8 unsigned char
#define CARD16 unsigned short
#define CARD32 unsigned long
#define INT16 short
#define INT32 long

#define LockDisplay(dpy) 
#define UnlockDisplay(dpy) 
#define SyncHandle() 
#define GetReq(name, req) 
#define _XSend(dpy, data, len) 
#define _XReply(dpy, reply, len, discard) 0
#define _XEatDataWords(dpy, len) 
#define _XRead32(dpy, buf, len) 
#define _XReadPad(dpy, buf, len) 
#define Xmalloc(size) malloc(size)
#define Xfree(ptr) free(ptr)
#define Xreallocarray(ptr, nmemb, size) realloc(ptr, (nmemb)*(size))
#define Xmallocarray(nmemb, size) malloc((nmemb)*(size))

static int cvtINT16toInt(short val) { return val; }