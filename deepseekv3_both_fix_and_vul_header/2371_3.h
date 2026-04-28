#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef uint64_t bfd_uint64_t;
typedef unsigned char bfd_byte;
typedef enum { FALSE, TRUE } bfd_boolean;

struct bfd {
    /* Minimal bfd structure definition */
    int dummy;
};

typedef struct bfd bfd;

struct attribute {
    unsigned int name;
    unsigned int form;
    union {
        const char *str;
        bfd_uint64_t val;
    } u;
};

struct abbrev_info {
    unsigned int num_attrs;
    struct attribute *attrs;
};

struct dwarf2_debug {
    bfd_byte *info_ptr_memory;
    bfd_byte *info_ptr_end;
    bfd_byte *alt_dwarf_info_buffer;
    size_t alt_dwarf_info_size;
};

struct comp_unit {
    bfd *abfd;
    struct dwarf2_debug *stash;
    bfd_byte *info_ptr_unit;
    bfd_byte *end_ptr;
    bfd_byte *sec_info_ptr;
    struct comp_unit *prev_unit;
    struct comp_unit *next_unit;
    struct abbrev_info *abbrevs;
    unsigned int lang;
};

enum {
    DW_FORM_ref_addr,
    DW_FORM_GNU_ref_alt,
    DW_AT_name,
    DW_AT_specification,
    DW_AT_linkage_name,
    DW_AT_MIPS_linkage_name
};

enum bfd_error {
    bfd_error_bad_value
};

#define _(x) x

extern unsigned int _bfd_safe_read_leb128 (bfd *, bfd_byte *, unsigned int *, bfd_boolean, bfd_byte *);
extern struct abbrev_info *lookup_abbrev (unsigned int, struct abbrev_info *);
extern bfd_byte *read_attribute (struct attribute *, struct attribute *, struct comp_unit *, bfd_byte *, bfd_byte *);
extern bfd_boolean is_str_attr (unsigned int);
extern bfd_boolean non_mangled (unsigned int);
extern bfd_byte *read_alt_indirect_ref (struct comp_unit *, bfd_uint64_t);
extern void _bfd_error_handler (const char *, ...);
extern void bfd_set_error (enum bfd_error);