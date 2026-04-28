#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BLOSC2_ERROR_NULL_POINTER -1
#define BLOSC2_ERROR_FAILURE -2
#define BLOSC_UNUSED_PARAM(x) ((void)(x))
#define BLOSC_ERROR_NULL(ptr, error) if ((ptr) == NULL) return (error)
#define BLOSC_TRACE_ERROR(...) 
#define NDLZ_UNEXPECT_CONDITIONAL(cond) (cond)

typedef struct {
    // Add any necessary fields here
} blosc2_dparams;