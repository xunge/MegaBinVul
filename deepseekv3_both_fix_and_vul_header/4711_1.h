#include <stdlib.h>
#include <string.h>

typedef struct _xmlBuffer xmlBuffer;
typedef xmlBuffer *xmlBufferPtr;

typedef struct _xsltNumberData xsltNumberData;
typedef xsltNumberData *xsltNumberDataPtr;

struct _xsltNumberData {
    int digitsPerGroup;
    char *groupingCharacter;
    int groupingCharacterLen;
};

void xmlBufferCCat(xmlBufferPtr buffer, const char *str);
void xsltNumberFormatDecimal(xmlBufferPtr buffer, double number, char zero, int digit_zero,
                            int digitsPerGroup, char *groupingCharacter, int groupingCharacterLen);