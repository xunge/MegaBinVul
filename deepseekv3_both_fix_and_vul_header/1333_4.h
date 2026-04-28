#include <stdint.h>
#include <unistd.h>

struct InputFile {
    void seek(int, int);
    void readx(void *, unsigned);
};

struct N_BELE_RTP {
    static N_BELE_RTP be_policy;
    static N_BELE_RTP le_policy;
    bool is_be() const { return this == &be_policy; }
    bool is_le() const { return this == &le_policy; }
};

struct opt_t {
    int cmd;
};

struct Elf32_Ehdr {
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS32 = 1,
        ELFDATA2MSB = 2,
        ELFDATA2LSB = 1,
        ET_DYN = 3
    };
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_phnum;
    uint32_t e_phoff;
    uint16_t e_shnum;
    uint32_t e_shoff;
    uint16_t e_phentsize;
};

struct Elf32_Phdr {
    enum {
        PT_DYNAMIC = 2,
        PT_LOAD = 1
    };
    uint32_t p_type;
    uint32_t p_filesz;
};

struct Elf32_Shdr {
    enum {
        SHT_DYNSYM = 11
    };
    uint32_t sh_link;
};

struct Elf32_Dyn {
    enum {
        DT_STRTAB = 5,
        DT_SYMTAB = 6,
        DT_GNU_HASH = 0x6ffffef5,
        DT_HASH = 4
    };
};

struct Elf32_Sym {
    uint32_t st_value;
};

enum {
    CMD_COMPRESS,
    PT_LOAD32
};

class PackLinuxElf32 {
public:
    void PackLinuxElf32help1(InputFile *f);
private:
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint32_t e_phoff;
    uint32_t e_shoff;
    unsigned sz_phdrs;
    Elf32_Ehdr ehdri;
};

uint16_t get_te16(const void *);
uint32_t get_te32(const void *);
void throwCantUnpack(const char *);
void throwCantPack(const char *);
void alloc_file_image(unsigned char *&, unsigned);
Elf32_Shdr *elf_find_section_type(unsigned);
void *elf_find_dynamic(unsigned);
Elf32_Sym *elf_lookup(const char *);
void check_pt_load(const Elf32_Phdr *);
uintptr_t check_pt_dynamic(const Elf32_Phdr *);
void invert_pt_dynamic(const Elf32_Dyn *, uint32_t);

unsigned long file_size;
unsigned char *file_image;
Elf32_Phdr *phdri;
Elf32_Shdr *shdri;
Elf32_Shdr *sec_dynsym;
Elf32_Shdr *sec_dynstr;
Elf32_Dyn const *dynseg;
char const *dynstr;
Elf32_Sym const *dynsym;
unsigned const *gashtab;
unsigned const *hashtab;
Elf32_Sym *jni_onload_sym;
uint32_t jni_onload_va;
opt_t *opt;
N_BELE_RTP *bele;