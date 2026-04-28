#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef int bfd_boolean;
typedef unsigned long bfd_vma;
typedef unsigned char bfd_byte;
typedef size_t bfd_size_type;

typedef struct bfd bfd;
struct comp_unit;
struct abbrev_info;
struct funcinfo;
struct varinfo;
struct attribute;
struct stash;
struct line_info_table;
struct arange;

struct nest_funcinfo {
    struct funcinfo *func;
};

struct comp_unit {
    bfd *abfd;
    bfd_byte *first_child_die_ptr;
    struct stash *stash;
    struct abbrev_info *abbrevs;
    struct funcinfo *function_table;
    unsigned int number_of_functions;
    bfd_boolean cached;
    struct varinfo *variable_table;
    struct line_info_table *line_table;
    unsigned int addr_size;
    int lang;
};

struct abbrev_info {
    unsigned int tag;
    unsigned int num_attrs;
    struct attribute *attrs;
    bfd_boolean has_children;
};

struct funcinfo {
    unsigned int tag;
    struct funcinfo *prev_func;
    struct funcinfo *caller_func;
    char *caller_file;
    unsigned int caller_line;
    char *name;
    bfd_boolean is_linkage;
    bfd_vma low_pc;
    bfd_vma high_pc;
    struct arange *arange;
    char *file;
    unsigned int line;
};

struct varinfo {
    unsigned int tag;
    int stack;
    struct varinfo *prev_var;
    char *name;
    char *file;
    unsigned int line;
    bfd_vma addr;
};

struct attribute {
    unsigned int name;
    unsigned int form;
    union {
        bfd_vma val;
        char *str;
        struct block *blk;
    } u;
};

struct block {
    bfd_byte *data;
    size_t size;
};

struct stash {
    bfd_byte *info_ptr_end;
};

#define DW_TAG_subprogram 0x2e
#define DW_TAG_entry_point 0x3
#define DW_TAG_inlined_subroutine 0x1d
#define DW_TAG_variable 0x34

#define DW_AT_call_file 0x58
#define DW_AT_call_line 0x59
#define DW_AT_abstract_origin 0x31
#define DW_AT_specification 0x47
#define DW_AT_name 0x3
#define DW_AT_linkage_name 0x6e
#define DW_AT_MIPS_linkage_name 0x2007
#define DW_AT_low_pc 0x11
#define DW_AT_high_pc 0x12
#define DW_AT_ranges 0x55
#define DW_AT_decl_file 0x3a
#define DW_AT_decl_line 0x3b
#define DW_AT_external 0x3f
#define DW_AT_location 0x2

#define DW_FORM_addr 0x1
#define DW_FORM_block 0x9
#define DW_FORM_block1 0xa
#define DW_FORM_block2 0x3
#define DW_FORM_block4 0x4
#define DW_FORM_exprloc 0x18

#define DW_OP_addr 0x3
#define DW_OP_GNU_push_tls_address 0xe0

#define FALSE 0
#define TRUE 1

#define BFD_ASSERT(expr) ((void)0)

enum bfd_error {
    bfd_error_bad_value
};

static void *bfd_malloc(bfd_size_type size) { return malloc(size); }
static void *bfd_zalloc(bfd *abfd, bfd_size_type size) { return calloc(1, size); }
static void *bfd_realloc(void *ptr, bfd_size_type size) { return realloc(ptr, size); }
static void bfd_set_error(enum bfd_error error) {}
static void _bfd_error_handler(const char *fmt, ...) {}
static const char *_(const char *str) { return str; }
static unsigned int _bfd_safe_read_leb128(bfd *abfd, bfd_byte *info_ptr, unsigned int *bytes_read, bfd_boolean sign, bfd_byte *end_ptr) { return 0; }
static struct abbrev_info *lookup_abbrev(unsigned int number, struct abbrev_info *abbrevs) { return NULL; }
static char *concat_filename(struct line_info_table *table, bfd_vma val) { return NULL; }
static bfd_boolean find_abstract_instance_name(struct comp_unit *unit, bfd_byte *info_ptr, struct attribute *attr, char **name, bfd_boolean *is_linkage) { return FALSE; }
static bfd_boolean is_str_attr(unsigned int form) { return FALSE; }
static bfd_boolean read_rangelist(struct comp_unit *unit, struct arange **arange, bfd_vma val) { return FALSE; }
static bfd_boolean arange_add(struct comp_unit *unit, struct arange **arange, bfd_vma low_pc, bfd_vma high_pc) { return FALSE; }
static bfd_vma bfd_get(unsigned int bits, bfd *abfd, const void *data) { return 0; }
static bfd_boolean non_mangled(int lang) { return FALSE; }
static bfd_byte *read_attribute(struct attribute *attr, struct attribute *abbrev_attr, struct comp_unit *unit, bfd_byte *info_ptr, bfd_byte *info_ptr_end) { return NULL; }