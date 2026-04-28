#include <stdint.h>

#define SLJIT_FUNC
typedef unsigned char PCRE2_UCHAR;
typedef PCRE2_UCHAR* PCRE2_SPTR;

typedef struct {
    PCRE2_SPTR begin;
    PCRE2_SPTR end;
} jit_arguments;

#define GETCHARINC(c, ptr) (c = *ptr++)
#define UCD_GRAPHBREAK(c) 0
#define PRIV(ucp_gbtable) ((const uint32_t*)0)

enum {
    ucp_gbRegionalIndicator,
    ucp_gbExtend,
    ucp_gbZWJ,
    ucp_gbExtended_Pictographic
};