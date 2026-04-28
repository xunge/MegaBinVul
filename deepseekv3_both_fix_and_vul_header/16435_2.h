#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define SEEK_SET 0

typedef int bfd_cleanup;

typedef struct bfd {
    const struct bfd_target *xvec;
    unsigned int flags;
    int read_only;
    struct asection *sections;
} bfd;

typedef struct asection {
    unsigned int flags;
    struct asection *next;
} asection;

typedef struct bfd_target {
    int (*_bfd_set_format[2])(bfd *);
} bfd_target;

typedef uint64_t file_ptr;
typedef uint64_t ufile_ptr;
typedef size_t bfd_size_type;

enum {
    bfd_error_system_call,
    bfd_error_wrong_format
};

#define EI_VERSION 6
#define EV_CURRENT 1
#define EI_CLASS 4
#define ELFCLASS 1
#define EI_DATA 5
#define ELFDATA2MSB 2
#define ELFDATA2LSB 1
#define ELFDATANONE 0
#define EI_OSABI 7
#define ELFOSABI_NONE 0
#define SHN_UNDEF 0
#define SHN_LORESERVE 0xff00
#define SHN_XINDEX 0xffff
#define PN_XNUM 0xffff
#define SHT_STRTAB 3
#define SHT_REL 9
#define SHT_RELA 4
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
#define ET_CORE 4
#define ET_REL 1
#define ET_EXEC 2
#define ET_DYN 3
#define SEC_DEBUGGING 0x100

#define EXEC_P 0x1000
#define DYNAMIC 0x2000
#define D_PAGED 0x4000

struct elf_backend_data {
    const struct elf_backend_data *s;
    int arch_size;
    int elf_machine_code;
    int elf_machine_alt1;
    int elf_machine_alt2;
    int arch;
    int elf_osabi;
    int minpagesize;
    int (*elf_backend_object_p)(bfd *);
};

struct elf_obj_tdata {
    struct Elf_Internal_Ehdr *ehdr;
    struct Elf_Internal_Phdr *phdr;
    struct Elf_Internal_Shdr **shdr;
    unsigned int num_sections;
};

typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf_External_Ehdr;

typedef struct Elf_Internal_Ehdr {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf_Internal_Ehdr;

typedef struct {
    uint32_t sh_name;
    uint32_t sh_type;
    uint64_t sh_flags;
    uint64_t sh_addr;
    uint64_t sh_offset;
    uint64_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint64_t sh_addralign;
    uint64_t sh_entsize;
} Elf_External_Shdr;

typedef struct Elf_Internal_Shdr {
    uint32_t sh_name;
    uint32_t sh_type;
    uint64_t sh_flags;
    uint64_t sh_addr;
    uint64_t sh_offset;
    uint64_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint64_t sh_addralign;
    uint64_t sh_entsize;
} Elf_Internal_Shdr;

typedef struct {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
} Elf_External_Phdr;

typedef struct Elf_Internal_Phdr {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
} Elf_Internal_Phdr;

struct elf_section_data {
    Elf_Internal_Shdr this_hdr;
};

#define ARCH_SIZE 64
#define bfd_object 1

extern int bfd_bread(void *, bfd_size_type, bfd *);
extern int bfd_get_error(void);
extern int bfd_seek(bfd *, file_ptr, int);
extern void *bfd_alloc(bfd *, bfd_size_type);
extern bfd_size_type bfd_get_file_size(bfd *);
extern int bfd_header_big_endian(bfd *);
extern int bfd_header_little_endian(bfd *);
extern int bfd_default_set_arch_mach(bfd *, int, int);
extern int bfd_section_from_shdr(bfd *, unsigned int);
extern int _bfd_elf_setup_sections(bfd *);
extern void bfd_set_error(int);
extern void bfd_set_start_address(bfd *, uint64_t);
extern asection *bfd_section_from_elf_index(bfd *, unsigned long);
extern Elf_Internal_Ehdr *elf_elfheader(bfd *);
extern void elf_swap_ehdr_in(bfd *, Elf_External_Ehdr *, Elf_Internal_Ehdr *);
extern void elf_swap_shdr_in(bfd *, Elf_External_Shdr *, Elf_Internal_Shdr *);
extern void elf_swap_phdr_in(bfd *, Elf_External_Phdr *, Elf_Internal_Phdr *);
extern unsigned int *elf_numsections_ptr(bfd *);
extern Elf_Internal_Shdr ***elf_elfsections_ptr(bfd *);
extern struct elf_obj_tdata *elf_tdata(bfd *);
extern struct elf_section_data *elf_section_data(asection *);
extern const struct elf_backend_data *get_elf_backend_data(bfd *);
extern int elf_file_p(Elf_External_Ehdr *);
extern void _bfd_error_handler(const char *, ...);
extern int _bfd_no_cleanup;
extern int _bfd_mul_overflow(size_t, size_t, size_t *);
extern const char *_(const char *);

#define elf_numsections(abfd) (*elf_numsections_ptr(abfd))
#define elf_elfsections(abfd) (*elf_elfsections_ptr(abfd))