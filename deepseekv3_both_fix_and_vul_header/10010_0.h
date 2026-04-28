#include <stdio.h>
#include <stdint.h>

#define MAX_OSPATH 256
#define PATH_SEP '/'

typedef enum {qfalse, qtrue} qboolean;

void Com_Printf(const char *fmt, ...);
void *Sys_LoadLibrary(const char *name);
const char *Sys_BinaryPath(void);
const char *Cvar_VariableString(const char *var_name);
int FS_FilenameCompare(const char *s1, const char *s2);
void Com_sprintf(char *dest, size_t size, const char *fmt, ...);