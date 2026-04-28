#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef int bfd_boolean;
#define TRUE 1
#define FALSE 0

typedef unsigned long bfd_vma;
typedef unsigned char bfd_byte;

struct bfd {
    unsigned long flags;
    struct asection *sections;
};

struct asection {
    char *name;
    bfd_vma vma;
    struct asection *next;
    struct asymbol **symbol_ptr_ptr;
};

struct asymbol {
    unsigned int flags;
    struct asymbol **symbol_ptr_ptr;
};

struct arelent {
    bfd_vma address;
    struct asymbol **sym_ptr_ptr;
    long addend;
    void *howto;
};

struct Elf_Internal_Shdr {
    unsigned int sh_type;
    unsigned int sh_info;
    unsigned int sh_entsize;
    bfd_vma sh_offset;
    bfd_vma sh_size;
};

struct Elf_Internal_Rela {
    bfd_vma r_offset;
    bfd_vma r_info;
    bfd_vma r_addend;
};

struct elf_section_data {
    struct Elf_Internal_Shdr this_hdr;
    unsigned int this_idx;
    void *sec_info;
};

struct elf_backend_data {
    struct {
        unsigned int sizeof_rel;
        unsigned int sizeof_rela;
        void (*swap_reloca_in)(struct bfd *, bfd_byte *, struct Elf_Internal_Rela *);
    } *s;
    bfd_boolean (*elf_info_to_howto)(struct bfd *, struct arelent *, struct Elf_Internal_Rela *);
};

#define BFD_DEFAULT_TARGET_SIZE 64
#define DEBUG_SECONDARY_RELOCS 0
#define SHT_SECONDARY_RELOC 0
#define EXEC_P 0x1
#define DYNAMIC 0x2
#define STN_UNDEF 0
#define BSF_KEEP 0x100

enum bfd_error {
    bfd_error_no_error,
    bfd_error_file_too_big,
    bfd_error_bad_value
};

#define NUM_SHDR_ENTRIES(hdr) ((hdr)->sh_size / (hdr)->sh_entsize)

typedef struct bfd bfd;
typedef struct asection asection;
typedef struct asymbol asymbol;
typedef struct arelent arelent;
typedef struct elf_backend_data elf_backend_data;
typedef struct Elf_Internal_Shdr Elf_Internal_Shdr;
typedef struct Elf_Internal_Rela Elf_Internal_Rela;

struct elf_section_data_wrapper {
    Elf_Internal_Shdr this_hdr;
    unsigned int this_idx;
    void *sec_info;
};

extern const struct elf_backend_data *get_elf_backend_data(bfd *abfd);
extern bfd_vma elf64_r_sym(bfd_vma);
extern bfd_vma elf32_r_sym(bfd_vma);
extern int bfd_arch_bits_per_address(bfd *abfd);
extern void *bfd_malloc(size_t size);
extern void *bfd_alloc(bfd *abfd, size_t size);
extern int bfd_seek(bfd *abfd, long offset, int whence);
extern size_t bfd_bread(void *ptr, size_t size, bfd *abfd);
extern unsigned int bfd_get_symcount(bfd *abfd);
extern void bfd_set_error(enum bfd_error error);
extern void _bfd_error_handler(const char *fmt, ...);
extern int _bfd_mul_overflow(unsigned int a, unsigned int b, size_t *res);
extern struct elf_section_data_wrapper *elf_section_data(asection *sec);
extern asection *bfd_abs_section_ptr;
extern const char *_(const char *);