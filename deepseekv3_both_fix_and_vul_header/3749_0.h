#include <wchar.h>

typedef struct _PyPathConfig {
    wchar_t program_full_path[1];
} _PyPathConfig;

typedef struct PyCalculatePath {
    // 假设结构体为空或包含必要字段
} PyCalculatePath;

static int get_dllpath(wchar_t *filename);
static int change_ext(wchar_t *dest, const wchar_t *src, const wchar_t *ext);
static int exists(const wchar_t *filename);