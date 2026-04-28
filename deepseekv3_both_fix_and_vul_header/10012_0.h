#include <stdio.h>
#include <string.h>

typedef enum {qfalse, qtrue} qboolean;
typedef int fileHandle_t;

typedef struct searchpath_s {
    struct searchpath_s *next;
    void *pack;
} searchpath_t;

extern searchpath_t *fs_searchpaths;
extern FILE *missingFiles;

void Com_Error(int level, const char *error);

#define ERR_FATAL 1
#define Q3CONFIG_CFG "q3config.cfg"
#define FS_MISSING

long FS_FOpenFileReadDir(const char *filename, searchpath_t *search, fileHandle_t *file, qboolean uniqueFILE, qboolean b);