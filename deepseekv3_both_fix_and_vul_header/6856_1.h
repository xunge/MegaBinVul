#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define L_BUFSIZE 512
#define L_BUF_SIZE 512
#define L_MIN(a, b) ((a) < (b) ? (a) : (b))
#define L_COPY 0
#define FALSE 0
#define TRUE 1

typedef uint8_t l_uint8;
typedef int32_t l_int32;

typedef struct L_BYTEA L_BYTEA;
typedef struct SARRAY SARRAY;

extern char *version;

char *stringNew(const char *src);
void lept_free(void *ptr);
char *l_makeTempFilename(void);
int lept_rmfile(const char *filename);
L_BYTEA *l_byteaCreate(size_t nbytes);
void l_byteaDestroy(L_BYTEA **pba);
void l_byteaAppendString(L_BYTEA *ba, const char *str);
char *l_byteaCopyData(L_BYTEA *ba, size_t *pnbytes);
SARRAY *sarrayCreate(size_t n);
void sarrayDestroy(SARRAY **psa);
int sarrayAddString(SARRAY *sa, char *str, int copyflag);
char *sarrayToString(SARRAY *sa, int addnlflag);
L_BYTEA *l_byteaInitFromFile(const char *filename);
void l_byteaJoin(L_BYTEA *ba1, L_BYTEA **pba2);
size_t l_byteaWrite(const char *filename, L_BYTEA *ba, size_t start, size_t nbytes);
int l_binaryWrite(const char *filename, const char *mode, const void *data, size_t nbytes);
char *parseForProtos(const char *tempfile, const char *prestring);

#define L_WARNING(msg, name) fprintf(stderr, "Warning in %s: %s", name, msg)