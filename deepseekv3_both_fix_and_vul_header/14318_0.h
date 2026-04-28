#include <stdio.h>
#include <stdlib.h>

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_CODING
} GF_LogLevel;

typedef enum {
    GF_NON_COMPLIANT_BITSTREAM
} GF_Error;

typedef struct {
    GF_Error last_error;
} GF_LASeRCodec;

void GF_LOG(GF_LogLevel level, GF_LogLevel subsystem, const char* message);