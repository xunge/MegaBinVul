#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef bool bfd_boolean;
#define TRUE true
#define FALSE false

typedef uint8_t bfd_byte;
typedef uint64_t bfd_vma;

struct bfd {
    // BFD structure placeholder
};

typedef struct bfd bfd;

struct comp_unit {
    bfd *abfd;
};

struct line_info_table {
    // Line info table placeholder
};

struct fileinfo {
    char *name;
    unsigned int dir;
    unsigned int time;
    unsigned int size;
};

enum {
    DW_LNCT_path = 1,
    DW_LNCT_directory_index,
    DW_LNCT_timestamp,
    DW_LNCT_size,
    DW_LNCT_MD5
};

enum {
    DW_FORM_string = 1,
    DW_FORM_line_strp,
    DW_FORM_data1,
    DW_FORM_data2,
    DW_FORM_data4,
    DW_FORM_data8,
    DW_FORM_udata,
    DW_FORM_block
};

enum bfd_error {
    bfd_error_bad_value
};

static inline bfd_byte read_1_byte(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end) { return *buf; }
static inline unsigned short read_2_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end) { return *(unsigned short *)buf; }
static inline unsigned int read_4_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end) { return *(unsigned int *)buf; }
static inline uint64_t read_8_bytes(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end) { return *(uint64_t *)buf; }
static inline char *read_string(bfd *abfd, bfd_byte *buf, bfd_byte *buf_end, unsigned int *bytes_read) { *bytes_read = strlen((char *)buf) + 1; return (char *)buf; }
static inline char *read_indirect_line_string(struct comp_unit *unit, bfd_byte *buf, bfd_byte *buf_end, unsigned int *bytes_read) { *bytes_read = 4; return (char *)buf; }
static inline bfd_vma _bfd_safe_read_leb128(bfd *abfd, bfd_byte *buf, unsigned int *bytes_read, bfd_boolean is_signed, bfd_byte *buf_end) { *bytes_read = 1; return *buf; }
static inline void _bfd_error_handler(const char *fmt, ...) {}
static inline void bfd_set_error(enum bfd_error error) {}