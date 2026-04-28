#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#endif

typedef int l_int32;
typedef float l_float32;

#define L_NOCOPY 0
#define L_COPY 1
#define ERROR_INT(msg, procName, val) (fprintf(stderr, "%s: %s\n", procName, msg), val)
#define L_WARNING(msg, procName) fprintf(stderr, "%s: %s\n", procName, msg)
#define L_ERROR(msg, procName, ...) fprintf(stderr, "%s: " msg "\n", procName, ##__VA_ARGS__)
#define PROCNAME(name) static const char *procName = name

#define DEFAULT_THUMB_WIDTH 100
#define MIN_THUMB_WIDTH 20
#define DEFAULT_VIEW_WIDTH 800
#define MIN_VIEW_WIDTH 100

typedef struct PIX PIX;
typedef struct SARRAY SARRAY;

static SARRAY *getFilenamesInDirectory(const char *dirname);
static char *stringNew(const char *str);
static char *stringJoin(const char *str1, const char *str2);
static char *genPathname(const char *dir, const char *fname);
static PIX *pixRead(const char *filename);
static void pixGetDimensions(PIX *pix, l_int32 *pw, l_int32 *ph, l_int32 *pd);
static PIX *pixScale(PIX *pix, l_float32 scalex, l_float32 scaley);
static void WriteFormattedPix(const char *filename, PIX *pix);
static PIX *pixClone(PIX *pix);
static void pixDestroy(PIX **pix);
static void lept_free(void *ptr);
static void l_binaryWrite(const char *filename, const char *mode, void *data, size_t size);
static char *sarrayToString(SARRAY *sa, l_int32 addnewline);
static void sarrayDestroy(SARRAY **psa);
static SARRAY *sarrayCreate(l_int32 n);
static l_int32 sarrayGetCount(SARRAY *sa);
static char *sarrayGetString(SARRAY *sa, l_int32 index, l_int32 copyflag);
static void sarrayAddString(SARRAY *sa, const char *str, l_int32 copyflag);