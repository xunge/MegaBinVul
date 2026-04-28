#include <stdint.h>
#include <string.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

extern uint32_t ReadWebPLSBWord(const unsigned char *);
typedef ssize_t;