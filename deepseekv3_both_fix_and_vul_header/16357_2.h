#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t bfd_vma;
typedef bool bfd_boolean;

#define EM_ALPHA 0x9026
#define EM_S390 0x16
#define EM_S390_OLD 0xA390
#define ELFCLASS64 2
#define EI_CLASS 4

#define DT_HASH 4
#define DT_GNU_HASH 0x6ffffef5
#define DT_MIPS_XHASH 0x70000033

#define TRUE true
#define FALSE false

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
extern unsigned long gnusymidx;
extern unsigned long *gnubuckets;
extern unsigned long *gnuchains;
extern unsigned long ngnuchains;
extern unsigned long *mipsxlat;

typedef struct {
    FILE *handle;
    struct {
        unsigned char e_ident[16];
        unsigned short e_machine;
    } file_header;
} Filedata;

extern unsigned long offset_from_vma(Filedata *filedata, unsigned long vma, size_t size);
extern void error(const char *msg);
extern unsigned long byte_get(unsigned char *bytes, size_t size);
extern unsigned long *get_dynamic_data(Filedata *filedata, unsigned long count, size_t size);

static inline const char *_(const char *str) { return str; }