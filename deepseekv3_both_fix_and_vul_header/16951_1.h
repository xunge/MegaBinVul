#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define DW_TAG_subprogram 0x2e
#define DW_TAG_entry_point 0x03
#define DW_TAG_inlined_subroutine 0x1d
#define DW_TAG_variable 0x34
#define DW_TAG_member 0x0d

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

#define DW_FORM_addr 0x01
#define DW_FORM_block 0x09
#define DW_FORM_block1 0x0a
#define DW_FORM_block2 0x0b
#define DW_FORM_block4 0x0c
#define DW_FORM_exprloc 0x18

#define DW_OP_addr 0x03

#define bfd_error_bad_value 1

struct bfd;
typedef struct bfd bfd;
typedef unsigned char bfd_byte;
typedef uint64_t bfd_vma;

struct comp_unit {
    bfd *abfd;
    bfd_byte *first_child_die_ptr;
    bfd_byte *end_ptr;
    bfd_byte *info_ptr_unit;
    void *abbrevs;
    struct funcinfo *function_table;
    unsigned int number_of_functions;
    bool cached;
    struct varinfo *variable_table;
    void *line_table;
    int lang;
    unsigned int addr_size;
    struct {
        void *trie_root;
    } *file;
};

struct funcinfo {
    unsigned int tag;
    struct funcinfo *prev_func;
    uint64_t unit_offset;
    struct funcinfo *caller_func;
    const char *name;
    bool is_linkage;
    const char *file;
    uint64_t line;
    const char *caller_file;
    uint64_t caller_line;
    void *arange;
};

struct varinfo {
    unsigned int tag;
    struct varinfo *prev_var;
    uint64_t unit_offset;
    bool stack;
    const char *name;
    const char *file;
    uint64_t line;
    bfd_vma addr;
};

struct abbrev_info {
    unsigned int tag;
    unsigned int num_attrs;
    struct attribute *attrs;
    bool has_children;
};

struct attribute {
    unsigned int name;
    unsigned int form;
    union {
        const char *str;
        uint64_t val;
        struct {
            unsigned int size;
            bfd_byte *data;
        } *blk;
    } u;
};

struct nest_funcinfo {
    struct funcinfo *func;
};

extern void *bfd_malloc(size_t);
extern void *bfd_zalloc(bfd *, size_t);
extern void *bfd_realloc(void *, size_t);
extern void bfd_set_error(int);
extern uint64_t bfd_get(unsigned int, bfd *, const bfd_byte *);
extern unsigned int _bfd_safe_read_leb128(bfd *, bfd_byte **, bool, bfd_byte *);
extern void _bfd_error_handler(const char *, ...);
extern struct abbrev_info *lookup_abbrev(unsigned int, void *);
extern bfd_byte *read_attribute(struct attribute *, struct attribute *, struct comp_unit *, bfd_byte *, bfd_byte *);
extern bool is_int_form(struct attribute *);
extern bool is_str_form(struct attribute *);
extern const char *concat_filename(void *, uint64_t);
extern bool find_abstract_instance(struct comp_unit *, struct attribute *, int, const char **, bool *, const char **, uint64_t *);
extern unsigned int mangle_style(int);
extern bool read_rangelist(struct comp_unit *, void **, void *, uint64_t);
extern bool arange_add(struct comp_unit *, void **, void *, bfd_vma, bfd_vma);
extern struct funcinfo *reverse_funcinfo_list(struct funcinfo *);
extern struct varinfo *reverse_varinfo_list(struct varinfo *);
extern struct funcinfo *lookup_func_by_offset(uint64_t, struct funcinfo *);
extern struct varinfo *lookup_var_by_offset(uint64_t, struct varinfo *);
#define BFD_ASSERT(x) ((void)0)
#define _(x) x