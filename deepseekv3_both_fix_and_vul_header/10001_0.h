#include <stddef.h>
#include <stdbool.h>

#define S_COLOR_YELLOW ""
#define PATH_SEP '/'
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

typedef bool qboolean;

void Com_Printf(const char *fmt, ...);
bool COM_CompareExtension(const char *name, const char *ext);
void *Sys_LoadLibrary(const char *name);
const char *Sys_LibraryError(void);
const char *Sys_BinaryPath(void);
const char *Cvar_VariableString(const char *var);
char *va(const char *format, ...);