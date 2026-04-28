#include <stdio.h>
#include <string.h>

#define MAX_QPATH 256

void Com_Printf(const char *fmt, ...);
void Q_strncpyz(char *dest, const char *src, size_t destsize);
void COM_DefaultExtension(char *path, size_t len, const char *extension);
void Com_WriteConfigToFile(const char *filename);
int Cmd_Argc(void);
const char *Cmd_Argv(int arg);