#include <stdlib.h>

typedef unsigned char UChar;

typedef struct {
    UChar* par;
} OnigErrorInfo;

typedef struct {
    int pattern_enc;
    int target_enc;
    int option;
    int case_fold_flag;
    int syntax;
} OnigCompileInfo;

typedef struct regex_t {
    // dummy definition since actual contents are not used in this snippet
} regex_t;

#define IS_NOT_NULL(ptr) ((ptr) != NULL)
#define IS_NULL(ptr) ((ptr) == NULL)

#define ONIGERR_NOT_SUPPORTED_ENCODING_COMBINATION 1
#define ONIGERR_MEMORY 2

void* xmalloc(size_t size);
void xfree(void* ptr);
int onig_reg_init(regex_t* reg, int option, int case_fold_flag, int enc, int syntax);
int onig_compile(regex_t* reg, const UChar* pattern, const UChar* pattern_end, OnigErrorInfo* einfo);
void onig_free(regex_t* reg);