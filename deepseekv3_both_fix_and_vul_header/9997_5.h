#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OSPATH 256
#define ARCH_STRING "x86"
#define DLL_EXT "dll"
#define DEFAULT_RENDER_LIBRARY "renderer"
#define CVAR_ARCHIVE 1
#define CVAR_LATCH 2
#define CVAR_PROTECTED 4
#define REF_API_VERSION 1
#define ERR_FATAL 1

typedef int qboolean;
#define qfalse 0
#define qtrue 1

typedef struct cvar_s {
    char* string;
    char* resetString;
} cvar_t;

typedef struct refexport_s {
    int dummy;
} refexport_t;

typedef struct refimport_s {
    void (*CIN_PlayCinematic)(void);
    void (*CIN_RunCinematic)(void);
    void (*CIN_UploadCinematic)(void);
    void (*CL_IsRunningInGameCinematic)(void);
    void (*Cmd_AddCommand)(void);
    void (*Cmd_Argc)(void);
    void (*Cmd_ArgsBuffer)(void);
    void (*Cmd_Argv)(void);
    void (*Cmd_ExecuteString)(void);
    void (*Cmd_RemoveCommand)(void);
    void (*CM_ClusterPVS)(void);
    void (*CM_CullWorldBox)(void);
    void (*CM_DeleteCachedMap)(void);
    void (*CM_DrawDebugSurface)(void);
    void (*CM_PointContents)(void);
    void (*Cvar_Get)(void);
    void (*Cvar_Set)(void);
    void (*Cvar_SetValue)(void);
    void (*Cvar_CheckRange)(void);
    void (*Cvar_VariableIntegerValue)(void);
    void (*Cvar_VariableString)(void);
    void (*Cvar_VariableStringBuffer)(void);
    void (*Cvar_VariableValue)(void);
    void (*FS_FCloseFile)(void);
    void (*FS_FileIsInPAK)(void);
    void (*FS_FOpenFileByMode)(void);
    void (*FS_FOpenFileRead)(void);
    void (*FS_FOpenFileWrite)(void);
    void (*FS_FreeFile)(void);
    void (*FS_FreeFileList)(void);
    void (*FS_ListFiles)(void);
    void (*FS_Read)(void);
    void (*FS_ReadFile)(void);
    void (*FS_Write)(void);
    void (*FS_WriteFile)(void);
    void (*Hunk_ClearToMark)(void);
    void (*SND_RegisterAudio_LevelLoadEnd)(void);
    void (*SV_Trace)(void);
    void (*S_RestartMusic)(void);
    void (*Z_Free)(void);
    void* (*Malloc)(size_t size);
    void (*Z_MemSize)(void);
    void (*Z_MorphMallocTag)(void);
    void (*WIN_Init)(void);
    void (*WIN_SetGamma)(void);
    void (*WIN_Shutdown)(void);
    void (*WIN_Present)(void);
    void* (*GL_GetProcAddress)(const char* proc);
    qboolean (*GL_ExtensionSupported)(const char* ext);
    void (*PD_Load)(void);
    void (*PD_Store)(void);
    void (*Error)(int level, const char* error, ...);
    qboolean (*FS_FileExists)(const char* file);
    void* (*GetG2VertSpaceServer)(void);
    qboolean (*LowPhysicalMemory)(void);
    int (*Milliseconds)(void);
    void (*Printf)(const char* msg, ...);
    const char* (*SE_GetString)(const char* psPackageAndStringReference);
    void* (*get_gpvCachedMapDiskImage)(void);
    int (*get_gsCachedMapDiskImage)(void);
    qboolean (*get_gbUsingCachedMapDataRightNow)(void);
    qboolean (*get_gbAlreadyDoingLoad)(void);
    int (*get_com_frameTime)(void);
    int (*SV_PointContents)(void);
    void* (*gpvCachedMapDiskImage)(void);
    int (*gsCachedMapDiskImage)(void);
    qboolean (*gbUsingCachedMapDataRightNow)(void);
    qboolean (*gbAlreadyDoingLoad)(void);
    int (*com_frameTime)(void);
    void* saved_game;
} refimport_t;

typedef refexport_t* (*GetRefAPI_t)(int, refimport_t*);

extern refexport_t re;
extern void* rendererLib;
extern cvar_t* cl_renderer;

void Com_Printf(const char* fmt, ...);
void Com_Error(int level, const char* fmt, ...);
void Com_sprintf(char* dest, size_t size, const char* fmt, ...);
void* Sys_LoadDll(const char* name, qboolean unpure);
void* Sys_LoadFunction(void* library, const char* name);
const char* Sys_LibraryError(void);
void Cvar_ForceReset(const char* var_name);
cvar_t* Cvar_Get(const char* name, const char* value, int flags);
void Cvar_Set(const char* var_name, const char* value);
void* CL_Malloc(size_t size);

void CIN_PlayCinematic(void);
void CIN_RunCinematic(void);
void CIN_UploadCinematic(void);
void CL_IsRunningInGameCinematic(void);
void Cmd_AddCommand(void);
void Cmd_Argc(void);
void Cmd_ArgsBuffer(void);
void Cmd_Argv(void);
void Cmd_ExecuteString(void);
void Cmd_RemoveCommand(void);
void CM_ClusterPVS(void);
void CM_CullWorldBox(void);
void CM_DeleteCachedMap(void);
void CM_DrawDebugSurface(void);
void CM_PointContents(void);
void Cvar_Get(void);
void Cvar_Set(void);
void Cvar_SetValue(void);
void Cvar_CheckRange(void);
void Cvar_VariableIntegerValue(void);
void Cvar_VariableString(void);
void Cvar_VariableStringBuffer(void);
void Cvar_VariableValue(void);
void FS_FCloseFile(void);
void FS_FileIsInPAK(void);
void FS_FOpenFileByMode(void);
void FS_FOpenFileRead(void);
void FS_FOpenFileWrite(void);
void FS_FreeFile(void);
void FS_FreeFileList(void);
void FS_ListFiles(void);
void FS_Read(void);
void FS_ReadFile(void);
void FS_Write(void);
void FS_WriteFile(void);
void Hunk_ClearToMark(void);
void SND_RegisterAudio_LevelLoadEnd(void);
void SV_Trace(void);
void S_RestartMusic(void);
void Z_Free(void);
void Z_MemSize(void);
void Z_MorphMallocTag(void);
void WIN_Init(void);
void WIN_SetGamma(void);
void WIN_Shutdown(void);
void WIN_Present(void);
void* WIN_GL_GetProcAddress(const char* proc);
qboolean WIN_GL_ExtensionSupported(const char* ext);
void PD_Load(void);
void PD_Store(void);
qboolean S_FileExists(const char* file);
void* GetG2VertSpaceServer(void);
qboolean Sys_LowPhysicalMemory(void);
int Sys_Milliseconds2(void);
void CL_RefPrintf(const char* msg, ...);
const char* String_GetStringValue(const char* psPackageAndStringReference);
void* get_gpvCachedMapDiskImage(void);
int get_gsCachedMapDiskImage(void);
qboolean get_gbUsingCachedMapDataRightNow(void);
qboolean get_gbAlreadyDoingLoad(void);
int get_com_frameTime(void);
int SV_PointContents(void);

namespace ojk {
    class SavedGame {
    public:
        static SavedGame& get_instance();
    };
}