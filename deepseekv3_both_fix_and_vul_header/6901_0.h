#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16384

extern char scrambleAsciiTables[16][256];
extern int usingKeyFile;
extern char passPhrase[16384];
extern int passIndex;
extern char scramblingTablesOrder[BUFFER_SIZE];
extern unsigned char generateNumber();