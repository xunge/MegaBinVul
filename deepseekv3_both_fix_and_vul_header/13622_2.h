#include <stdio.h>
#include <string.h>

typedef unsigned int Unicode;
typedef unsigned int CharCode;

typedef struct {
    CharCode c;
    int len;
    Unicode *u;
} CharCodeToUnicodeString;

typedef struct CharCodeToUnicode {
    Unicode *map;
    CharCode mapLen;
    CharCodeToUnicodeString *sMap;
    int sMapLen;
    int sMapSize;
    
    void addMapping(CharCode code, char *uStr, int n, int offset);
} CharCodeToUnicode;

extern void *greallocn(void *p, int n, int m);
extern void *gmallocn(int n, int m);
extern void error(int err, const char *msg);
#define unlikely(x) (x)