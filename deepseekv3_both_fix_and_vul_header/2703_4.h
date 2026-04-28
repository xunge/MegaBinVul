#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char bfd_byte;
typedef unsigned long bfd_size_type;
typedef unsigned long bfd_vma;
typedef struct bfd bfd;
typedef struct asymbol asymbol;

#define FILE_ALLOC_CHUNK 16
#define _(x) x
#define FALSE 0
#define TRUE 1

enum dwarf_section
{
  debug_info,
  debug_line,
  debug_abbrev,
  debug_aranges,
  debug_ranges,
  debug_str,
  debug_loc,
  debug_frame,
  debug_macinfo,
  debug_pubnames,
  debug_pubtypes,
  debug_types,
  debug_weaknames,
  debug_funcnames,
  debug_varnames,
  debug_typenames,
  debug_usednames,
  debug_max
};

struct dwarf2_section_info
{
  bfd_byte *buffer;
  bfd_size_type size;
};

struct dwarf2_debug
{
  struct dwarf2_section_info debug_sections[debug_max];
  bfd_byte *dwarf_line_buffer;
  bfd_size_type dwarf_line_size;
  asymbol **syms;
};

struct arange
{
  bfd_vma low;
  bfd_vma high;
};

struct comp_unit
{
  bfd *abfd;
  char *comp_dir;
  unsigned int line_offset;
  unsigned int addr_size;
  struct arange arange;
};

struct line_head
{
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

struct fileinfo
{
  char *name;
  unsigned int dir;
  unsigned int time;
  unsigned int size;
};

struct line_info_table
{
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

enum bfd_error
{
  bfd_error_no_error,
  bfd_error_system_call,
  bfd_error_invalid_target,
  bfd_error_wrong_format,
  bfd_error_invalid_operation,
  bfd_error_no_memory,
  bfd_error_no_symbols,
  bfd_error_no_armap,
  bfd_error_no_more_archived_files,
  bfd_error_malformed_archive,
  bfd_error_file_not_recognized,
  bfd_error_file_ambiguously_recognized,
  bfd_error_no_contents,
  bfd_error_nonrepresentable_section,
  bfd_error_no_debug_section,
  bfd_error_bad_value,
  bfd_error_file_truncated,
  bfd_error_file_too_big,
  bfd_error_invalid_error_code
};

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

#define DW_LNE_end_sequence 1
#define DW_LNE_set_address 2
#define DW_LNE_define_file 3
#define DW_LNE_set_discriminator 4
#define DW_LNE_HP_source_file_correlation 0x80

extern void _bfd_error_handler(const char *fmt, ...);
extern void bfd_set_error(enum bfd_error error);
extern void *bfd_alloc(bfd *abfd, bfd_size_type wanted);
extern void *bfd_realloc(void *ptr, bfd_size_type size);
extern int read_section(bfd *abfd, struct dwarf2_section_info *section,
                       asymbol **syms, unsigned int offset,
                       bfd_byte **buffer, bfd_size_type *size);
extern unsigned int read_1_byte(bfd *abfd, bfd_byte *buf, bfd_byte *end);
extern int read_1_signed_byte(bfd *abfd, bfd_byte *buf, bfd_byte *end);
extern unsigned int read_2_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *end);
extern unsigned int read_4_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *end);
extern bfd_vma read_8_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *end);
extern char *read_string(bfd *abfd, bfd_byte *buf, bfd_byte *end,
                        unsigned int *bytes_read);
extern unsigned int _bfd_safe_read_leb128(bfd *abfd, bfd_byte *buf,
                                         unsigned int *bytes_read,
                                         int sign, bfd_byte *end);
extern bfd_vma read_address(struct comp_unit *unit, bfd_byte *buf, bfd_byte *end);
extern int read_formatted_entries(struct comp_unit *unit, bfd_byte **buf,
                                 bfd_byte *end, struct line_info_table *table,
                                 int (*callback)(struct line_info_table *,
                                                const char *, unsigned int,
                                                unsigned int, unsigned int));
extern int line_info_add_include_dir_stub(struct line_info_table *table,
                                         const char *dir);
extern int line_info_add_include_dir(struct line_info_table *table,
                                    const char *dir);
extern int line_info_add_file_name(struct line_info_table *table,
                                  const char *file, unsigned int dir,
                                  unsigned int time, unsigned int size);
extern char *concat_filename(struct line_info_table *table, unsigned int file);
extern int add_line_info(struct line_info_table *table, bfd_vma address,
                        unsigned char op_index, char *filename,
                        unsigned int line, unsigned int column,
                        unsigned int discriminator, int end_sequence);
extern int arange_add(struct comp_unit *unit, struct arange *arange,
                     bfd_vma low_pc, bfd_vma high_pc);
extern int sort_line_sequences(struct line_info_table *table);