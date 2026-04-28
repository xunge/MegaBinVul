#include <stdlib.h>
#include <string.h>

#if defined(PLATFORM_DESKTOP)
#include <GLFW/glfw3.h>
#endif

#if defined(PLATFORM_WEB)
#include <emscripten.h>
#endif

typedef struct {
    void* handle;
} WindowInfo;

typedef struct {
    WindowInfo Window;
} CoreState;

extern CoreState CORE;

char* TextFormat(const char* text, ...);