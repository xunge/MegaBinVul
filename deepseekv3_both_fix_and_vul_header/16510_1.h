#include <stdio.h>
#include <string.h>

typedef unsigned int CharCode;
typedef unsigned int Unicode;

#define maxUnicodeString 8
#define unlikely(x) (x)

struct CharCodeToUnicodeString {
  CharCode c;
  int len;
  Unicode u[maxUnicodeString];
};

struct CharCodeToUnicode {
  CharCode mapLen;
  Unicode *map;
  int sMapLen;
  int sMapSize;
  CharCodeToUnicodeString *sMap;
  
  void addMapping(CharCode code, char *uStr, int n, int offset);
};

extern void *greallocn(void *p, int n, int size);
extern void error(int code, const char *msg);