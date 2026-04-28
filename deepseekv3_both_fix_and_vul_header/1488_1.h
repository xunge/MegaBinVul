#include <stdlib.h>
#include <stdbool.h>

typedef int FriBidiStrIndex;
typedef unsigned int FriBidiChar;
typedef unsigned char FriBidiLevel;
typedef bool fribidi_boolean;

#define FRIBIDI_ENTRY
#define UNLIKELY(x) (x)
#define DBG(x)
#define FRIBIDI_IS_EXPLICIT_OR_BN(x) 0
#define FRIBIDI_IS_ISOLATE(x) 0
#define FRIBIDI_CHAR_LRM 0
#define FRIBIDI_CHAR_RLM 0

extern FriBidiChar fribidi_get_bidi_type(FriBidiChar c);
extern void fribidi_assert(const void *);
extern void *fribidi_malloc(size_t size);
extern void fribidi_free(void *ptr);