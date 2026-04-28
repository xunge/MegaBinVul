#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef unsigned char bfd_byte;
typedef uint64_t bfd_vma;
typedef uint64_t bfd_uint64_t;
typedef size_t bfd_size_type;
typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

struct bfd;
typedef struct bfd bfd;

struct dwarf2_debug {
    bfd_byte *info_ptr;
    bfd *bfd_ptr;
    bfd_byte *sec_info_ptr;
};

struct comp_unit;
struct abbrev_info;
struct attribute;

enum dwarf_unit_type {
    DW_UT_compile,
    DW_UT_type
};

enum {
    DW_AT_stmt_list,
    DW_AT_name,
    DW_AT_low_pc,
    DW_AT_high_pc,
    DW_AT_ranges,
    DW_AT_comp_dir,
    DW_AT_language
};

enum {
    DW_FORM_addr,
    DW_FORM_strp
};

enum {
    DW_TAG_compile_unit
};

struct attribute {
    unsigned int name;
    unsigned int form;
    union {
        bfd_vma val;
        char *str;
    } u;
};

struct abbrev_info {
    unsigned int num_attrs;
    unsigned int tag;
    struct attribute *attrs;
};

struct comp_unit {
    bfd *abfd;
    unsigned int version;
    unsigned int addr_size;
    unsigned int offset_size;
    struct abbrev_info **abbrevs;
    bfd_byte *end_ptr;
    struct dwarf2_debug *stash;
    bfd_byte *info_ptr_unit;
    bfd_byte *sec_info_ptr;
    bfd_vma base_address;
    bfd_vma line_offset;
    char *name;
    char *comp_dir;
    bfd_vma lang;
    bfd_byte *first_child_die_ptr;
    void *arange;
    unsigned int stmtlist;
};

unsigned int read_2_bytes(bfd *abfd, bfd_byte *info_ptr, bfd_byte *end_ptr);
unsigned int read_1_byte(bfd *abfd, bfd_byte *info_ptr, bfd_byte *end_ptr);
bfd_uint64_t read_4_bytes(bfd *abfd, bfd_byte *info_ptr, bfd_byte *end_ptr);
bfd_uint64_t read_8_bytes(bfd *abfd, bfd_byte *info_ptr, bfd_byte *end_ptr);
struct abbrev_info **read_abbrevs(bfd *abfd, bfd_uint64_t abbrev_offset, struct dwarf2_debug *stash);
unsigned int _bfd_safe_read_leb128(bfd *abfd, bfd_byte *info_ptr, unsigned int *bytes_read, bfd_boolean is_signed, bfd_byte *end_ptr);
struct abbrev_info *lookup_abbrev(unsigned int abbrev_number, struct abbrev_info **abbrevs);
bfd_byte *read_attribute(struct attribute *attr, struct attribute *abbrev_attr, struct comp_unit *unit, bfd_byte *info_ptr, bfd_byte *end_ptr);
bfd_boolean is_str_attr(unsigned int form);
bfd_boolean read_rangelist(struct comp_unit *unit, void *arange, bfd_vma val);
bfd_boolean arange_add(struct comp_unit *unit, void *arange, bfd_vma low_pc, bfd_vma high_pc);
void *_bfd_error_handler(const char *fmt, ...);
void bfd_set_error(int error);
#define bfd_error_bad_value 0
void *bfd_zalloc(bfd *abfd, bfd_size_type amt);
#define BFD_ASSERT(cond)
#define _(str) str