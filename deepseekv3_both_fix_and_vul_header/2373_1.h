#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool bfd_boolean;
#define TRUE true
#define FALSE false

typedef uint8_t bfd_byte;
typedef uint64_t bfd_vma;

struct bfd;
typedef struct bfd bfd;

struct comp_unit {
    bfd *abfd;
};

struct line_info_table {
    // dummy structure
};

struct fileinfo {
    char *name;
    unsigned int dir;
    unsigned int time;
    unsigned int size;
};

#define DW_LNCT_path 0
#define DW_LNCT_directory_index 1
#define DW_LNCT_timestamp 2
#define DW_LNCT_size 3
#define DW_LNCT_MD5 4

#define DW_FORM_string 0
#define DW_FORM_line_strp 1
#define DW_FORM_data1 2
#define DW_FORM_data2 3
#define DW_FORM_data4 4
#define DW_FORM_data8 5
#define DW_FORM_udata 6
#define DW_FORM_block 7

#define bfd_error_bad_value 0

extern bfd_byte read_1_byte(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern unsigned short read_2_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern unsigned int read_4_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern uint64_t read_8_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern char *read_string(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end, unsigned int *bytes_read);
extern char *read_indirect_line_string(struct comp_unit *unit, bfd_byte *buf, bfd_byte *buf_end, unsigned int *bytes_read);
extern bfd_vma _bfd_safe_read_leb128(bfd *abfd, bfd_byte *buf, unsigned int *bytes_read, bfd_boolean is_signed, bfd_byte *buf_end);
extern void _bfd_error_handler(const char *fmt, ...);
extern void bfd_set_error(int error);