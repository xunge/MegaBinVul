#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

extern uint32_t ReadWebPLSBWord(const unsigned char *);