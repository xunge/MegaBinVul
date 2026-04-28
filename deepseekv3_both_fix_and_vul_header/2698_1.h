#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#define FALSE 0
#define TRUE 1
#define FILE_ALLOC_CHUNK 64
#define debug_line 0

typedef uint64_t bfd_vma;
typedef size_t bfd_size_type;
typedef struct bfd bfd;
typedef unsigned char bfd_byte;

struct comp_unit {
    bfd *abfd;
    char *comp_dir;
    unsigned int line_offset;
    unsigned int addr_size;
    void *arange;
};

struct dwarf2_debug {
    void *debug_sections[1];
    void *syms;
    bfd_byte *dwarf_line_buffer;
    bfd_size_type dwarf_line_size;
};

struct line_info_table {
    bfd *abfd;
    char *comp_dir;
    unsigned int num_files;
    struct fileinfo *files;
    unsigned int num_dirs;
    char **dirs;
    unsigned int num_sequences;
    struct line_sequence *sequences;
    struct line_head *lcl_head;
};

struct line_head {
    bfd_vma total_length;
    unsigned int version;
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

struct line_sequence {
    struct line_sequence *prev_sequence;
};

/* DWARF line number opcodes */
#define DW_LNS_copy 1
#define DW_LNS_advance_pc 2
#define DW_LNS_advance_line 3
#define DW_LNS_set_file 4
#define DW_LNS_set_column 5
#define DW_LNS_negate_stmt 6
#define DW_LNS_set_basic_block 7
#define DW_LNS_const_add_pc 8
#define DW_LNS_fixed_advance_pc 9
#define DW_LNS_extended_op 0

/* DWARF extended line number opcodes */
#define DW_LNE_end_sequence 1
#define DW_LNE_set_address 2
#define DW_LNE_define_file 3
#define DW_LNE_set_discriminator 4
#define DW_LNE_HP_source_file_correlation 0x80

extern int _bfd_error_handler(const char *, ...);
extern void bfd_set_error(int);
extern void *bfd_alloc(bfd *, bfd_size_type);
extern void *bfd_realloc(void *, bfd_size_type);
extern int bfd_error_bad_value;

unsigned int read_1_byte(bfd *, bfd_byte *, bfd_byte *);
unsigned int read_2_bytes(bfd *, bfd_byte *, bfd_byte *);
unsigned int read_4_bytes(bfd *, bfd_byte *, bfd_byte *);
uint64_t read_8_bytes(bfd *, bfd_byte *, bfd_byte *);
signed char read_1_signed_byte(bfd *, bfd_byte *, bfd_byte *);
bfd_vma read_address(struct comp_unit *, bfd_byte *, bfd_byte *);
char *read_string(bfd *, bfd_byte *, bfd_byte *, unsigned int *);
unsigned int _bfd_safe_read_leb128(bfd *, bfd_byte *, unsigned int *, int, bfd_byte *);
int read_section(bfd *, void *, void *, unsigned int, bfd_byte **, bfd_size_type *);
int read_formatted_entries(struct comp_unit *, bfd_byte **, bfd_byte *, struct line_info_table *, int (*)(struct line_info_table *, ...));
int line_info_add_include_dir_stub(struct line_info_table *, ...);
int line_info_add_include_dir(struct line_info_table *, char *);
int line_info_add_file_name(struct line_info_table *, char *, unsigned int, unsigned int, unsigned int);
char *concat_filename(struct line_info_table *, unsigned int);
int add_line_info(struct line_info_table *, bfd_vma, unsigned char, char *, unsigned int, unsigned int, unsigned int, int);
int arange_add(struct comp_unit *, void *, bfd_vma, bfd_vma);
int sort_line_sequences(struct line_info_table *);