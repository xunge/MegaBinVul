#include <stdio.h>
#include <string.h>

typedef unsigned char byte;
typedef int qboolean;

#define MAX_OSPATH 256
#define REF_API_VERSION 1
#define CVAR_ARCHIVE (1<<0)
#define CVAR_LATCH (1<<1)
#define ERR_FATAL 0
#define qfalse 0

struct refEntity_s;
struct polyVert_s;
struct refdef_s;

typedef struct refimport_s {
    void (*Cmd_AddCommand)(const char *name, void(*cmd)(void));
    void (*Cmd_RemoveCommand)(const char *name);
    int (*Cmd_Argc)(void);
    char *(*Cmd_Argv)(int arg);
    void (*Cmd_ExecuteText)(int exec_when, const char *text);
    void (*Printf)(int level, const char *fmt, ...);
    void (*Error)(int level, const char *error, ...);
    int (*Milliseconds)(void);
    void *(*Z_Malloc)(int size);
    void (*Free)(void *ptr);
    void (*Tag_Free)(int tag);
    void (*Hunk_Clear)(void);
    void *(*Hunk_Alloc)(int size);
    void *(*Hunk_AllocateTempMemory)(int size);
    void (*Hunk_FreeTempMemory)(void *buf);
    byte *(*CM_ClusterPVS)(int cluster);
    void (*CM_DrawDebugSurface)(void (*drawPoly)(int color, int numPoints, float *points));
    void *(*FS_ReadFile)(const char *name, int *len);
    void (*FS_FreeFile)(void *buffer);
    int (*FS_WriteFile)(const char *name, const void *buffer, int size);
    void (*FS_FreeFileList)(char **list);
    char **(*FS_ListFiles)(const char *name, const char *extension, int *numfiles);
    int (*FS_FileIsInPAK)(const char *name, int *pChecksum);
    int (*FS_FileExists)(const char *name);
    void *(*Cvar_Get)(const char *name, const char *value, int flags);
    void (*Cvar_Set)(const char *name, const char *value);
    void (*Cvar_SetValue)(const char *name, float value);
    void (*Cvar_CheckRange)(void *var, float min, float max, qboolean integral);
    int (*Cvar_VariableIntegerValue)(const char *name);
    void (*CIN_UploadCinematic)(int handle);
    int (*CIN_PlayCinematic)(const char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
    int (*CIN_RunCinematic)(int handle);
    void (*CL_WriteAVIVideoFrame)(const char *filename, int width, int height, byte *buffer, int numFrames);
    void (*IN_Init)(void *window);
    void (*IN_Shutdown)(void);
    void (*IN_Restart)(void);
    int (*ftol)(float f);
    void (*Sys_SetEnv)(const char *name, const char *value);
    void (*Sys_GLimpSafeInit)(void);
    void (*Sys_GLimpInit)(void);
    qboolean (*Sys_LowPhysicalMemory)(void);
} refimport_t;

typedef struct refexport_s {
    void (*Shutdown)(qboolean destroyWindow);
    void (*BeginRegistration)(const char *map);
    void (*RegisterModel)(const char *name);
    void (*RegisterSkin)(const char *name);
    void (*RegisterShader)(const char *name);
    void (*RegisterShaderNoMip)(const char *name);
    void (*LoadWorld)(const char *name);
    void (*SetWorldVisData)(const byte *vis);
    void (*EndRegistration)(void);
    void (*ClearScene)(void);
    void (*AddRefEntityToScene)(const struct refEntity_s *re);
    void (*AddPolyToScene)(int shader, int numVerts, const struct polyVert_s *verts);
    void (*LightForPoint)(const float *point, float *dir, float *color, float *intensity);
    void (*RenderScene)(const struct refdef_s *fd);
    void (*SetColor)(const float *rgba);
    void (*DrawStretchPic)(float x, float y, float w, float h, float s1, float t1, float s2, float t2, int shader);
    void (*DrawStretchRaw)(int x, int y, int w, int h, int cols, int rows, const byte *data, int client, qboolean dirty);
    void (*UploadCinematic)(int cols, int rows, const byte *data, int client, qboolean dirty);
    void (*BeginFrame)(int camera);
    void (*EndFrame)(void);
    int (*Mark)(void);
    void (*Reset)(void);
    void (*TakeVideoFrame)(int h, int w, byte *captureBuffer, byte *encodeBuffer, qboolean motionJpeg);
} refexport_t;

extern refexport_t re;
extern void *rendererLib;
extern void *cl_renderer;

typedef refexport_t *(*GetRefAPI_t)(int apiVersion, refimport_t *rimp);

// Function prototypes
void Com_Printf(const char *fmt, ...);
void Com_Error(int level, const char *error, ...);
void Cmd_AddCommand(const char *name, void(*cmd)(void));
void Cmd_RemoveCommand(const char *name);
int Cmd_Argc(void);
char *Cmd_Argv(int arg);
void Cbuf_ExecuteText(int exec_when, const char *text);
void CL_RefPrintf(int level, const char *fmt, ...);
int CL_ScaledMilliseconds(void);
void *CL_RefMalloc(int size);
void Z_Free(void *ptr);
void CL_RefTagFree(int tag);
void Hunk_ClearToMark(void);
void *Hunk_Alloc(int size);
void *Hunk_AllocateTempMemory(int size);
void Hunk_FreeTempMemory(void *buf);
byte *CM_ClusterPVS(int cluster);
void CM_DrawDebugSurface(void (*drawPoly)(int color, int numPoints, float *points));
void *FS_ReadFile(const char *name, int *len);
void FS_FreeFile(void *buffer);
int FS_WriteFile(const char *name, const void *buffer, int size);
void FS_FreeFileList(char **list);
char **FS_ListFiles(const char *name, const char *extension, int *numfiles);
int FS_FileIsInPAK(const char *name, int *pChecksum);
int FS_FileExists(const char *name);
void *Cvar_Get(const char *name, const char *value, int flags);
void Cvar_Set(const char *name, const char *value);
void Cvar_SetValue(const char *name, float value);
void Cvar_CheckRange(void *var, float min, float max, qboolean integral);
int Cvar_VariableIntegerValue(const char *name);
void CIN_UploadCinematic(int handle);
int CIN_PlayCinematic(const char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
int CIN_RunCinematic(int handle);
void CL_WriteAVIVideoFrame(const char *filename, int width, int height, byte *buffer, int numFrames);
void IN_Init(void *window);
void IN_Shutdown(void);
void IN_Restart(void);
int Q_ftol(float f);
void Sys_SetEnv(const char *name, const char *value);
void Sys_GLimpSafeInit(void);
void Sys_GLimpInit(void);
qboolean Sys_LowPhysicalMemory(void);