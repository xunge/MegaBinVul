#include <stdint.h>
#include <unistd.h>

struct InputFile {
    void seek(long, int);
    void readx(void *, unsigned);
};

class PackLinuxElf64 {
public:
    void PackLinuxElf64help1(InputFile *f);
};

typedef uint16_t te16_t;
typedef uint64_t te64_t;

struct Elf64_Ehdr {
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS64 = 2,
        ELFDATA2LSB = 1,
        ELFDATA2MSB = 2,
        ET_DYN = 3
    };
    unsigned char e_ident[16];
    te16_t e_type;
    te16_t e_phnum;
    te16_t e_shnum;
    te64_t e_phoff;
    te64_t e_shoff;
    te16_t e_phentsize;
};

struct Elf64_Phdr {
    enum { PT_DYNAMIC = 2 };
    te64_t p_type;
    te64_t p_offset;
};

struct Elf64_Shdr {
    enum { SHT_DYNSYM = 11 };
    te64_t sh_link;
};

struct Elf64_Dyn {
    enum { DT_STRTAB = 5, DT_SYMTAB = 6, DT_GNU_HASH = 0x6ffffef5, DT_HASH = 4 };
    te64_t d_tag;
};

struct Elf64_Sym {
    te64_t st_value;
};

struct N_BELE_RTP {
    static int be_policy;
    static int le_policy;
};

extern unsigned long file_size;
extern char *file_image;
extern Elf64_Ehdr ehdri;
extern Elf64_Phdr *phdri;
extern Elf64_Shdr const *shdri;
extern Elf64_Shdr const *sec_dynsym;
extern Elf64_Shdr const *sec_dynstr;
extern Elf64_Dyn const *dynseg;
extern char const *dynstr;
extern Elf64_Sym const *dynsym;
extern unsigned const *gashtab;
extern unsigned const *hashtab;
extern Elf64_Sym const *jni_onload_sym;
extern uint64_t jni_onload_va;
extern int *bele;
extern uint64_t e_phoff;
extern uint64_t e_shoff;
extern unsigned sz_phdrs;
extern te16_t e_type;
extern te16_t e_phnum;
extern te16_t e_shnum;

te16_t get_te16(const void *);
te64_t get_te64(const void *);
void throwCantUnpack(const char *);
void alloc_file_image(char *&, unsigned);
Elf64_Shdr const *elf_find_section_type(unsigned);
void *elf_find_dynamic(int);
Elf64_Sym const *elf_lookup(const char *);