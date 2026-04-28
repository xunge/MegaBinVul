#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define likely(x) x

typedef int GBool;
#define gTrue 1
#define gFalse 0

char *copyString(const char *s);
char *getNextLine(char *line);
void *gmallocn(int n, int size);
void error(int err, const char *msg);

#define fofiType1StandardEncoding NULL

struct FoFiType1 {
    char *file;
    char *name;
    char **encoding;
    GBool parsed;
    void parse();
};