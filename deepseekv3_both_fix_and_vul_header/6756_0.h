#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct SWF_Parserstruct SWF_Parserstruct;
typedef struct {
    int size;
} Movie;

extern int fileOffset;
extern int filelen_check_fails(int);
extern unsigned short readUInt16(FILE *);
extern unsigned long readUInt32(FILE *);
extern SWF_Parserstruct* blockParse(FILE *, int, int);
extern void outputBlock(int, SWF_Parserstruct *, FILE *);
extern void SWF_warn(const char *, ...);
extern const char* blockName(int);
extern void dumpBytes(FILE *, int);
extern void outputTrailer(Movie *);
extern Movie m;
extern int filelen;