#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef int bfd_boolean;
typedef struct bfd bfd;
typedef unsigned char bfd_byte;

#define FALSE 0
#define TRUE 1

#define TAG_padding 0

enum {
    FORM_DATA2 = 1,
    FORM_DATA4,
    FORM_REF,
    FORM_DATA8,
    FORM_ADDR,
    FORM_BLOCK2,
    FORM_BLOCK4,
    FORM_STRING
};

enum {
    AT_sibling = 1,
    AT_stmt_list,
    AT_low_pc,
    AT_high_pc,
    AT_name
};

#define FORM_FROM_ATTR(attr) ((attr) & 0xF)

struct die_info {
    uint32_t length;
    uint16_t tag;
    uint32_t sibling;
    uint32_t stmt_list_offset;
    bfd_boolean has_stmt_list;
    uint32_t low_pc;
    uint32_t high_pc;
    char *name;
};

uint16_t bfd_get_16(bfd *abfd, bfd_byte *xptr);
uint32_t bfd_get_32(bfd *abfd, bfd_byte *xptr);