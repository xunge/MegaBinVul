#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SARMAG 8
#define FALSE 0
#define TRUE 1

typedef int bfd_boolean;

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
    unsigned int index_num;
    void *index_array;
    char *sym_table;
    size_t sym_size;
    char *longnames;
    size_t longnames_size;
    unsigned long nested_member_origin;
    bfd_boolean is_thin_archive;
    bfd_boolean uses_64bit_indicies;
    unsigned long next_arhdr_offset;
    struct ar_hdr arhdr;
};

#define _(x) x

int const_strneq(const char *s1, const char *s2);
int process_archive_index_and_symbols(struct archive_info *arch, int size, bfd_boolean read_symbols);
void error(const char *format, ...);