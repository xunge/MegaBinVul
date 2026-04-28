#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pdfio_token_s {
    size_t num_tokens;
    char **tokens;
} _pdfio_token_t;

bool _pdfioTokenRead(_pdfio_token_t *tb, char *buffer, size_t bufsize);

#define PDFIO_DEBUG(fmt, ...)