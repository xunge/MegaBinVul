#include <stddef.h>

typedef unsigned char UChar;

typedef struct OnigEncodingType {
    int dummy;
} OnigEncodingType;
typedef OnigEncodingType* OnigEncoding;

#define ONIGENC_MBC_CASE_FOLD_MAXLEN 6
#define ONIGENC_MBC_CASE_FOLD(enc, flag, pp, end, buf) 0