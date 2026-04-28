#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

typedef struct {
    unsigned short id;
    unsigned short size;
} BOF;

typedef struct {
    unsigned short xWn;
    unsigned short yWn;
    unsigned short dxWn;
    unsigned short dyWn;
    unsigned short grbit;
    unsigned short itabCur;
    unsigned short itabFirst;
    unsigned short ctabSel;
    unsigned short wTabRatio;
} WIND1;

typedef struct {
    unsigned short height;
    unsigned short flag;
    unsigned short color;
    unsigned short bold;
    unsigned short escapement;
    unsigned short underline;
    unsigned short family;
    unsigned short charset;
} FONT;

typedef struct {
    unsigned short font;
    unsigned short format;
    unsigned short type;
    unsigned short align;
    unsigned short color;
    unsigned short fill;
    unsigned short border;
    unsigned short linestyle;
} XF5;

typedef struct {
    unsigned short font;
    unsigned short format;
    unsigned short type;
    unsigned short align;
    unsigned short rotation;
    unsigned short ident;
    unsigned short usedattrib;
    unsigned short linestyle;
    unsigned short linecolor;
    unsigned short groundcolor;
} XF8;

typedef struct {
    unsigned short count;
    unsigned short unique;
    char* strings;
} SST;

typedef struct {
    unsigned short pos;
    unsigned short type;
    unsigned short visible;
    char* name;
} BOUNDSHEET;

typedef struct {
    unsigned short index;
    char* format;
} FORMAT;

typedef struct OLE2Stream {
    unsigned long start;
    unsigned long pos;
    unsigned long size;
    unsigned long fatpos;
    int eof;
} OLE2Stream;

typedef struct xlsWorkBook {
    OLE2Stream* olestr;
    long filepos;
    int is5ver;
    unsigned short type;
    unsigned short codepage;
    unsigned short activeSheetIdx;
    int is1904;
} xlsWorkBook;

typedef enum {
    LIBXLS_ERROR_NULL_ARGUMENT,
    LIBXLS_OK,
    LIBXLS_ERROR_READ,
    LIBXLS_ERROR_MALLOC,
    LIBXLS_ERROR_PARSE,
    LIBXLS_ERROR_UNSUPPORTED_ENCRYPTION
} xls_error_t;

enum {
    XLS_RECORD_EOF = 0x0A,
    XLS_RECORD_SST = 0xFC,
    XLS_RECORD_BOF = 0x809,
    XLS_RECORD_CODEPAGE = 0x42,
    XLS_RECORD_CONTINUE = 0x3C,
    XLS_RECORD_WINDOW1 = 0x3D,
    XLS_RECORD_EXTSST = 0xFF,
    XLS_RECORD_BOUNDSHEET = 0x85,
    XLS_RECORD_XF = 0xE0,
    XLS_RECORD_FONT = 0x31,
    XLS_RECORD_FONT_ALT = 0x41,
    XLS_RECORD_FORMAT = 0x1E,
    XLS_RECORD_STYLE = 0x293,
    XLS_RECORD_PALETTE = 0x92,
    XLS_RECORD_1904 = 0x22,
    XLS_RECORD_FILEPASS = 0x2F,
    XLS_RECORD_DEFINEDNAME = 0x18
};

extern int xls_debug;