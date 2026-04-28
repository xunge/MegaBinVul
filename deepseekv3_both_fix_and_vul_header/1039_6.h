#include <stdint.h>
#include <stdlib.h>

typedef void* yyscan_t;

typedef struct YR_ARENA_REF {
    uint32_t offset;
    void* arena;
} YR_ARENA_REF;

typedef struct YR_FIXUP {
    YR_ARENA_REF ref;
    struct YR_FIXUP* next;
} YR_FIXUP;

typedef struct YR_STRING {
    char* identifier;
    struct YR_STRING* chained_to;
} YR_STRING;

typedef struct YR_COMPILER {
    void* arena;
    YR_FIXUP* fixup_stack_head;
    uint32_t current_rule_idx;
} YR_COMPILER;

typedef struct YR_RULE {
    char* identifier;
    uint32_t num_atoms;
} YR_RULE;

#define YR_CONFIG_MAX_STRINGS_PER_RULE 0
#define YR_ATOMS_PER_RULE_WARNING_THRESHOLD 0
#define ERROR_UNREFERENCED_STRING 0
#define ERROR_TOO_MANY_STRINGS 0
#define ERROR_SUCCESS 0
#define OP_MATCH_RULE 0
#define YR_CODE_SECTION 0

#define STRING_IS_REFERENCED(s) 0
#define FAIL_ON_ERROR(x) do { int _err = (x); if (_err != 0) return _err; } while(0)
#define yr_rule_strings_foreach(rule, string) for(string = NULL; string != NULL; string = NULL)

void yr_get_configuration_uint32(int, uint32_t*);
void yr_get_configuration(int, void*);
void* yyget_extra(yyscan_t);
void* yr_arena_ref_to_ptr(void*, YR_ARENA_REF*);
void yywarning(yyscan_t, const char*);
int yr_compiler_set_error_extra_info(YR_COMPILER*, const char*);
int yr_parser_emit_with_arg(yyscan_t, int, uint32_t, void*, void*);
uint32_t yr_arena_get_current_offset(void*, int);
void yr_free(void*);

#define yr_compiler_set_error_extra_info(c, i) { return ERROR_UNREFERENCED_STRING; }