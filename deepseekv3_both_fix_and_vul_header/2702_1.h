#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef int bfd_boolean;
#define TRUE 1
#define FALSE 0

typedef struct bfd bfd;
typedef unsigned char bfd_byte;

#define SEEK_SET 0

typedef struct {
    unsigned int sh_info;
    unsigned int sh_size;
    unsigned long sh_offset;
    unsigned int sh_link;
} Elf_Internal_Shdr;

typedef struct {
    unsigned int vn_file;
    unsigned int vn_cnt;
    unsigned int vn_aux;
    unsigned int vn_next;
    bfd *vn_bfd;
    char *vn_filename;
    struct elf_internal_vernaux *vn_auxptr;
    struct Elf_Internal_Verneed *vn_nextref;
} Elf_Internal_Verneed;

typedef struct {
    unsigned int vna_name;
    unsigned int vna_next;
    unsigned int vna_other;
    char *vna_nodename;
    struct elf_internal_vernaux *vna_nextptr;
} Elf_Internal_Vernaux;

typedef struct {
    unsigned int vd_version;
    unsigned int vd_flags;
    unsigned int vd_ndx;
    unsigned int vd_cnt;
    unsigned int vd_hash;
    unsigned int vd_aux;
    unsigned int vd_next;
    bfd *vd_bfd;
    char *vd_nodename;
    struct elf_internal_verdaux *vd_auxptr;
    struct Elf_Internal_Verdef *vd_nextdef;
} Elf_Internal_Verdef;

typedef struct {
    unsigned int vda_name;
    unsigned int vda_next;
    char *vda_nodename;
    struct elf_internal_verdaux *vda_nextptr;
} Elf_Internal_Verdaux;

typedef struct {
    Elf_Internal_Shdr dynverref_hdr;
    Elf_Internal_Shdr dynverdef_hdr;
    Elf_Internal_Verneed *verref;
    unsigned int cverrefs;
    Elf_Internal_Verdef *verdef;
    unsigned int cverdefs;
} elf_tdata_type;

typedef struct {
    unsigned char data[16];
} Elf_External_Verneed;

typedef struct {
    unsigned char data[16];
} Elf_External_Vernaux;

typedef struct {
    unsigned char data[16];
} Elf_External_Verdef;

typedef struct {
    unsigned char data[16];
} Elf_External_Verdaux;

struct elf_internal_vernaux {
    unsigned int vna_name;
    unsigned int vna_next;
    unsigned int vna_other;
    char *vna_nodename;
    struct elf_internal_vernaux *vna_nextptr;
};

struct elf_internal_verdaux {
    unsigned int vda_name;
    unsigned int vda_next;
    char *vda_nodename;
    struct elf_internal_verdaux *vda_nextptr;
};

#define VER_DEF_CURRENT 1
#define VERSYM_VERSION 0x7fff

#define BFD_ASSERT(expr) ((void)0)

extern elf_tdata_type *elf_tdata(bfd *);
extern unsigned int elf_dynverref(bfd *);
extern unsigned int elf_dynverdef(bfd *);
extern void _bfd_elf_swap_verneed_in(bfd *, void *, Elf_Internal_Verneed *);
extern void _bfd_elf_swap_vernaux_in(bfd *, void *, Elf_Internal_Vernaux *);
extern void _bfd_elf_swap_verdef_in(bfd *, void *, Elf_Internal_Verdef *);
extern void _bfd_elf_swap_verdaux_in(bfd *, void *, Elf_Internal_Verdaux *);
extern char *bfd_elf_string_from_elf_section(bfd *, unsigned int, unsigned int);
extern char *bfd_elf_get_dt_soname(bfd *);
extern void *_bfd_zalloc2(bfd *, size_t, size_t);
extern void *_bfd_alloc2(bfd *, size_t, size_t);
extern void *bfd_malloc(size_t);
extern void *bfd_zalloc(bfd *, size_t);
extern void *bfd_alloc2(bfd *, size_t, size_t);
extern void *bfd_zalloc2(bfd *, size_t, size_t);
extern int bfd_seek(bfd *, long, int);
extern size_t bfd_bread(void *, size_t, bfd *);
extern void _bfd_error_handler(const char *, ...);
extern void bfd_set_error(int);
extern int bfd_error_bad_value;