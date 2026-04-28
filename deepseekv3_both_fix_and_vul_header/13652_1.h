#include <stdlib.h>
#include <stddef.h>

typedef unsigned char UChar;
typedef unsigned int OnigOptionType;

typedef struct {
    int state;
    UChar* low;
    UChar* high;
    UChar* low_prev;
    UChar* sch_range;
} SearchRange;

typedef struct {
    int n;
    void* enc;
    int all_low_high;
    int anychar_inf;
    struct {
        void* reg;
    } *rs;
} OnigRegSet;

typedef struct {
    int optimize;
    int dist_max;
    int anchor;
} regex_t;

typedef void* OnigEncoding;

typedef struct {
    void* msa;
} MatchArg;

#define INFINITE_LEN 0x7FFFFFFF
#define OPTIMIZE_NONE 0
#define SRS_DEAD 0
#define SRS_LOW_HIGH 1
#define SRS_ALL_RANGE 2
#define ANCR_ANYCHAR_INF 1
#define ONIG_MISMATCH -1

#define CHECK_NULL_RETURN_MEMERR(p) if ((p) == NULL) return ONIG_MISMATCH
#define REGSET_MATCH_AND_RETURN_CHECK(range) \
    r = onig_match(reg, str, end, s, msas[i].msa, option); \
    if (r >= 0) { \
        *rmatch_pos = (int)(s - str); \
        goto match; \
    } \
    else if (r != ONIG_MISMATCH) goto finish

static inline UChar* onigenc_get_prev_char_head(OnigEncoding enc, const UChar* str, const UChar* s) { return NULL; }
static inline int onig_match(regex_t* reg, const UChar* str, const UChar* end, const UChar* s, void* msa, OnigOptionType option) { return 0; }
static inline int forward_search(regex_t* reg, const UChar* str, const UChar* end, const UChar* s, const UChar* sch_range, UChar** low, UChar** high, UChar** low_prev) { return 0; }
static inline int ONIGENC_IS_MBC_NEWLINE(OnigEncoding enc, const UChar* s, const UChar* end) { return 0; }
static inline int enclen(OnigEncoding enc, const UChar* s) { return 1; }
static inline void* xmalloc(size_t size) { return malloc(size); }
static inline void xfree(void* ptr) { free(ptr); }