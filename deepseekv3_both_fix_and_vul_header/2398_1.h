#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned long elf_vma;
typedef enum { FALSE, TRUE } bfd_boolean;

struct ar_hdr {
    char ar_name[16];
    char ar_date[12];
    char ar_uid[6];
    char ar_gid[6];
    char ar_mode[8];
    char ar_size[10];
    char ar_fmag[2];
};

struct archive_info {
    char *file_name;
    FILE *file;
    struct ar_hdr arhdr;
    unsigned long next_arhdr_offset;
    unsigned long index_num;
    elf_vma *index_array;
    char *sym_table;
    size_t sym_size;
};

unsigned long byte_get_big_endian(unsigned char *buf, unsigned int size);
void error(const char *format, ...);