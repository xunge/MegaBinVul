#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct _pdfio_file_s pdfio_file_t;
struct _pdfio_file_s {
  unsigned char *bufptr;
  unsigned char *bufend;
};

extern int _pdfioFileSeek(pdfio_file_t *pdf, off_t offset, int whence);
#define PDFIO_DEBUG(...)