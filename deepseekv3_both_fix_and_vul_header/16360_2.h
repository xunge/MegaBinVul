#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char bfd_byte;
typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

typedef unsigned long bfd_vma;
typedef unsigned long long bfd_uint64_t;

struct bfd;
typedef struct bfd bfd;

struct arange {
    bfd_vma low;
    bfd_vma high;
    struct arange *next;
};

struct line_info_table;

struct comp_unit {
    bfd *abfd;
    bfd_byte *first_child_die_ptr;
    bfd_byte *end_ptr;
    bfd_byte *info_ptr_unit;
    struct abbrev_info *abbrevs;
    struct funcinfo *function_table;
    unsigned int number_of_functions;
    bfd_boolean cached;
    struct varinfo *variable_table;
    struct line_info_table *line_table;
    unsigned int addr_size;
    unsigned int lang;
};

struct funcinfo {
    unsigned int tag;
    struct funcinfo *prev_func;
    struct funcinfo *caller_func;
    char *name;
    bfd_boolean is_linkage;
    char *file;
    unsigned int line;
    char *caller_file;
    unsigned int caller_line;
    struct arange arange;
};

struct varinfo {
    unsigned int tag;
    bfd_boolean stack;
    struct varinfo *prev_var;
    bfd_vma unit_offset;
    char *name;
    char *file;
    unsigned int line;
    void *sec;
    bfd_vma addr;
};

struct abbrev_info {
    unsigned int tag;
    unsigned int num_attrs;
    struct attribute *attrs;
    bfd_boolean has_children;
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

struct nest_funcinfo {
    struct funcinfo *func;
};

struct block {
    unsigned char *data;
    size_t size;
};

enum dwarf_tags {
    DW_TAG_subprogram,
    DW_TAG_entry_point,
    DW_TAG_inlined_subroutine,
    DW_TAG_variable
};

enum dwarf_attributes {
    DW_AT_call_file,
    DW_AT_call_line,
    DW_AT_abstract_origin,
    DW_AT_specification,
    DW_AT_name,
    DW_AT_linkage_name,
    DW_AT_MIPS_linkage_name,
    DW_AT_low_pc,
    DW_AT_high_pc,
    DW_AT_ranges,
    DW_AT_decl_file,
    DW_AT_decl_line,
    DW_AT_external,
    DW_AT_location
};

enum dwarf_forms {
    DW_FORM_addr,
    DW_FORM_block,
    DW_FORM_block1,
    DW_FORM_block2,
    DW_FORM_block4,
    DW_FORM_exprloc
};

enum dwarf_ops {
    DW_OP_addr
};

enum bfd_error {
    bfd_error_bad_value
};

static unsigned int _bfd_safe_read_leb128(bfd *abfd, bfd_byte *info_ptr, 
                                        unsigned int *bytes_read, bfd_boolean sign, 
                                        bfd_byte *info_ptr_end) {
    return 0;
}

static struct abbrev_info *lookup_abbrev(unsigned int number, struct abbrev_info *abbrevs) {
    return NULL;
}

static bfd_byte *read_attribute(struct attribute *attr, struct attribute *abbrev_attr,
                               struct comp_unit *unit, bfd_byte *info_ptr,
                               bfd_byte *info_ptr_end) {
    return NULL;
}

static char *concat_filename(struct line_info_table *table, bfd_vma val) {
    return NULL;
}

static bfd_boolean find_abstract_instance(struct comp_unit *unit, struct attribute *attr,
                                        bfd_boolean flag, char **name,
                                        bfd_boolean *is_linkage, char **file,
                                        unsigned int *line) {
    return FALSE;
}

static bfd_boolean is_str_attr(unsigned int form) {
    return FALSE;
}

static bfd_boolean non_mangled(unsigned int lang) {
    return FALSE;
}

static bfd_boolean read_rangelist(struct comp_unit *unit, struct arange *arange, 
                                 bfd_vma val) {
    return FALSE;
}

static struct varinfo *lookup_var_by_offset(bfd_vma offset, struct varinfo *table) {
    return NULL;
}

static bfd_vma bfd_get(unsigned int bits, bfd *abfd, const void *data) {
    return 0;
}

static bfd_boolean arange_add(struct comp_unit *unit, struct arange *arange,
                             bfd_vma low_pc, bfd_vma high_pc) {
    return FALSE;
}

#define BFD_ASSERT(x) ((void)0)
#define _bfd_error_handler(...) ((void)0)
#define bfd_set_error(x) ((void)0)

static void *bfd_malloc(size_t size) { return malloc(size); }
static void *bfd_zalloc(bfd *abfd, size_t size) { (void)abfd; return calloc(1, size); }
static void *bfd_realloc(void *ptr, size_t size) { return realloc(ptr, size); }