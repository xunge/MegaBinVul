#include <stddef.h>

typedef unsigned char UChar;

#define ONIGENC_MBC_CASE_FOLD_MAXLEN 16

typedef void* OnigEncoding;

int ONIGENC_MBC_CASE_FOLD(OnigEncoding enc, int case_fold_flag,
                         const UChar** p, const UChar* end, UChar* lower);