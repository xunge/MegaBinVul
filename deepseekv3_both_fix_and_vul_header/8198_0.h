#include <math.h>
#include <stdlib.h>

#define DEFAULT_BOX_RADIUS 0.5
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef double (*interpolation_method)(double);

typedef struct {
    double *Weights;
    int Left;
    int Right;
} ContributionType;

typedef struct {
    unsigned int LineLength;
    ContributionType *ContribRow;
} LineContribType;

static LineContribType *_gdContributionsAlloc(unsigned int line_length, int windows_size);
static void _gdContributionsFree(LineContribType *p);