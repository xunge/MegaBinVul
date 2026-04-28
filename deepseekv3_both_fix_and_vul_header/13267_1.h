#include <stdlib.h>
#include <string.h>

typedef struct Vector2 {
    float x;
    float y;
} Vector2;

typedef struct Image {
    unsigned char *data;
    int width;
    int height;
    int mipmaps;
    int format;
} Image;

typedef struct Core {
    struct {
        struct {
            int width;
            int height;
        } render;
    } Window;
    struct {
        char basePath[2048];
    } Storage;
} Core;

extern Core CORE;
extern Vector2 GetWindowScaleDPI(void);
extern unsigned char *rlReadScreenPixels(int width, int height);
extern void ExportImage(Image image, const char *fileName);
extern char *TextFormat(const char *text, ...);
extern const char *GetFileName(const char *path);
extern void TRACELOG(int logType, const char *text, ...);
extern void RL_FREE(void *ptr);

#if defined(PLATFORM_WEB)
#include <emscripten.h>
#endif

#define SUPPORT_MODULE_RTEXTURES
#define PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 0
#define LOG_INFO 0
#define LOG_WARNING 1