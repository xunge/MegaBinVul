#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define L_HORIZ 1
#define L_VERT 2
#define L_COPY 1

typedef int32_t l_int32;
typedef struct SArray SARRAY;
typedef struct Sela SELA;

void selectComposableSizes(l_int32 size, l_int32 *psize1, l_int32 *psize2);
char *selaGetBrickName(SELA *sela, l_int32 h, l_int32 v);
char *selaGetCombName(SELA *sela, l_int32 size, l_int32 direction);
SELA *selaAddBasic(SELA *sela);
SELA *selaAddDwaCombs(SELA *sela);
SARRAY *sarrayCreate(l_int32 n);
void sarrayAddString(SARRAY *sa, const char *str, l_int32 copyflag);
char *sarrayToString(SARRAY *sa, l_int32 addnewline);
void sarrayDestroy(SARRAY **psa);
void selaDestroy(SELA **psela);
char *stringNew(const char *str);
void l_binaryWrite(const char *fileout, const char *mode, const void *data, size_t size);
void *LEPT_FREE(void *ptr);