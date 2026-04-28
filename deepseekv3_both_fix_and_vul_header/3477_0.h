#include <ctype.h>

#define MAXDATEFIELDS 32

enum
{
    DTK_NUMBER,
    DTK_TIME,
    DTK_DATE,
    DTK_STRING,
    DTK_TZ,
    DTK_SPECIAL
};

static inline unsigned char pg_tolower(unsigned char ch)
{
    return tolower(ch);
}