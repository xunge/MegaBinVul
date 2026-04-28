#include <stdio.h>
#include <stddef.h>

typedef unsigned char UChar;

typedef struct {
    int dmin;
    int dmax;
    int optimize;
    UChar* exact;
    UChar* exact_end;
    int case_fold_flag;
    const void* enc;
    int sub_anchor;
    UChar map[256];
} regex_t;

enum {
    ONIG_OPTIMIZE_EXACT,
    ONIG_OPTIMIZE_EXACT_IC,
    ONIG_OPTIMIZE_EXACT_BM,
    ONIG_OPTIMIZE_EXACT_BM_NOT_REV,
    ONIG_OPTIMIZE_MAP
};

enum {
    ANCHOR_BEGIN_LINE = 1,
    ANCHOR_END_LINE = 2
};

#define ONIG_INFINITE_DISTANCE -1
#define ONIG_DEBUG_SEARCH
#define ONIGENC_IS_SINGLEBYTE(enc) 1
#define ON_STR_BEGIN(p) ((p) == str)
#define ON_STR_END(p) ((p) >= end)
#define ONIGENC_IS_MBC_NEWLINE(enc,p,end) 0
#define ONIGENC_IS_MBC_CRNL(enc,p,end) 0
#define IS_NULL(p) ((p) == NULL)

static int enclen(const void* enc, const UChar* p);
static UChar* slow_search(const void* enc, const UChar* exact, const UChar* exact_end, const UChar* p, const UChar* end, UChar* range);
static UChar* slow_search_ic(const void* enc, int case_fold_flag, const UChar* exact, const UChar* exact_end, const UChar* p, const UChar* end, UChar* range);
static UChar* bm_search(regex_t* reg, const UChar* exact, const UChar* exact_end, const UChar* p, const UChar* end, UChar* range);
static UChar* bm_search_notrev(regex_t* reg, const UChar* exact, const UChar* exact_end, const UChar* p, const UChar* end, UChar* range);
static UChar* map_search(const void* enc, const UChar* map, const UChar* p, UChar* range);
static UChar* onigenc_get_prev_char_head(const void* enc, const UChar* str, const UChar* p);
static UChar* onigenc_get_right_adjust_char_head_with_prev(const void* enc, const UChar* start, const UChar* s, const UChar** prev);