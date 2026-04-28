#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <unistd.h>
#include <fcntl.h>

#define GmfStrSiz 256
#define WrdSiz 4
#define Bin 1
#define Asc 2
#define MshFil 4
#define SolFil 8
#define GmfRead 1
#define GmfWrite 2
#define GmfDimension 1
#define GmfVersionFormatted 0
#define WITH_GMF_AIO 1
#define OPEN_READ_FLAGS O_RDONLY
#define OPEN_READ_MODE 0
#define OPEN_WRITE_FLAGS O_WRONLY | O_CREAT | O_TRUNC
#define OPEN_WRITE_MODE 0644
#define GMFDEBUG 1
#define GMF_WINDOWS 0

typedef struct GmfMshSct {
    jmp_buf err;
    FILE *hdl;
    int FilDes;
    char FilNam[GmfStrSiz];
    int mod;
    int typ;
    void *buf;
    void *FltBuf;
    void *IntBuf;
    double DblBuf[1];
    int cod;
    int ver;
    int dim;
    int FltSiz;
} GmfMshSct;

extern int safe_fread(void *ptr, size_t size, size_t nmemb, FILE *stream, jmp_buf err);
extern int safe_fscanf(FILE *stream, const char *format, void *ptr, jmp_buf err);
extern void ScaWrd(GmfMshSct *msh, unsigned char *ptr);
extern void RecWrd(GmfMshSct *msh, unsigned char *ptr);
extern void GetPos(GmfMshSct *msh);
extern int ScaKwdTab(GmfMshSct *msh);
extern void GmfSetKwd(int64_t MshIdx, int KwdCod, int NmbLin);
extern char *GmfKwdFmt[][1];