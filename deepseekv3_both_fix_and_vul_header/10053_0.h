#include <stdlib.h>

typedef struct {
    double *Weights;
} ContributionType;

typedef struct {
    unsigned int WindowSize;
    unsigned int LineLength;
    ContributionType *ContribRow;
} LineContribType;

extern void *gdMalloc(size_t size);
extern void gdFree(void *ptr);
extern int overflow2(size_t a, size_t b);