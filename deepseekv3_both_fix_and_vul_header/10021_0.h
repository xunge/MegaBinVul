#include <stdio.h>
#include <string.h>

typedef int fileHandle_t;

#define MAX_QPATH 64
#define Q_strncpyz(dest, src, destsize) strncpy(dest, src, destsize-1), dest[destsize-1] = 0
#define Q_strcat(dest, destsize, src) strncat(dest, src, destsize - strlen(dest) - 1)

typedef struct {
    int current;
    int totallines;
    int linewidth;
    short *text;
} console_t;

extern console_t con;

void Com_Printf(const char *fmt, ...);
int Cmd_Argc(void);
char *Cmd_Argv(int arg);
void COM_DefaultExtension(char *path, int maxSize, const char *extension);
fileHandle_t FS_FOpenFileWrite(const char *filename);
void FS_Write(const void *buffer, int len, fileHandle_t f);
void FS_FCloseFile(fileHandle_t f);
void *Hunk_AllocateTempMemory(int size);
void Hunk_FreeTempMemory(void *buf);