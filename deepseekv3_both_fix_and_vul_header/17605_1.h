#include <stdbool.h>

typedef struct rdpUpdate rdpUpdate;
typedef struct wStream wStream;

#define WINPR_UNUSED(x) (void)(x)
#define BOOL bool

static int Stream_SafeSeek(wStream* s, int offset);