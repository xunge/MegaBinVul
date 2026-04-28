#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int repack_IDAT_size;
char *suffix;
char *outputPath;
int flag_Debug;
int flag_Verbose;
int flag_List_Chunks;
int flag_UpdateAlpha;
int flag_Process_Anyway;
int flag_Ignore_CRC32;
int flag_Rewrite;

int process(char *filename);