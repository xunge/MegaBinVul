#include <stdint.h>

typedef struct JsVar JsVar;

typedef enum {
    JSET_ERROR,
    // other error types...
} JsExceptionType;

typedef enum {
    JSGRAPHICSTYPE_ARRAYBUFFER,
    // other types...
} JsGraphicsType;

typedef enum {
    JSGRAPHICSFLAGS_NONE = 0,
    JSGRAPHICSFLAGS_ARRAYBUFFER_ZIGZAG = 1,
    JSGRAPHICSFLAGS_ARRAYBUFFER_MSB = 2,
    JSGRAPHICSFLAGS_ARRAYBUFFER_VERTICAL_BYTE = 4,
    JSGRAPHICSFLAGS_COLOR_BRG = 8,
    JSGRAPHICSFLAGS_COLOR_BGR = 16,
    JSGRAPHICSFLAGS_COLOR_GBR = 32,
    JSGRAPHICSFLAGS_COLOR_GRB = 64,
    JSGRAPHICSFLAGS_COLOR_RBG = 128
} JsGraphicsFlags;

typedef struct JsGraphicsData {
    uint8_t type;
    uint8_t flags;
    uint16_t width;
    uint16_t height;
    uint8_t bpp;
} JsGraphicsData;

typedef struct JsGraphics {
    JsGraphicsData data;
    JsVar *graphicsVar;
} JsGraphics;

void jsExceptionHere(JsExceptionType type, const char *message);
int isValidBPP(int bpp);
JsVar *jspNewObject(JsVar *parent, const char *name);
void graphicsStructInit(JsGraphics *gfx);
int jsvIsObject(JsVar *var);
int jsvGetBoolAndUnLock(JsVar *var);
JsVar *jsvObjectGetChild(JsVar *parent, const char *name, int createIfNotExists);
int jsvIsStringEqual(JsVar *var, const char *str);
void jsvUnLock(JsVar *var);
void jsWarn(const char *message);
void lcdInit_ArrayBuffer(JsGraphics *gfx);
void graphicsSetVar(JsGraphics *gfx);