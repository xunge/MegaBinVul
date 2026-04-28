#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef enum bfd_boolean { FALSE, TRUE } bfd_boolean;
typedef unsigned long bfd_vma;
typedef unsigned char bfd_byte;

struct bfd {
    /* dummy structure definition */
};

typedef struct bfd bfd;

struct comp_unit {
    bfd *abfd;
};

struct line_info_table {
    /* dummy structure definition */  
};

struct attribute {
    union {
        char *str;
        unsigned int val;
    } u;
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

#define DW_FORM_string 1
#define DW_FORM_line_strp 2
#define DW_FORM_data1 3
#define DW_FORM_data2 4
#define DW_FORM_data4 5
#define DW_FORM_data8 6
#define DW_FORM_udata 7
#define DW_FORM_block 8

extern bfd_byte read_1_byte(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern unsigned short read_2_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern unsigned int read_4_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern unsigned long read_8_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end);
extern bfd_vma _bfd_safe_read_leb128(bfd *abfd, bfd_byte *buf, unsigned int *bytes_read, bfd_boolean sign, bfd_byte *buf_end);
extern char *read_string(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end, unsigned int *bytes_read);
extern char *read_indirect_line_string(struct comp_unit *unit, bfd_byte *buf, bfd_byte *buf_end, unsigned int *bytes_read);
extern bfd_byte *read_attribute_value(struct attribute *attr, bfd_vma form, int dummy, struct comp_unit *unit, bfd_byte *buf, bfd_byte *buf_end);
extern void _bfd_error_handler(const char *fmt, ...);
extern void bfd_set_error(int error);
#define bfd_error_bad_value 0
#define _(x) x