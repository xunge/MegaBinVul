#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

enum ContentEncoding {
  ENCQUOTEDPRINTABLE,
  ENCBASE64
};

struct Buffer {
  char *data;
  size_t size;
  size_t used;
};

static int hexval(char c) {
  if (isdigit(c)) return c - '0';
  if (isxdigit(c)) return toupper(c) - 'A' + 10;
  return -1;
}

static void mutt_buffer_addch(struct Buffer *buf, char c) {
  if (buf->used >= buf->size) {
    buf->size += 256;
    buf->data = realloc(buf->data, buf->size);
  }
  buf->data[buf->used++] = c;
}

static void *mutt_mem_malloc(size_t size) {
  return malloc(size);
}

static int mutt_b64_decode(char *out, const char *in, ...) {
  va_list args;
  va_start(args, in);
  size_t olen = va_arg(args, size_t);
  va_end(args);
  (void)olen;
  return -1;
}

#define FREE(ptr) do { free(*(ptr)); *(ptr) = NULL; } while (0)