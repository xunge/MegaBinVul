#include <string.h>

#define MAX_QPATH 64
#define FS_READ 0

typedef struct {
    char string[MAX_QPATH];
} vmCvar_t;

typedef enum {
    CVAR_ROM,
    CVAR_SERVERINFO
} cvarFlags_t;

typedef enum {
    GT_COOP
} gametype_t;

typedef struct {
    gametype_t integer;
} cvar_t;

typedef struct {
    void* scriptAI;
} level_t;

typedef int fileHandle_t;

extern level_t level;
extern cvar_t g_gametype;
extern void trap_Cvar_VariableStringBuffer(const char* var_name, char* buffer, int buffer_size);
extern void trap_Cvar_Register(vmCvar_t* cvar, const char* var_name, const char* default_value, cvarFlags_t flags);
extern void Q_strncpyz(char* dest, const char* src, int destsize);
extern void Q_strcat(char* dest, int size, const char* src);
extern int trap_FS_FOpenFile(const char* qpath, fileHandle_t* f, int mode);
extern void G_Printf(const char* fmt, ...);
extern void* G_Alloc(int size);
extern int trap_FS_Read(void* buffer, int len, fileHandle_t f);
extern void trap_FS_FCloseFile(fileHandle_t f);