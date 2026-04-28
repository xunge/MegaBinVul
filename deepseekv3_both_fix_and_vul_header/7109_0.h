#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct _pdfio_token_s _pdfio_token_t;
typedef struct _pdfio_file_s _pdfio_file_t;

struct _pdfio_token_s {
    _pdfio_file_t *pdf;
    int bufptr;
};

struct _pdfio_file_s {
    // Add necessary fields here
};

#define PDFIO_DELIM_CHARS "()<>[]{}/%"
#define PDFIO_NUMBER_CHARS "+-0123456789."
#define PDFIO_DEBUG(fmt, ...) 

int get_char(_pdfio_token_t *tb);
void _pdfioFileError(_pdfio_file_t *pdf, const char *fmt, ...);