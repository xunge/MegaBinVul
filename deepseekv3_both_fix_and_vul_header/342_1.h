#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned char xmlChar;
typedef struct _xmlBuffer xmlBuffer;
typedef xmlBuffer *xmlBufferPtr;

#define SYMBOL_QUOTE '\''
#define BAD_CAST (xmlChar *)
#define FALSE 0
#define TRUE 1
#define XPATH_EXPRESSION_OK 0
#define XPATH_MEMORY_ERROR 1

typedef struct _xsltDecimalFormat {
    xmlChar *digit;
    xmlChar *zeroDigit;
    xmlChar *decimalPoint;
    xmlChar *grouping;
    xmlChar *patternSeparator;
    xmlChar *percent;
    xmlChar *permille;
    xmlChar *minusSign;
    xmlChar *infinity;
    xmlChar *noNumber;
} xsltDecimalFormat;
typedef xsltDecimalFormat *xsltDecimalFormatPtr;

typedef struct {
    int integer_hash;
    int integer_digits;
    int frac_digits;
    int frac_hash;
    int group;
    int multiplier;
    int add_decimal;
    int is_multiplier_set;
    int is_negative_pattern;
} xsltFormatNumberInfo;

typedef int xmlXPathError;