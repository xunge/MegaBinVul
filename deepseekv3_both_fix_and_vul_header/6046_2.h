#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

typedef struct JsVar JsVar;

typedef struct {
    int type;
} JsGraphicsData;

typedef struct JsGraphics {
    JsVar* graphicsVar;
    JsGraphicsData data;
    void (*setPixel)(struct JsGraphics*);
    void (*getPixel)(struct JsGraphics*);
    void (*fillRect)(struct JsGraphics*);
    void (*scroll)(struct JsGraphics*);
} JsGraphics;

#define JS_HIDDEN_CHAR_STR ""
#define JSGRAPHICSTYPE_SDL 0
#define JSGRAPHICSTYPE_FSMC 0
#define JSGRAPHICSTYPE_ARRAYBUFFER 0
#define JSGRAPHICSTYPE_JS 0
#define JSGRAPHICSTYPE_SPILCD 0
#define JSGRAPHICSTYPE_ST7789_8BIT 0
#define JSET_INTERNALERROR 0
#define SAVE_ON_FLASH 0
#define USE_LCD_SDL 0
#define USE_LCD_FSMC 0
#define USE_LCD_SPI 0
#define USE_LCD_ST7789_8BIT 0

extern JsVar* jsvObjectGetChild(JsVar* parent, const char* name, int createIfNotExists);
extern void jsvUnLock(JsVar* var);
extern void jsvGetString(JsVar* var, char* str, size_t len);
extern void graphicsFallbackSetPixel(JsGraphics* gfx);
extern void graphicsFallbackGetPixel(JsGraphics* gfx);
extern void graphicsFallbackFillRect(JsGraphics* gfx);
extern void graphicsFallbackScroll(JsGraphics* gfx);
extern void lcdSetCallbacks_SDL(JsGraphics* gfx);
extern void lcdSetCallbacks_FSMC(JsGraphics* gfx);
extern void lcdSetCallbacks_ArrayBuffer(JsGraphics* gfx);
extern void lcdSetCallbacks_JS(JsGraphics* gfx);
extern void lcdSetCallbacks_SPILCD(JsGraphics* gfx);
extern void lcdST7789_setCallbacks(JsGraphics* gfx);
extern void jsExceptionHere(int type, const char* message);