#include <limits.h>
#include <stddef.h>

#define ISA_DIGIT(c) ((*(c) >= '0') && (*(c) <= '9'))

typedef struct {
    int port;
} xmlURI;

typedef xmlURI* xmlURIPtr;