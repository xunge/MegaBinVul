#include <stdint.h>

typedef uint32_t IOEventFlags;
#define EV_NONE 0

typedef struct {
  char str[4];
} JsVarData;

typedef struct {
  JsVarData varData;
} JsVar;