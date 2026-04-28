#include <stddef.h>
#include <string.h>

typedef struct bfd bfd;
typedef struct asection {
    struct asection *next;
    unsigned long flags;
    void *used_by_bfd;
} asection;
typedef struct bfd_target bfd_target;
typedef unsigned long file_ptr;
typedef unsigned long bfd_size_type;

enum {
    bfd_error_system_call,
    bfd_error_wrong_format
};

#define bfd_get_error() bfd_error_system_call
#define bfd_bread(a,b,c) 0
#define bfd_seek(a,b,c) 0
#define bfd_alloc(a,b) NULL
#define bfd_set_error(a)
#define bfd_set_start_address(a,b)
#define bfd_header_big_endian(a) 0
#define bfd_header_little_endian(a) 0
#define bfd_section_from_elf_index(a,b) NULL
#define bfd_section_from_shdr(a,b) 0
#define bfd_default_set_arch_mach(a,b,c) 0

enum {
    EV_CURRENT = 1,
    EI_VERSION = 6,
    EI_CLASS = 4,
    EI_DATA = 5,
    EI_OSABI = 7,
    ELFCLASS = 2,
    ELFDATA2MSB = 2,
    ELFDATA2LSB = 1,
    ELFDATANONE = 0,
    ELFOSABI_NONE = 0,
    EM_NONE = 0,
    EM_386 = 3,
    EM_IAMCU = 6,
    EM_X86_64 = 62,
    EM_OLD_SPARCV9 = 11,
    EM_SPARC32PLUS = 18,
    EM_SPARCV9 = 43,
    EM_SPARC = 2,
    ET_CORE = 4,
    ET_REL = 1,
    ET_EXEC = 2,
    ET_DYN = 3,
    SHN_UNDEF = 0,
    SHN_LORESERVE = 0xff00,
    SHN_XINDEX = 0xffff,
    SHN_BEFORE = 0xff00,
    SHN_AFTER = 0xff01,
    SHT_REL = 9,
    SHT_RELA = 4,
    SHT_NOBITS = 8,
    SHF_ALLOC = 0x2,
    SHF_INFO_LINK = 0x40,
    SHF_GROUP = 0x200,
    SHF_LINK_ORDER = 0x80,
    SEC_DEBUGGING = 0x100,
    EXEC_P = 0x1000,
    DYNAMIC = 0x2000,
    D_PAGED = 0x4000,
    PN_XNUM = 0xffff,
    ARCH_SIZE = 32,
    DEBUG = 0,
    bfd_object = 1
};

struct elf_backend_data {
    const struct elf_backend_data *s;
    int arch_size;
    int elf_machine_code;
    int elf_machine_alt1;
    int elf_machine_alt2;
    int elf_osabi;
    int minpagesize;
    int arch;
    int (*elf_backend_object_p)(bfd *);
};

struct bfd {
    const bfd_target *xvec;
    unsigned long flags;
    asection *sections;
    union {
        void *any;
        struct elf_obj_tdata *elf_obj_data;
    } tdata;
};

struct bfd_target {
    int (*_bfd_set_format[2])(bfd *);
};

typedef struct {
    unsigned char e_ident[16];
    unsigned short e_type;
    unsigned short e_machine;
    unsigned int e_version;
    unsigned long e_entry;
    unsigned long e_phoff;
    unsigned long e_shoff;
    unsigned int e_flags;
    unsigned short e_ehsize;
    unsigned short e_phentsize;
    unsigned short e_phnum;
    unsigned short e_shentsize;
    unsigned short e_shnum;
    unsigned short e_shstrndx;
} Elf_Internal_Ehdr;

typedef struct {
    unsigned char e_ident[16];
} Elf_External_Ehdr;

typedef struct {
    unsigned int sh_name;
    unsigned int sh_type;
    unsigned long sh_flags;
    unsigned long sh_addr;
    unsigned long sh_offset;
    unsigned long sh_size;
    unsigned int sh_link;
    unsigned int sh_info;
    unsigned long sh_addralign;
    unsigned long sh_entsize;
} Elf_Internal_Shdr;

typedef struct {
    unsigned char sh_info[16];
} Elf_External_Shdr;

typedef struct {
    unsigned char p_info[16];
} Elf_External_Phdr;

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

struct elf_obj_tdata {
    Elf_Internal_Ehdr *ehdr;
    Elf_Internal_Phdr *phdr;
    Elf_Internal_Shdr **shdr;
    unsigned int num_sections;
};

struct elf_section_data {
    Elf_Internal_Shdr this_hdr;
};

#define elf_tdata(a) ((a)->tdata.elf_obj_data)
#define elf_elfheader(a) (elf_tdata(a)->ehdr)
#define elf_numsections(a) (elf_tdata(a)->num_sections)
#define elf_elfsections(a) (elf_tdata(a)->shdr)
#define elf_section_data(a) ((struct elf_section_data *)((a)->used_by_bfd))

const struct elf_backend_data *get_elf_backend_data(bfd *);
int elf_file_p(Elf_External_Ehdr *);
void elf_swap_ehdr_in(bfd *, Elf_External_Ehdr *, Elf_Internal_Ehdr *);
void elf_swap_shdr_in(bfd *, Elf_External_Shdr *, Elf_Internal_Shdr *);
void elf_swap_phdr_in(bfd *, Elf_External_Phdr *, Elf_Internal_Phdr *);
void elf_debug_file(Elf_Internal_Ehdr *);
int _bfd_elf_setup_sections(bfd *);
void _bfd_error_handler(const char *, ...);
const char *_(const char *);