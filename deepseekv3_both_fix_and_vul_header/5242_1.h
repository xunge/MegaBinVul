#include <ctype.h>
#include <locale.h>
#include <stdio.h>

#define MagickExport

#if defined(MAGICKCORE_LOCALE_SUPPORT)
extern locale_t c_locale;
#endif