#include <string.h>
#include <stdlib.h>

typedef unsigned char guint8;
typedef long glong;
typedef unsigned int gunichar;
typedef char gchar;

typedef enum {
  PANGO_DIRECTION_LTR,
  PANGO_DIRECTION_RTL,
  PANGO_DIRECTION_TTB_LTR,
  PANGO_DIRECTION_TTB_RTL,
  PANGO_DIRECTION_WEAK_LTR,
  PANGO_DIRECTION_WEAK_RTL,
  PANGO_DIRECTION_NEUTRAL
} PangoDirection;

typedef enum {
  FRIBIDI_TYPE_RLE,
  FRIBIDI_TYPE_ON,
  FRIBIDI_TYPE_LTR,
  FRIBIDI_TYPE_RTL,
  FRIBIDI_TYPE_AL
} FriBidiCharType;

typedef enum {
  FRIBIDI_PAR_LTR,
  FRIBIDI_PAR_RTL,
  FRIBIDI_PAR_WLTR,
  FRIBIDI_PAR_WRTL
} FriBidiParType;

typedef unsigned int FriBidiBracketType;
typedef guint8 FriBidiLevel;
typedef gunichar FriBidiChar;

#define FRIBIDI_NO_BRACKET 0
#define FRIBIDI_IS_STRONG(x) ((x) == FRIBIDI_TYPE_LTR || (x) == FRIBIDI_TYPE_RTL || (x) == FRIBIDI_TYPE_AL)
#define FRIBIDI_IS_RTL(x) ((x) == FRIBIDI_TYPE_RTL || (x) == FRIBIDI_TYPE_AL)
#define FRIBIDI_IS_ARABIC(x) ((x) == FRIBIDI_TYPE_AL)
#define FRIBIDI_IS_LETTER(x) 0
#define FRIBIDI_IS_NUMBER(x) 0
#define FRIBIDI_IS_WEAK(x) ((x) == FRIBIDI_PAR_WLTR || (x) == FRIBIDI_PAR_WRTL)

#define G_UNLIKELY(expr) (expr)
#define g_new(type, count) ((type*)malloc(sizeof(type)*(count)))
#define g_free(ptr) free(ptr)