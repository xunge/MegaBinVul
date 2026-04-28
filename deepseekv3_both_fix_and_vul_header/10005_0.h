#include <stdio.h>
#include <string.h>

#define MAX_QPATH 256

typedef int fileHandle_t;

typedef struct {
    int current;
    int totallines;
    int linewidth;
    short *text;
} console_t;

extern console_t con;
extern void Com_Printf(const char *fmt, ...);
extern int Cmd_Argc(void);
extern char *Cmd_Argv(int arg);
extern void Q_strncpyz(char *dest, const char *src, int destsize);
extern void COM_DefaultExtension(char *path, int maxSize, const char *extension);
extern fileHandle_t FS_FOpenFileWrite(const char *filename);
extern void FS_Write(const void *buffer, int len, fileHandle_t f);
extern void FS_FCloseFile(fileHandle_t f);
extern void *Hunk_AllocateTempMemory(int size);
extern void Hunk_FreeTempMemory(void *buf);
extern void Q_strcat(char *dest, int size, const char *src);