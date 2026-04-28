#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } bfd_boolean;
typedef uint64_t bfd_uint64_t;
typedef unsigned char bfd_byte;
typedef void bfd;

enum {
    DW_FORM_ref_addr = 0x10,
    DW_FORM_GNU_ref_alt = 0x1f00,
    DW_AT_name = 0x03,
    DW_AT_specification = 0x47,
    DW_AT_linkage_name = 0x6e,
    DW_AT_MIPS_linkage_name = 0x2007,
    bfd_error_bad_value
};

struct comp_unit;
struct attribute;
struct abbrev_info;
struct stash;

struct comp_unit {
    bfd *abfd;
    bfd_byte *sec_info_ptr;
    bfd_byte *end_ptr;
    bfd_byte *info_ptr_unit;
    struct comp_unit *prev_unit;
    struct comp_unit *next_unit;
    struct abbrev_info *abbrevs;
    struct stash *stash;
    unsigned int lang;
};

struct attribute {
    unsigned int form;
    unsigned int name;
    union {
        bfd_uint64_t val;
        char *str;
    } u;
};

struct abbrev_info {
    unsigned int num_attrs;
    struct attribute *attrs;
};

struct stash {
    bfd_byte *alt_dwarf_info_buffer;
    size_t alt_dwarf_info_size;
};

#define _(x) x

extern bfd_byte *read_alt_indirect_ref(struct comp_unit *unit, bfd_uint64_t die_ref);
extern unsigned int _bfd_safe_read_leb128(bfd *abfd, bfd_byte *info_ptr, unsigned int *bytes_read, bfd_boolean sign, bfd_byte *info_ptr_end);
extern struct abbrev_info *lookup_abbrev(unsigned int abbrev_number, struct abbrev_info *abbrevs);
extern bfd_byte *read_attribute(struct attribute *attr, struct attribute *abbrev_attr, struct comp_unit *unit, bfd_byte *info_ptr, bfd_byte *info_ptr_end);
extern bfd_boolean is_str_attr(unsigned int form);
extern bfd_boolean non_mangled(unsigned int lang);
extern void _bfd_error_handler(const char *fmt, ...);
extern void bfd_set_error(int error);