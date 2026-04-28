#include <stddef.h>
#include <elf.h>
#include <stdint.h>

typedef uint32_t bfd_vma;
typedef int32_t bfd_signed_vma;
typedef int bfd_boolean;

#define FALSE 0
#define TRUE 1
#define SHN_UNDEF 0
#define SHT_REL 9
#define SHT_RELA 4
#define EM_ARM 40
#define EM_TI_C6000 140

typedef struct {
    Elf32_Word sh_name;
    Elf32_Word sh_type;
    Elf32_Word sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off sh_offset;
    Elf32_Word sh_size;
    Elf32_Word sh_link;
    Elf32_Word sh_info;
    Elf32_Word sh_addralign;
    Elf32_Word sh_entsize;
} Elf_Internal_Shdr;

typedef struct {
    Elf32_Addr r_offset;
    Elf32_Word r_info;
    Elf32_Sword r_addend;
} Elf_Internal_Rela;

typedef struct {
    Elf32_Word st_name;
    Elf32_Addr st_value;
    Elf32_Word st_size;
    unsigned char st_info;
    unsigned char st_other;
    Elf32_Half st_shndx;
} Elf_Internal_Sym;

struct arm_unw_aux_info {
    void *file;
    Elf_Internal_Sym *symtab;
    unsigned int nsyms;
};

struct arm_section {
    Elf_Internal_Shdr *sec;
    void *data;
    Elf_Internal_Rela *rela;
    unsigned int nrelas;
    Elf_Internal_Rela *next_rela;
    unsigned int rel_type;
};

struct absaddr {
    int section;
    bfd_vma offset;
};

extern Elf_Internal_Shdr *section_headers;
extern Elf32_Ehdr elf_header;

extern void arm_free_section(struct arm_section *);
extern void *get_data(void *, void *, bfd_vma, int, bfd_vma, const char *);
extern bfd_boolean slurp_rel_relocs(void *, bfd_vma, bfd_vma, Elf_Internal_Rela **, unsigned int *);
extern bfd_boolean slurp_rela_relocs(void *, bfd_vma, bfd_vma, Elf_Internal_Rela **, unsigned int *);
extern unsigned int byte_get(const void *, int);
extern void warn(const char *, ...);
extern void error(const char *, ...);
extern const char *elf_arm_reloc_type(unsigned int);
extern const char *elf_tic6x_reloc_type(unsigned int);
extern int streq(const char *, const char *);
extern const char *_(const char *);