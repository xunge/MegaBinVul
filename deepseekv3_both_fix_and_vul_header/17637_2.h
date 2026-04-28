#include <stdint.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef uint16_t UINT16;
typedef struct _wStream wStream;
typedef struct _rdpSettings rdpSettings;

#define WINPR_UNUSED(x) ((void)(x))

static void Stream_Seek_UINT16(wStream* s);