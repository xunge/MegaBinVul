#include <stdio.h>
#include <string.h>

typedef unsigned char byte;
typedef int qboolean;

#define MAX_OSPATH 256
#define CVAR_ARCHIVE 1
#define CVAR_LATCH 2
#define REF_API_VERSION 1
#define ERR_FATAL 1
#define qfalse 0

typedef struct cvar_s {
    char *string;
    char *resetString;
} cvar_t;

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
    int (*FS_FileIsInPAK)(const char *name);
    int (*FS_FileExists)(const char *name);
    struct cvar_s *(*Cvar_Get)(const char *name, const char *value, int flags);
    void (*Cvar_Set)(const char *name, const char *value);
    void (*Cvar_SetValue)(const char *name, float value);
    void (*Cvar_CheckRange)(struct cvar_s *var, float min, float max, qboolean integral);
    int (*Cvar_VariableIntegerValue)(const char *var_name);
    void (*CIN_UploadCinematic)(int handle);
    int (*CIN_PlayCinematic)(const char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
    int (*CIN_RunCinematic)(int handle);
    void (*CL_WriteAVIVideoFrame)(const char *filename, int width, int height, byte *buffer, int numFrames);
    void (*IN_Init)(void *windowData);
    void (*IN_Shutdown)(void);
    void (*IN_Restart)(void);
    int (*ftol)(float f);
    void (*Sys_SetEnv)(const char *name, const char *value);
    void *(*Sys_GLimpSafeInit)(void);
    void *(*Sys_GLimpInit)(void);
    qboolean (*Sys_LowPhysicalMemory)(void);
} refimport_t;

typedef struct refexport_s {
    void (*Shutdown)(qboolean destroyWindow);
    void (*BeginRegistration)(const char *map);
    struct model_s *(*RegisterModel)(const char *name);
    struct image_s *(*RegisterSkin)(const char *name);
    void (*SetSky)(const char *name, float rotate, float *axis);
    void (*EndRegistration)(void);
    void (*RenderFrame)(void *fd);
    void (*DrawStretchPic)(int x, int y, int w, int h, float s1, float t1, float s2, float t2, int hShader);
    void (*DrawStretchRaw)(int x, int y, int w, int h, int cols, int rows, const byte *data, int client, qboolean dirty);
    void (*UploadCinematic)(int cols, int rows, const byte *data, int client, qboolean dirty);
    void (*BeginFrame)(float cameraSeparation);
    void (*EndFrame)(void);
    int (*Mark)(void);
    void (*ClearScene)(void);
    void (*AddRefEntityToScene)(const void *ent);
    void (*AddPolyToScene)(int hShader, int numVerts, const void *verts);
    void (*LightForPoint)(float *point, float *ambientLight, float *directedLight, float *lightDir);
    void (*AddLightToScene)(const float *org, float intensity, float r, float g, float b);
    void (*AddAdditiveLightToScene)(const float *org, float intensity, float r, float g, float b);
    void (*RenderScene)(const void *fd);
    void (*SetColor)(const float *rgba);
    void (*DrawStretchPicGradient)(int x, int y, int w, int h, float s1, float t1, float s2, float t2, int hShader, const float *gradientColor, int gradientType);
    void (*DrawHandlePic)(float x, float y, float w, float h, int hShader);
    void (*DrawStretchRawGradient)(int x, int y, int w, int h, int cols, int rows, const byte *data, int client, qboolean dirty, const float *gradientColor, int gradientType);
    void (*Add2dPolys)(void *polys, int numPolys, int hShader);
    void (*CaptureScreen)(byte *buffer, int bufSize);
    void (*GetScreenShot)(byte *buffer, int w, int h);
    void (*GetScreenShotPixels)(byte *buffer, int w, int h);
} refexport_t;

typedef refexport_t* (*GetRefAPI_t)(int apiVersion, refimport_t *rimp);

extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(int level, const char *error, ...);
extern void Cmd_AddCommand(const char *name, void(*cmd)(void));
extern void Cmd_RemoveCommand(const char *name);
extern int Cmd_Argc(void);
extern char *Cmd_Argv(int arg);
extern void Cbuf_ExecuteText(int exec_when, const char *text);
extern void CL_RefPrintf(int level, const char *fmt, ...);
extern int CL_ScaledMilliseconds(void);
extern void *CL_RefMalloc(int size);
extern void Z_Free(void *ptr);
extern void CL_RefTagFree(int tag);
extern void Hunk_ClearToMark(void);
extern void *Hunk_Alloc(int size);
extern void *Hunk_AllocateTempMemory(int size);
extern void Hunk_FreeTempMemory(void *buf);
extern byte *CM_ClusterPVS(int cluster);
extern void CM_DrawDebugSurface(void (*drawPoly)(int color, int numPoints, float *points));
extern void *FS_ReadFile(const char *name, int *len);
extern void FS_FreeFile(void *buffer);
extern int FS_WriteFile(const char *name, const void *buffer, int size);
extern void FS_FreeFileList(char **list);
extern char **FS_ListFiles(const char *name, const char *extension, int *numfiles);
extern int FS_FileIsInPAK(const char *name);
extern int FS_FileExists(const char *name);
extern cvar_t *Cvar_Get(const char *name, const char *value, int flags);
extern void Cvar_Set(const char *name, const char *value);
extern void Cvar_SetValue(const char *name, float value);
extern void Cvar_CheckRange(cvar_t *var, float min, float max, qboolean integral);
extern int Cvar_VariableIntegerValue(const char *var_name);
extern void CIN_UploadCinematic(int handle);
extern int CIN_PlayCinematic(const char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern int CIN_RunCinematic(int handle);
extern void CL_WriteAVIVideoFrame(const char *filename, int width, int height, byte *buffer, int numFrames);
extern void IN_Init(void *windowData);
extern void IN_Shutdown(void);
extern void IN_Restart(void);
extern int Q_ftol(float f);
extern void Sys_SetEnv(const char *name, const char *value);
extern void *Sys_GLimpSafeInit(void);
extern void *Sys_GLimpInit(void);
extern qboolean Sys_LowPhysicalMemory(void);
extern cvar_t *cl_renderer;
extern void *rendererLib;
extern refexport_t re;