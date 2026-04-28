#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long bfd_vma;
typedef bool bfd_boolean;

#define FALSE false
#define TRUE true

#define EM_ALPHA 0x9026
#define EM_S390 0x16
#define EM_S390_OLD 0xA390
#define ELFCLASS64 2
#define EI_CLASS 4

#define DT_HASH 4
#define DT_GNU_HASH 0x6ffffef5
#define DT_MIPS_XHASH 0x70000000

extern bool do_histogram;
extern bool do_using_dynamic;
extern bool do_dyn_syms;
extern bool is_32bit_elf;
extern unsigned long *dynamic_info;
extern unsigned long dynamic_info_DT_GNU_HASH;
extern unsigned long dynamic_info_DT_MIPS_XHASH;
extern unsigned long archive_file_offset;
extern unsigned long nbuckets;
extern unsigned long nchains;
extern unsigned long *buckets;
extern unsigned long *chains;
extern unsigned long ngnubuckets;
extern unsigned long ngnuchains;
extern unsigned long *gnubuckets;
extern unsigned long *gnuchains;
extern unsigned long *mipsxlat;
extern unsigned long gnusymidx;

typedef struct {
    FILE *handle;
    struct {
        unsigned char e_ident[16];
        unsigned short e_machine;
    } file_header;
} Filedata;

extern void error(const char *);
extern unsigned long byte_get(const unsigned char *, unsigned int);
extern unsigned long *get_dynamic_data(Filedata *, unsigned long, unsigned int);
extern unsigned long offset_from_vma(Filedata *, unsigned long, unsigned long);