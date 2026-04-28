#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    qfalse,
    qtrue
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

#define Q3CONFIG_NAME "q3config.cfg"
#define PATH_SEP '/'
#define ERR_FATAL 1

void *unzOpen(const char *path);
int unzSetOffset(void *file, long pos);
int unzOpenCurrentFile(void *file);

void FS_AssertInitialised(void);
long FS_HashFileName(const char *fname, int hashSize);
int FS_HandleForFile(void);
int FS_FilenameCompare(const char *s1, const char *s2);
char *FS_BuildOSPath(const char *base, const char *game, const char *qpath);
long FS_fplength(FILE *f);
void Com_Error(int level, const char *error, ...);
void Com_Printf(const char *msg, ...);
void Com_DPrintf(const char *msg, ...);
qboolean FS_FileCacheable(const char *filename);
void FS_CopyFile(const char *from, const char *to);
void FS_CreatePath(const char *path);
int Q_stricmp(const char *s1, const char *s2);
void Q_strncpyz(char *dest, const char *src, int destsize);