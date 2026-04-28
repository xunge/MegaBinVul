#include <stddef.h>

typedef void* GLFWwindow;

typedef struct {
    GLFWwindow* handle;
} CORE_Window;

extern CORE_Window CORE;

const char* glfwGetClipboardString(GLFWwindow* window);