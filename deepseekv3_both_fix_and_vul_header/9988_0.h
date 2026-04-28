#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char BYTE;
typedef unsigned long ULONG;

typedef struct {
    BYTE *data;
    int size;
} variableLength;

unsigned int SwapDWord(BYTE *data, int size);
#define ALLOCCHECK_CHAR(ptr) if (!(ptr)) { printf("Memory allocation failed\n"); exit(-1); }
#define RTF_PREBUF "{\\rtf1\\ansi\\mac\\deff0\\deftab720{\\fonttbl;}{\\f0\\fnil \\froman \\fswiss \\fmodern \\fscript \\fdecor MS Sans SerifSymbolArialTimes New RomanCourier{\\colortbl\\red0\\green0\\blue0\n\r\\par \\pard\\plain\\f0\\fs20\\b\\i\\u\\tab\\tx"