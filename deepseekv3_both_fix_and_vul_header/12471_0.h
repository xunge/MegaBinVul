#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef intptr_t OFF;
typedef uint32_t BOOL;
#define TRUE 1
#define FALSE 0

typedef struct MD_CTX MD_CTX;
typedef struct MD_LINE_ANALYSIS MD_LINE_ANALYSIS;
typedef struct MD_CONTAINER MD_CONTAINER;
typedef struct MD_BLOCK MD_BLOCK;
typedef struct MD_PARSER MD_PARSER;

#define MD_BLOCK_LOOSE_LIST (1 << 0)
#define MD_BLOCK_LI 1
#define MD_BLOCK_CONTAINER_OPENER 1
#define MD_BLOCK_CONTAINER_CLOSER 2

#define MD_FLAG_NOHTMLBLOCKS (1 << 0)
#define MD_FLAG_TABLES (1 << 1)
#define MD_FLAG_TASKLISTS (1 << 2)
#define MD_FLAG_PERMISSIVEATXHEADERS (1 << 3)

enum {
    MD_LINE_BLANK,
    MD_LINE_INDENTEDCODE,
    MD_LINE_FENCEDCODE,
    MD_LINE_HTML,
    MD_LINE_TEXT,
    MD_LINE_SETEXTUNDERLINE,
    MD_LINE_HR,
    MD_LINE_ATXHEADER,
    MD_LINE_TABLE,
    MD_LINE_TABLEUNDERLINE
};

struct MD_LINE_ANALYSIS {
    int type;
    OFF beg;
    OFF end;
    unsigned indent;
    unsigned data;
};

struct MD_CONTAINER {
    int ch;
    unsigned mark_indent;
    unsigned contents_indent;
    BOOL is_task;
    OFF task_mark_off;
    OFF block_byte_off;
    int start;
};

struct MD_BLOCK {
    int type;
    unsigned flags;
    int n_lines;
};

struct MD_PARSER {
    unsigned flags;
};

struct MD_CTX {
    const char* text;
    OFF size;
    BOOL doc_ends_with_newline;
    MD_PARSER parser;
    MD_CONTAINER* containers;
    int n_containers;
    unsigned code_indent_offset;
    BOOL last_line_has_list_loosening_effect;
    BOOL last_list_item_starts_with_two_blank_lines;
    MD_BLOCK* current_block;
    char* block_bytes;
    int n_block_bytes;
    int html_block_type;
};

#define CH(off) ctx->text[off]
#define ISNEWLINE(off) (CH(off) == '\n' || CH(off) == '\r')
#define ISBLANK(off) (CH(off) == ' ' || CH(off) == '\t')
#define ISWHITESPACE(off) (ISBLANK(off) || ISNEWLINE(off))
#define ISANYOF(off, chars) (strchr(chars, CH(off)) != NULL)
#define ISANYOF_(ch, chars) (strchr(chars, ch) != NULL)
#define STR(off) (ctx->text + off)

static const MD_LINE_ANALYSIS md_dummy_blank_line = { MD_LINE_BLANK, 0, 0, 0, 0 };

static int md_line_indentation(MD_CTX* ctx, unsigned total_indent, OFF off, OFF* p_off);
static BOOL md_is_closing_code_fence(MD_CTX* ctx, int ch, OFF off, OFF* p_off);
static int md_is_html_block_end_condition(MD_CTX* ctx, OFF off, OFF* p_off);
static BOOL md_is_setext_underline(MD_CTX* ctx, OFF off, OFF* p_off, unsigned* p_level);
static BOOL md_is_hr_line(MD_CTX* ctx, OFF off, OFF* p_off, OFF* p_hr_killer);
static BOOL md_is_container_mark(MD_CTX* ctx, unsigned indent, OFF off, OFF* p_off, MD_CONTAINER* p_container);
static BOOL md_is_container_compatible(const MD_CONTAINER* a, const MD_CONTAINER* b);
static int md_leave_child_containers(MD_CTX* ctx, int n_parents);
static int md_push_container(MD_CTX* ctx, const MD_CONTAINER* container);
static int md_push_container_bytes(MD_CTX* ctx, int type, OFF off, int ch, int opener_closer);
static int md_enter_child_containers(MD_CTX* ctx, int n_children);
static BOOL md_is_atxheader_line(MD_CTX* ctx, OFF off, OFF* p_beg, OFF* p_off, unsigned* p_level);
static BOOL md_is_opening_code_fence(MD_CTX* ctx, OFF off, OFF* p_off);
static int md_is_html_block_start_condition(MD_CTX* ctx, OFF off);
static BOOL md_is_table_underline(MD_CTX* ctx, OFF off, OFF* p_off, unsigned* p_col_count);

#define MD_ASSERT(expr) ((void)0)
#define MD_CHECK(expr) do { ret = (expr); if(ret != 0) goto abort; } while(0)