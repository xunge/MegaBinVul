#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef int bfd_boolean;
typedef unsigned char bfd_byte;
typedef uint64_t bfd_vma;
typedef size_t bfd_size_type;

struct bfd {
    /* BFD object placeholder */
};

typedef struct bfd bfd;

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
    unsigned int lang;
};

struct stash {
    bfd_byte *info_ptr_end;
};

struct abbrev_info {
    unsigned int tag;
    unsigned int num_attrs;
    struct abbrev_attr *attrs;
    bfd_boolean has_children;
};

struct abbrev_attr {
    unsigned int name;
    unsigned int form;
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
    bfd_boolean stack;
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

struct arange;
struct line_info_table;

enum bfd_error {
    bfd_error_bad_value
};

unsigned int _bfd_safe_read_leb128(bfd *, bfd_byte *, unsigned int *, bfd_boolean, bfd_byte *);
struct abbrev_info *lookup_abbrev(unsigned int, struct abbrev_info *);
void _bfd_error_handler(const char *, ...);
const char *_(const char *);
void bfd_set_error(enum bfd_error);
void *bfd_malloc(bfd_size_type);
void *bfd_zalloc(bfd *, bfd_size_type);
void *bfd_realloc(void *, bfd_size_type);
char *concat_filename(struct line_info_table *, bfd_vma);
char *find_abstract_instance_name(struct comp_unit *, struct attribute *, bfd_boolean *);
bfd_boolean is_str_attr(unsigned int);
bfd_boolean read_rangelist(struct comp_unit *, struct arange **, bfd_vma);
bfd_boolean arange_add(struct comp_unit *, struct arange **, bfd_vma, bfd_vma);
bfd_vma bfd_get(unsigned int, bfd *, bfd_byte *);
bfd_boolean non_mangled(unsigned int);
bfd_byte *read_attribute(struct attribute *, struct abbrev_attr *, struct comp_unit *, bfd_byte *, bfd_byte *);

#define BFD_ASSERT(expr) ((void)0)
#define FALSE 0
#define TRUE 1
#define DW_TAG_subprogram 0x2e
#define DW_TAG_entry_point 0x03
#define DW_TAG_inlined_subroutine 0x1d
#define DW_TAG_variable 0x34
#define DW_AT_call_file 0x58
#define DW_AT_call_line 0x59
#define DW_AT_abstract_origin 0x31
#define DW_AT_specification 0x47
#define DW_AT_name 0x03
#define DW_AT_linkage_name 0x6e
#define DW_AT_MIPS_linkage_name 0x2007
#define DW_AT_low_pc 0x11
#define DW_AT_high_pc 0x12
#define DW_AT_ranges 0x55
#define DW_AT_decl_file 0x3a
#define DW_AT_decl_line 0x3b
#define DW_AT_external 0x3f
#define DW_AT_location 0x02
#define DW_FORM_block 0x09
#define DW_FORM_block1 0x0a
#define DW_FORM_block2 0x0b
#define DW_FORM_block4 0x0c
#define DW_FORM_exprloc 0x18
#define DW_FORM_addr 0x01
#define DW_OP_addr 0x03
#define DW_OP_GNU_push_tls_address 0xe0