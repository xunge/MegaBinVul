#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <setjmp.h>
#include <stdint.h>

typedef struct GmfMshSct GmfMshSct;
struct GmfMshSct {
   int typ;
   FILE *hdl;
   jmp_buf err;
};

#define GmfStrSiz 256
#define GmfMaxKwd 100
#define GmfEnd 999
#define Asc 1

extern char GmfKwdFmt[GmfMaxKwd+1][256];
extern int64_t GetFilSiz(GmfMshSct *msh);
extern int64_t GetPos(GmfMshSct *msh);
extern int SetFilPos(GmfMshSct *msh, int64_t pos);
extern void ScaWrd(GmfMshSct *msh, char *buf);
extern void ScaKwdHdr(GmfMshSct *msh, int KwdCod);