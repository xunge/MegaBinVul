#include <stddef.h>
#include <stdint.h>

typedef uint32_t OFF;
typedef int BOOL;
#define FALSE 0
#define TRUE 1

typedef struct MD_CTX {
    OFF size;
    OFF code_indent_offset;
    int n_containers;
    struct MD_CONTAINER* containers;
    BOOL last_line_has_list_loosening_effect;
    BOOL last_list_item_starts_with_two_blank_lines;
    void* block_bytes;
    size_t n_block_bytes;
    struct MD_BLOCK* current_block;
    struct {
        unsigned flags;
    } r;
    int html_block_type;
} MD_CTX;

typedef struct MD_LINE_ANALYSIS {
    int type;
    OFF beg;
    OFF end;
    unsigned indent;
    unsigned data;
} MD_LINE_ANALYSIS;

typedef struct MD_CONTAINER {
    char ch;
    unsigned mark_indent;
    unsigned contents_indent;
    unsigned start;
    size_t block_byte_off;
} MD_CONTAINER;

typedef struct MD_BLOCK {
    int type;
    unsigned flags;
    size_t n_lines;
} MD_BLOCK;

static const MD_LINE_ANALYSIS md_dummy_blank_line = {0};

#define MD_BLOCK_LI 0
#define MD_BLOCK_LOOSE_LIST (1 << 0)
#define MD_BLOCK_CONTAINER_CLOSER (1 << 1)
#define MD_BLOCK_CONTAINER_OPENER (1 << 2)

enum {
    MD_LINE_BLANK,
    MD_LINE_FENCEDCODE,
    MD_LINE_HTML,
    MD_LINE_INDENTEDCODE,
    MD_LINE_SETEXTUNDERLINE,
    MD_LINE_HR,
    MD_LINE_TABLE,
    MD_LINE_TABLEUNDERLINE,
    MD_LINE_ATXHEADER,
    MD_LINE_TEXT
};

#define MD_FLAG_NOHTMLBLOCKS (1 << 0)
#define MD_FLAG_TABLES (1 << 1)
#define MD_FLAG_PERMISSIVEATXHEADERS (1 << 2)

#define _T(c) c
#define CH(off) 0
#define ISNEWLINE(off) 0
#define ISANYOF(off, s) 0
#define MD_ASSERT(expr) ((void)0)
#define MD_CHECK(expr) do { if((expr) < 0) return -1; } while(0)

static int md_line_indentation(MD_CTX* ctx, unsigned total_indent, OFF off, OFF* p_off) { return 0; }
static BOOL md_is_closing_code_fence(MD_CTX* ctx, int ch, OFF off, OFF* p_off) { return FALSE; }
static BOOL md_is_html_block_end_condition(MD_CTX* ctx, OFF off, OFF* p_off) { return FALSE; }
static BOOL md_is_setext_underline(MD_CTX* ctx, OFF off, OFF* p_off, unsigned* level) { return FALSE; }
static BOOL md_is_hr_line(MD_CTX* ctx, OFF off, OFF* p_off) { return FALSE; }
static BOOL md_is_table_row(MD_CTX* ctx, OFF off, OFF* p_off) { return FALSE; }
static BOOL md_is_container_mark(MD_CTX* ctx, int indent, OFF off, OFF* p_off, MD_CONTAINER* container) { return FALSE; }
static BOOL md_is_container_compatible(MD_CONTAINER* c1, MD_CONTAINER* c2) { return FALSE; }
static BOOL md_is_opening_code_fence(MD_CTX* ctx, OFF off, OFF* p_off) { return FALSE; }
static int md_is_html_block_start_condition(MD_CTX* ctx, OFF off) { return 0; }
static BOOL md_is_table_underline(MD_CTX* ctx, OFF off, OFF* p_off, unsigned* col_count) { return FALSE; }
static int md_leave_child_containers(MD_CTX* ctx, int n) { return 0; }
static int md_push_container(MD_CTX* ctx, MD_CONTAINER* container) { return 0; }
static int md_push_container_bytes(MD_CTX* ctx, int type, int flags, int data, int container_flags) { return 0; }
static int md_enter_child_containers(MD_CTX* ctx, int n, int data) { return 0; }
static BOOL md_is_atxheader_line(MD_CTX* ctx, OFF off, OFF* p_beg, OFF* p_off, unsigned* level) { return FALSE; }