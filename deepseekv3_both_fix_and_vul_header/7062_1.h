#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct bfd bfd;
typedef unsigned char bfd_byte;

#define BFD_ASSERT(expr)
#define _bfd_error_handler(msg, arg)
#define bfd_set_error(err)
#define bfd_error_bad_value 0
#define bfd_error_file_too_big 0
#define bfd_seek(abfd, offset, whence) 0
#define _bfd_malloc_and_read(abfd, size1, size2) malloc(size2)
#define _bfd_mul_overflow(a, b, res) (*(res) = (a)*(b), 0)
#define bfd_alloc(abfd, size) malloc(size)
#define bfd_zalloc(abfd, size) calloc(1, size)
#define bfd_elf_string_from_elf_section(abfd, link, name) NULL
#define bfd_elf_get_dt_soname(abfd) NULL
#define free(ptr) free(ptr)

#define VERSYM_VERSION 0x7fff
#define VER_DEF_CURRENT 1

struct elf_internal_vernaux {
    const char *vna_nodename;
    unsigned int vna_name;
    unsigned int vna_next;
    unsigned int vna_other;
    struct elf_internal_vernaux *vna_nextptr;
};

struct elf_internal_verdaux {
    const char *vda_nodename;
    unsigned int vda_name;
    unsigned int vda_next;
    struct elf_internal_verdaux *vda_nextptr;
};

typedef struct Elf_Internal_Verneed {
    unsigned int vn_version;
    unsigned int vn_cnt;
    unsigned int vn_file;
    unsigned int vn_aux;
    unsigned int vn_next;
    const char *vn_filename;
    struct elf_internal_vernaux *vn_auxptr;
    struct Elf_Internal_Verneed *vn_nextref;
    bfd *vn_bfd;
} Elf_Internal_Verneed;

typedef struct Elf_Internal_Verdef {
    unsigned int vd_version;
    unsigned int vd_flags;
    unsigned int vd_ndx;
    unsigned int vd_cnt;
    unsigned int vd_hash;
    unsigned int vd_aux;
    unsigned int vd_next;
    const char *vd_nodename;
    struct elf_internal_verdaux *vd_auxptr;
    struct Elf_Internal_Verdef *vd_nextdef;
    bfd *vd_bfd;
} Elf_Internal_Verdef;

typedef struct {
    unsigned char vna_hash[4];
    unsigned char vna_flags[2];
    unsigned char vna_other[2];
    unsigned char vna_name[4];
    unsigned char vna_next[4];
} Elf_External_Vernaux;

typedef struct {
    unsigned char vd_version[2];
    unsigned char vd_flags[2];
    unsigned char vd_ndx[2];
    unsigned char vd_cnt[2];
    unsigned char vd_hash[4];
    unsigned char vd_aux[4];
    unsigned char vd_next[4];
} Elf_External_Verdef;

typedef struct {
    unsigned char vn_version[2];
    unsigned char vn_cnt[2];
    unsigned char vn_file[4];
    unsigned char vn_aux[4];
    unsigned char vn_next[4];
} Elf_External_Verneed;

typedef struct {
    unsigned char vda_name[4];
    unsigned char vda_next[4];
} Elf_External_Verdaux;

typedef struct {
    unsigned int sh_info;
    unsigned int sh_link;
    unsigned int sh_offset;
    unsigned int sh_size;
} Elf_Internal_Shdr;

typedef struct elf_internal_vernaux Elf_Internal_Vernaux;
typedef struct elf_internal_verdaux Elf_Internal_Verdaux;

struct elf_obj_tdata {
    Elf_Internal_Shdr dynverref_hdr;
    Elf_Internal_Shdr dynverdef_hdr;
    Elf_Internal_Verneed *verref;
    unsigned int cverrefs;
    Elf_Internal_Verdef *verdef;
    unsigned int cverdefs;
};

#define elf_tdata(abfd) ((struct elf_obj_tdata *)(abfd))
#define elf_dynverref(abfd) 0
#define elf_dynverdef(abfd) 0
#define _bfd_elf_swap_verneed_in(abfd, ext, intp)
#define _bfd_elf_swap_vernaux_in(abfd, ext, intp)
#define _bfd_elf_swap_verdef_in(abfd, ext, intp)
#define _bfd_elf_swap_verdaux_in(abfd, ext, intp)