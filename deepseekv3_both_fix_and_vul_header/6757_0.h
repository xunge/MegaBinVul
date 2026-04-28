#include <stdio.h>
#include <stdlib.h>

#define FONTINFO2_WIDEOFFSETS 0x04
#define FONTINFO2_WIDECODES 0x08
#define FONTINFO2_HASLAYOUT 0x80

extern int fileOffset;

unsigned char readUInt8(FILE *f);
unsigned short readUInt16(FILE *f);
unsigned int readUInt32(FILE *f);
short readSInt16(FILE *f);
int readBits(FILE *f, int n);
void byteAlign();
char *indent();
int printShapeRec(FILE *f, int *fillBits, int *lineBits, int level);
void printRect(FILE *f);