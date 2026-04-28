#include <stdbool.h>

#define MagnitudeContexts 18

typedef struct {
    void (*Init)(const char*);
} Context;

Context X[MagnitudeContexts];
Context M[MagnitudeContexts];