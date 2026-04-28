#include <stddef.h>

typedef int FriBidiStrIndex;
typedef unsigned int FriBidiChar;

#define FRIBIDI_CHAR_LRM 0x200E
#define FRIBIDI_CHAR_RLM 0x200F
#define FRIBIDI_CHAR_LRE 0x202A
#define FRIBIDI_CHAR_RLE 0x202B
#define FRIBIDI_CHAR_PDF 0x202C
#define FRIBIDI_CHAR_LRO 0x202D
#define FRIBIDI_CHAR_RLO 0x202E
#define FRIBIDI_CHAR_LRI 0x2066
#define FRIBIDI_CHAR_RLI 0x2067
#define FRIBIDI_CHAR_FSI 0x2068
#define FRIBIDI_CHAR_PDI 0x2069

extern FriBidiChar *caprtl_to_unicode;
void init_cap_rtl(void);