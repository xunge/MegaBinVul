#include <stddef.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;

typedef struct xlsWorkBook {
    int is5ver;
} xlsWorkBook;

typedef struct BOF {
    int id;
    unsigned short size;
} BOF;

typedef struct WIND1 {
    // dummy structure for WIND1
} WIND1;

typedef struct SST {
    // dummy structure for SST
    char strings[1];
} SST;

typedef struct BOUNDSHEET {
    // dummy structure for BOUNDSHEET
    char name[1];
} BOUNDSHEET;

typedef struct XF5 {
    // dummy structure for XF5
} XF5;

typedef struct XF8 {
    // dummy structure for XF8
} XF8;

typedef struct FONT {
    // dummy structure for FONT
    char name[1];
} FONT;

typedef struct FORMAT {
    // dummy structure for FORMAT
    char value[1];
} FORMAT;

#define XLS_RECORD_BOF 0x809
#define XLS_RECORD_CODEPAGE 0x42
#define XLS_RECORD_WINDOW1 0x3D
#define XLS_RECORD_SST 0xFC
#define XLS_RECORD_BOUNDSHEET 0x85
#define XLS_RECORD_XF 0xE0
#define XLS_RECORD_FONT 0x31
#define XLS_RECORD_FONT_ALT 0x41
#define XLS_RECORD_FORMAT 0x1E
#define XLS_RECORD_STYLE 0x293
#define XLS_RECORD_1904 0x22