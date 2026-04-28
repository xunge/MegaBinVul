#include <cstdint>
#include <string>

#define ONIG_MAX_ERROR_MESSAGE_LEN 256
#define CopyString 1

typedef int OnigOptionType;
typedef unsigned char OnigUChar;

struct OnigRegion {
    int num_regs;
    int* beg;
    int* end;
};

struct OnigSyntaxType {};
struct mbfl_encoding {
    const char* name;
};
struct php_mb_regex_t {};

class String {
public:
    String() = default;
    String(const char*, size_t, int);
    const char* data() const;
    size_t size() const;
    bool empty() const;
    String toString() const;
    char toByte() const;
};

class Variant {
public:
    Variant() = default;
    Variant(bool);
    bool isString() const;
    String toString() const;
    char toByte() const;
};

class StringBuffer {
public:
    void append(const char*, size_t);
    Variant detach();
};

static OnigOptionType MBSTRG_regex_default_options = 0;
static OnigSyntaxType* MBSTRG_regex_default_syntax = nullptr;
static int MBSTRG_current_mbctype = 0;

#define MBSTRG(variable) MBSTRG_##variable

const char* php_mb_regex_mbctype2name(int mbctype);
const mbfl_encoding* mbfl_name2encoding(const char* name);
void _php_mb_regex_init_options(const char* option, size_t size, OnigOptionType* options, OnigSyntaxType** syntax, int* eval);
php_mb_regex_t* php_mbregex_compile_pattern(const String& pattern, OnigOptionType options, int mbctype, OnigSyntaxType* syntax);
int onig_search(php_mb_regex_t* reg, const OnigUChar* str, const OnigUChar* end, const OnigUChar* at, const OnigUChar* range, OnigRegion* region, OnigOptionType option);
OnigRegion* onig_region_new();
void onig_region_free(OnigRegion* region, int free_self);
void onig_error_code_to_str(OnigUChar* err_str, int err);
int php_mb_mbchar_bytes_ex(const char* p, const mbfl_encoding* enc);
void raise_warning(const char* format, ...);
void throw_not_supported(const char* func, const char* feature);