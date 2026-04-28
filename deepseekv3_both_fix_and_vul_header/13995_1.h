#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXFONTFILENAMELEN 1024
#define CataloguePrefix "catalogue:"

typedef struct FontPathElement {
    void *private;
    char *name;
    int type;
    int name_length;
    int refcount;
} *FontPathElementPtr;

typedef struct Catalogue {
    time_t mtime;
    FontPathElementPtr *fpeList;
    int fpeCount;
} *CataloguePtr;

enum {
    BadFontPath,
    Successful
};

static void *xalloc(size_t size) { return malloc(size); }
static void xfree(void *ptr) { free(ptr); }
static int CatalogueUnrefFPEs(FontPathElementPtr fpe) { return 0; }
static int CatalogueAddFPE(CataloguePtr cat, FontPathElementPtr subfpe) { return 0; }
static int FontFileInitFPE(FontPathElementPtr fpe) { return 0; }
static void FontFileFreeFPE(FontPathElementPtr fpe) {}
static int ComparePriority(const void *a, const void *b) { return 0; }