#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    qfalse = 0,
    qtrue = 1
} qboolean;

typedef int fileHandle_t;

typedef struct {
    union {
        FILE *o;
        void *z;
    } file;
    qboolean unique;
} handleFiles_t;

typedef struct {
    handleFiles_t handleFiles;
    char name[256];
    qboolean zipFile;
    long zipFilePos;
    long zipFileLen;
} fileHandleData_t;

typedef struct directory_s {
    char *path;
    char *gamedir;
} directory_t;

typedef struct fileInPack_s {
    char *name;
    long pos;
    long len;
    struct fileInPack_s *next;
} fileInPack_t;

typedef struct pack_s {
    char pakFilename[256];
    void *handle;
    fileInPack_t **hashTable;
    int hashSize;
} pack_t;

typedef struct searchpath_s {
    struct searchpath_s *next;
    pack_t *pack;
    directory_t *dir;
} searchpath_t;

typedef struct {
    int integer;
    char string[256];
} cvar_t;

extern fileHandleData_t fsh[];
extern searchpath_t *fs_searchpaths;
extern cvar_t *fs_debug;
extern cvar_t *fs_basepath;
extern cvar_t *fs_cdpath;
extern cvar_t *fs_copyfiles;
extern qboolean com_fullyInitialized;

void *unzOpen(const char *path);
int unzSetOffset(void *file, long pos);
int unzOpenCurrentFile(void *file);

#define Q3CONFIG_NAME "q3config.cfg"
#define PATH_SEP '/'
#define ERR_FATAL 1

#define Com_Error(code, fmt, ...) 
#define Com_Printf(fmt, ...) 
#define Com_DPrintf(fmt, ...) 
#define FS_AssertInitialised() 
#define FS_HandleForFile() 0
#define FS_HashFileName(name, size) 0
#define FS_FilenameCompare(a, b) 0
#define FS_BuildOSPath(a, b, c) NULL
#define FS_FileCacheable(name) 0
#define FS_fplength(file) 0
#define FS_CopyFile(src, dst) 
#define FS_CreatePath(path) 
#define Q_stricmp(a, b) 0
#define Q_strncpyz(dest, src, size) 
#define Sys_FileOutOfDate(a, b) 0