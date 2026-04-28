#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define FILE_ALLOC_CHUNK 10
#define debug_line 0

enum {
    DW_LNS_extended_op = 0,
    DW_LNS_copy,
    DW_LNS_advance_pc,
    DW_LNS_advance_line,
    DW_LNS_set_file,
    DW_LNS_set_column,
    DW_LNS_negate_stmt,
    DW_LNS_set_basic_block,
    DW_LNS_const_add_pc,
    DW_LNS_fixed_advance_pc
};

enum {
    DW_LNE_end_sequence = 1,
    DW_LNE_set_address,
    DW_LNE_define_file,
    DW_LNE_set_discriminator,
    DW_LNE_HP_source_file_correlation = 0x80
};

enum bfd_error {
    bfd_error_bad_value
};

typedef unsigned long bfd_vma;
typedef unsigned long bfd_size_type;
typedef unsigned char bfd_byte;

struct bfd;
typedef struct bfd bfd;

struct line_head {
    bfd_vma total_length;
    unsigned short version;
    bfd_vma prologue_length;
    unsigned char minimum_instruction_length;
    unsigned char maximum_ops_per_insn;
    unsigned char default_is_stmt;
    signed char line_base;
    unsigned char line_range;
    unsigned char opcode_base;
    unsigned char *standard_opcode_lengths;
};

struct fileinfo {
    char *name;
    unsigned int dir;
    unsigned int time;
    unsigned int size;
};

struct line_info_table {
    bfd *abfd;
    char *comp_dir;
    unsigned int num_files;
    struct fileinfo *files;
    unsigned int num_dirs;
    char **dirs;
    unsigned int num_sequences;
    void *sequences;
    void *lcl_head;
};

struct comp_unit {
    bfd *abfd;
    char *comp_dir;
    unsigned int line_offset;
    unsigned int addr_size;
    void *arange;
};

struct dwarf2_debug {
    void *debug_sections;
    void *syms;
    bfd_byte *dwarf_line_buffer;
    bfd_size_type dwarf_line_size;
};

extern int read_section(bfd *, void *, void *, unsigned int, bfd_byte **, bfd_size_type *);
extern void *bfd_alloc(bfd *, bfd_size_type);
extern void _bfd_error_handler(const char *, ...);
extern void bfd_set_error(enum bfd_error);
extern bfd_vma read_4_bytes(bfd *, bfd_byte *, bfd_byte *);
extern bfd_vma read_8_bytes(bfd *, bfd_byte *, bfd_byte *);
extern unsigned short read_2_bytes(bfd *, bfd_byte *, bfd_byte *);
extern unsigned char read_1_byte(bfd *, bfd_byte *, bfd_byte *);
extern signed char read_1_signed_byte(bfd *, bfd_byte *, bfd_byte *);
extern char *read_string(bfd *, bfd_byte *, bfd_byte *, unsigned int *);
extern unsigned int _bfd_safe_read_leb128(bfd *, bfd_byte *, unsigned int *, int, bfd_byte *);
extern bfd_vma read_address(struct comp_unit *, bfd_byte *, bfd_byte *);
extern int read_formatted_entries(struct comp_unit *, bfd_byte **, bfd_byte *, struct line_info_table *, int (*)(struct line_info_table *, ...));
extern int line_info_add_include_dir_stub(struct line_info_table *, ...);
extern int line_info_add_file_name(struct line_info_table *, ...);
extern int line_info_add_include_dir(struct line_info_table *, char *);
extern char *concat_filename(struct line_info_table *, unsigned int);
extern int add_line_info(struct line_info_table *, bfd_vma, unsigned char, char *, unsigned int, unsigned int, unsigned int, int);
extern int arange_add(struct comp_unit *, void *, bfd_vma, bfd_vma);
extern int sort_line_sequences(struct line_info_table *);
extern void *bfd_realloc(void *, bfd_size_type);