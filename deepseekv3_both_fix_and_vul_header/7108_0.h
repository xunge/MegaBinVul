#include <stdio.h>
#include <unistd.h>

typedef struct _pdfio_token_s _pdfio_token_t;

struct _pdfio_token_s {
  unsigned char *buffer;
  unsigned char *bufptr;
  unsigned char *bufend;
  void (*consume_cb)(void *, size_t);
  ssize_t (*peek_cb)(void *, void *, size_t);
  void *cb_data;
};

#define PDFIO_DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define DEBUG 1