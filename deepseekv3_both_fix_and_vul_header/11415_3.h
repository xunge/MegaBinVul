#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <inttypes.h>
#include <locale.h>
#include <libintl.h>

#define DWARF3_LENGTH_64_BIT 0xffffffff
#define unlikely(x) (x)
#define IDX_debug_aranges 0

typedef uint64_t Dwarf_Word;

typedef struct {
    void *d_buf;
    size_t d_size;
} Elf_Data;

typedef struct Ebl Ebl;
typedef struct GElf_Ehdr GElf_Ehdr;
typedef struct {
    uint64_t sh_offset;
} GElf_Shdr;
typedef struct Elf_Scn Elf_Scn;
typedef struct {
    Elf_Data *sectiondata[1];
} Dwarf;
typedef struct Dwfl_Module Dwfl_Module;

extern int decodedaranges;
extern const char *section_name(Ebl *ebl, GElf_Ehdr *ehdr, GElf_Shdr *shdr);
extern Dwarf_Word read_4ubyte_unaligned_inc(Dwarf *dbg, const unsigned char **p);
extern Dwarf_Word read_8ubyte_unaligned_inc(Dwarf *dbg, const unsigned char **p);
extern Dwarf_Word read_2ubyte_unaligned_inc(Dwarf *dbg, const unsigned char **p);
extern void print_decoded_aranges_section(Ebl *ebl, GElf_Ehdr *ehdr, Elf_Scn *scn, GElf_Shdr *shdr, Dwarf *dbg);
extern void print_dwarf_addr(Dwfl_Module *dwflmod, unsigned int address_size, Dwarf_Word addr, Dwarf_Word length);
extern const char *elf_errmsg(int err);
extern size_t elf_ndxscn(Elf_Scn *scn);
extern Elf_Data *elf_rawdata(Elf_Scn *scn, Elf_Data *data);