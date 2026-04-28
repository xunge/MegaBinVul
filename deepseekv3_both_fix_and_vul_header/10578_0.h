#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define ONIG_DEBUG_SEARCH
#define ONIG_OPTIMIZE_EXACT 1
#define ONIG_OPTIMIZE_EXACT_IC 2
#define ONIG_OPTIMIZE_EXACT_BM 3
#define ONIG_OPTIMIZE_EXACT_BM_NOT_REV 4
#define ONIG_OPTIMIZE_MAP 5
#define ONIG_INFINITE_DISTANCE -1
#define ANCHOR_BEGIN_LINE 1
#define ANCHOR_END_LINE 2
#define USE_NEWLINE_AT_END_OF_STRING_HAS_EMPTY_LINE
#define USE_CRNL_AS_LINE_TERMINATOR

#define ONIGENC_IS_SINGLEBYTE(enc) 1
#define ON_STR_BEGIN(p) ((p) == str)
#define ON_STR_END(p) ((p) >= end)
#define ONIGENC_IS_MBC_NEWLINE(enc,p,end) 0
#define ONIGENC_IS_MBC_CRNL(enc,p,end) 0
#define IS_NULL(p) ((p) == NULL)

static UChar* slow_search(const void* enc, UChar* s, UChar* end, UChar* p, UChar* range_end, UChar* range);
static UChar* slow_search_ic(const void* enc, int case_fold_flag, UChar* s, UChar* end, UChar* p, UChar* range_end, UChar* range);
static UChar* bm_search(regex_t* reg, UChar* target, UChar* target_end, UChar* text, UChar* text_end, UChar* text_range);
static UChar* bm_search_notrev(regex_t* reg, UChar* target, UChar* target_end, UChar* text, UChar* text_end, UChar* text_range);
static UChar* map_search(const void* enc, UChar map[], UChar* text, UChar* text_range);
static int enclen(const void* enc, UChar* p);
static UChar* onigenc_get_prev_char_head(const void* enc, UChar* start, UChar* s);
static UChar* onigenc_get_right_adjust_char_head_with_prev(const void* enc, UChar* start, UChar* s, const UChar** prev);