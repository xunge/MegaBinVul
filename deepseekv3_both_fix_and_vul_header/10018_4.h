#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef int qboolean;
typedef enum {
    FMV_IDLE,
    FMV_PLAY,
    FMV_EOF,
    FMV_ID_BLT,
    FMV_ID_LOOP,
    FMV_LOOPED,
    FMV_ID_WAIT
} e_status;

#define MAX_OSPATH 256
#define ARCH_STRING "x86"
#define DLL_EXT ".dll"
#define USE_RENDERER_DLOPEN
#define REF_API_VERSION 1
#define CVAR_ARCHIVE (1<<0)
#define CVAR_LATCH (1<<1)
#define CVAR_PROTECTED (1<<2)
#define qfalse 0
#define qtrue 1
#define ERR_FATAL 1
#define HUNK_DEBUG

typedef struct refimport_s {
    void (*Cmd_AddCommand)(const char *cmd_name);
    void (*Cmd_RemoveCommand)(const char *cmd_name);
    int (*Cmd_Argc)(void);
    char *(*Cmd_Argv)(int arg);
    void (*Cmd_ExecuteText)(int exec_when, const char *text);
    void (*Printf)(const char *fmt, ...);
    void (*Error)(int level, const char *fmt, ...);
    int (*Milliseconds)(void);
    void *(*Malloc)(size_t size);
    void (*Free)(void *ptr);
    void *(*Hunk_AllocDebug)(size_t size, const char *label, int align);
    void *(*Hunk_Alloc)(size_t size, int align);
    void *(*Hunk_AllocateTempMemory)(size_t size);
    void (*Hunk_FreeTempMemory)(void *buf);
    const byte *(*CM_ClusterPVS)(int cluster);
    void (*CM_DrawDebugSurface)(void (*drawPoly)(int color, int numPoints, float *points));
    void *(*FS_ReadFile)(const char *qpath, int *len);
    void (*FS_FreeFile)(void *buffer);
    int (*FS_WriteFile)(const char *qpath, const void *buffer, int size);
    void (*FS_FreeFileList)(char **list);
    char **(*FS_ListFiles)(const char *directory, const char *extension, int *numfiles);
    int (*FS_FileIsInPAK)(const char *filename, int *pChecksum);
    int (*FS_FileExists)(const char *file);
    struct cvar_s *(*Cvar_Get)(const char *var_name, const char *value, int flags);
    void (*Cvar_Set)(const char *var_name, const char *value);
    void (*Cvar_SetValue)(const char *var_name, float value);
    void (*Cvar_CheckRange)(struct cvar_s *var, float min, float max, qboolean integral);
    void (*Cvar_SetDescription)(struct cvar_s *var, const char *description);
    int (*Cvar_VariableIntegerValue)(const char *var_name);
    void (*CIN_UploadCinematic)(int handle);
    int (*CIN_PlayCinematic)(const char *arg0, int x, int y, int w, int h, int systemBits);
    e_status (*CIN_RunCinematic)(int handle);
    void (*CL_WriteAVIVideoFrame)(const byte *buffer, int size);
    void (*IN_Init)(void);
    void (*IN_Shutdown)(void);
    void (*IN_Restart)(void);
    int (*ftol)(float f);
    void (*Sys_SetEnv)(const char *name, const char *value);
    qboolean (*Sys_GLimpSafeInit)(void);
    qboolean (*Sys_GLimpInit)(void);
    qboolean (*Sys_LowPhysicalMemory)(void);
} refimport_t;

typedef struct refexport_s {
    int dummy;
} refexport_t;

typedef refexport_t* (*GetRefAPI_t)(int apiVersion, refimport_t *rimp);

extern refexport_t re;
extern void *rendererLib;
extern struct cvar_s *cl_renderer;

struct cvar_s {
    char *string;
    char *resetString;
};

void Cmd_AddCommand(const char *cmd_name);
void Cmd_RemoveCommand(const char *cmd_name);
int Cmd_Argc(void);
char *Cmd_Argv(int arg);
void Cbuf_ExecuteText(int exec_when, const char *text);
void CL_RefPrintf(const char *fmt, ...);
int CL_ScaledMilliseconds(void);
void *CL_RefMalloc(size_t size);
void Z_Free(void *ptr);
void *Hunk_AllocDebug(size_t size, const char *label, int align);
void *Hunk_Alloc(size_t size, int align);
void *Hunk_AllocateTempMemory(size_t size);
void Hunk_FreeTempMemory(void *buf);
const byte *CM_ClusterPVS(int cluster);
void CM_DrawDebugSurface(void (*drawPoly)(int color, int numPoints, float *points));
void *FS_ReadFile(const char *qpath, int *len);
void FS_FreeFile(void *buffer);
int FS_WriteFile(const char *qpath, const void *buffer, int size);
void FS_FreeFileList(char **list);
char **FS_ListFiles(const char *directory, const char *extension, int *numfiles);
int FS_FileIsInPAK(const char *filename, int *pChecksum);
int FS_FileExists(const char *file);
void Cvar_SetValue(const char *var_name, float value);
void Cvar_CheckRange(struct cvar_s *var, float min, float max, qboolean integral);
void Cvar_SetDescription(struct cvar_s *var, const char *description);
int Cvar_VariableIntegerValue(const char *var_name);
void CIN_UploadCinematic(int handle);
int CIN_PlayCinematic(const char *arg0, int x, int y, int w, int h, int systemBits);
e_status CIN_RunCinematic(int handle);
void CL_WriteAVIVideoFrame(const byte *buffer, int size);
void IN_Init(void);
void IN_Shutdown(void);
void IN_Restart(void);
int Q_ftol(float f);
void Sys_SetEnv(const char *name, const char *value);
qboolean Sys_GLimpSafeInit(void);
qboolean Sys_GLimpInit(void);
qboolean Sys_LowPhysicalMemory(void);
void Com_Printf(const char *fmt, ...);
void Com_Error(int level, const char *fmt, ...);
void Cvar_ForceReset(const char *var_name);
struct cvar_s *Cvar_Get(const char *var_name, const char *default_value, int flags);
void Cvar_Set(const char *var_name, const char *value);
void *Sys_LoadDll(const char *name, int useSystemLib);
void *Sys_LoadFunction(void *library, const char *functionName);
const char *Sys_LibraryError(void);
void Com_sprintf(char *dest, int size, const char *fmt, ...);