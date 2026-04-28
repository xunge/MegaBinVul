#include <assert.h>
#include <algorithm>

#define HB_MAX_CONTEXT_LENGTH 64
#define HB_BUFFER_FLAG_PRODUCE_UNSAFE_TO_CONCAT (1u << 0)

struct hb_glyph_info_t {};
struct matcher_t {
    enum may_skip_t { SKIP_NO, SKIP_YES };
    enum may_match_t { MATCH_NO, MATCH_YES, MATCH_MAYBE };
    may_skip_t may_skip(void*, hb_glyph_info_t&) { return SKIP_NO; }
    may_match_t may_match(hb_glyph_info_t&, void*) { return MATCH_NO; }
};

struct buffer_t {
    unsigned flags;
    hb_glyph_info_t out_info[1];
};

struct context_t {
    buffer_t* buffer;
};

static unsigned num_items;
static unsigned idx;
static context_t* c;
static matcher_t matcher;

static void* get_glyph_data() { return nullptr; }
static void advance_glyph_data() {}

template <typename T>
static T hb_max(T a, T b) { return std::max(a, b); }
#define unlikely(x) (x)