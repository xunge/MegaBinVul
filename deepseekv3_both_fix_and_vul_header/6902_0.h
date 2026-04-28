#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

extern char *progName;
extern char *fileName;
extern char pathToMainFile[1024];
extern int scrambling;
extern int isCodingInverted;
extern int usingKeyFile;
extern int numberOfBuffer;
extern char passPhrase[16384];
extern int isCrypting;

int ceilRound(float num);
int isADirectory(char *path);
char *processTarString(char *str);
void usage(int exitCode);
void readString(char *str, int maxLen);
void getSeed(char *passPhrase);
void scramble(FILE *keyFile);
void code(FILE *file);
void decode(FILE *file);