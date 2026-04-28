#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define SEEK_SET 0
#define bfd_error_system_call 1
#define bfd_error_wrong_format 2
#define bfd_object 1

typedef struct bfd bfd;
typedef struct bfd_target bfd_target;
typedef struct asection asection;
typedef long file_ptr;
typedef unsigned long bfd_size_type;

struct bfd_target {
    int (*_bfd_set_format[2])(bfd *);
};

struct bfd {
    const bfd_target *xvec;
    unsigned long flags;
    asection *sections;
};

struct asection {
    unsigned long flags;
    asection *next;
    void *used_by_bfd;
};

typedef struct {
    unsigned long sh_name;
    unsigned long sh_type;
    unsigned long sh_flags;
    unsigned long sh_addr;
    unsigned long sh_offset;
    unsigned long sh_size;
    unsigned long sh_link;
    unsigned long sh_info;
    unsigned long sh_addralign;
    unsigned long sh_entsize;
} Elf_Internal_Shdr;

typedef struct {
    unsigned long p_type;
    unsigned long p_offset;
    unsigned long p_vaddr;
    unsigned long p_paddr;
    unsigned long p_filesz;
    unsigned long p_memsz;
    unsigned long p_flags;
    unsigned long p_align;
} Elf_Internal_Phdr;

struct elf_section_data {
    Elf_Internal_Shdr this_hdr;
};

struct elf_backend_data {
    unsigned int elf_machine_code;
    unsigned int elf_machine_alt1;
    unsigned int elf_machine_alt2;
    unsigned int elf_osabi;
    unsigned int minpagesize;
    unsigned int arch_size;
    const char *arch;
    int (*elf_backend_object_p)(bfd *);
    struct {
        unsigned int arch_size;
    } *s;
};

struct elf_obj_tdata {
    Elf_Internal_Phdr *phdr;
    Elf_Internal_Shdr **elfsections;
    unsigned int numsections;
};

typedef struct {
    unsigned char e_ident[16];
    unsigned char e_type;
    unsigned char e_machine;
    unsigned char e_version;
    unsigned long e_entry;
    unsigned long e_phoff;
    unsigned long e_shoff;
    unsigned long e_flags;
    unsigned short e_ehsize;
    unsigned short e_phentsize;
    unsigned short e_phnum;
    unsigned short e_shentsize;
    unsigned short e_shnum;
    unsigned short e_shstrndx;
} Elf_External_Ehdr;

typedef struct {
    unsigned char e_ident[16];
    unsigned char e_type;
    unsigned char e_machine;
    unsigned char e_version;
    unsigned long e_entry;
    unsigned long e_phoff;
    unsigned long e_shoff;
    unsigned long e_flags;
    unsigned short e_ehsize;
    unsigned short e_phentsize;
    unsigned short e_phnum;
    unsigned short e_shentsize;
    unsigned short e_shnum;
    unsigned short e_shstrndx;
} Elf_Internal_Ehdr;

typedef struct {
    unsigned long sh_name;
    unsigned long sh_type;
    unsigned long sh_flags;
    unsigned long sh_addr;
    unsigned long sh_offset;
    unsigned long sh_size;
    unsigned long sh_link;
    unsigned long sh_info;
    unsigned long sh_addralign;
    unsigned long sh_entsize;
} Elf_External_Shdr;

typedef struct {
    unsigned long p_type;
    unsigned long p_offset;
    unsigned long p_vaddr;
    unsigned long p_paddr;
    unsigned long p_filesz;
    unsigned long p_memsz;
    unsigned long p_flags;
    unsigned long p_align;
} Elf_External_Phdr;

#define EI_VERSION 6
#define EI_CLASS 4
#define EI_DATA 5
#define EI_OSABI 7
#define EV_CURRENT 1
#define ELFCLASS 1
#define ELFDATA2MSB 2
#define ELFDATA2LSB 1
#define ELFDATANONE 0
#define ET_CORE 4
#define ET_REL 1
#define ET_EXEC 2
#define ET_DYN 3
#define SHN_UNDEF 0
#define SHN_LORESERVE 0xff00
#define SHN_XINDEX 0xffff
#define SHN_BEFORE (SHN_LORESERVE & 0xffff)
#define SHN_AFTER ((SHN_LORESERVE + 1) & 0xffff)
#define SHT_STRTAB 3
#define SHT_RELA 4
#define SHT_REL 9
#define SHT_NOBITS 8
#define SHF_ALLOC 2
#define SHF_INFO_LINK 0x40
#define SHF_GROUP 0x200
#define SHF_LINK_ORDER 0x80
#define EM_NONE 0
#define EM_386 3
#define EM_IAMCU 6
#define EM_X86_64 62
#define EM_OLD_SPARCV9 11
#define EM_SPARC32PLUS 18
#define EM_SPARCV9 43
#define EM_SPARC 2
#define ELFOSABI_NONE 0
#define PN_XNUM 0xffff
#define ARCH_SIZE 32
#define DEBUG 0

#define SEC_DEBUGGING 0x100
#define EXEC_P 0x10
#define DYNAMIC 0x20
#define D_PAGED 0x100

extern int bfd_bread(void *, bfd_size_type, bfd *);
extern int bfd_get_error(void);
extern int bfd_header_big_endian(bfd *);
extern int bfd_header_little_endian(bfd *);
extern int bfd_seek(bfd *, file_ptr, int);
extern int bfd_default_set_arch_mach(bfd *, const char *, unsigned long);
extern int _bfd_elf_setup_sections(bfd *);
extern void bfd_set_error(int);
extern void bfd_set_start_address(bfd *, unsigned long);
extern void *bfd_alloc2(bfd *, bfd_size_type, bfd_size_type);
extern bfd_size_type bfd_get_file_size(bfd *);
extern Elf_Internal_Ehdr *elf_elfheader(bfd *);
extern struct elf_obj_tdata *elf_tdata(bfd *);
extern void elf_swap_ehdr_in(bfd *, Elf_External_Ehdr *, Elf_Internal_Ehdr *);
extern void elf_swap_shdr_in(bfd *, Elf_External_Shdr *, Elf_Internal_Shdr *);
extern void elf_swap_phdr_in(bfd *, Elf_External_Phdr *, Elf_Internal_Phdr *);
extern int elf_file_p(Elf_External_Ehdr *);
extern const struct elf_backend_data *get_elf_backend_data(bfd *);
extern asection *bfd_section_from_shdr(bfd *, unsigned int);
extern asection *bfd_section_from_elf_index(bfd *, unsigned long);
extern void _bfd_error_handler(const char *, ...);
extern struct elf_section_data *elf_section_data(asection *);

#define elf_numsections(abfd) (elf_tdata(abfd)->numsections)
#define elf_elfsections(abfd) (elf_tdata(abfd)->elfsections)
#define _(str) str