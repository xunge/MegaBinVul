#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    BreakUndefined,
    BreakWordBreakType
} BreakType;

typedef struct _Image {
    size_t columns;
} Image;

typedef struct _DrawInfo {
    char *text;
    BreakType word_break;
    double stroke_width;
} DrawInfo;

typedef struct _TypeMetric {
    double width;
} TypeMetric;

typedef struct _ExceptionInfo {
    // placeholder for exception info
} ExceptionInfo;

#define MagickExport

int GetUTFCode(const char *);
size_t GetUTFOctets(const char *);
int IsUTFSpace(int);
int IsNonBreakingUTFSpace(int);
char *ReplaceSpaceWithNewline(char **, char *);
MagickBooleanType GetTypeMetrics(Image *, DrawInfo *, TypeMetric *, ExceptionInfo *);
char *AcquireString(const char *);
void CopyMagickString(char *, const char *, size_t);
void ConcatenateMagickString(char *, const char *, size_t);
char *DestroyString(char *);