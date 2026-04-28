#include <stdlib.h>

struct size_sym {
    const void *minisym;
    unsigned long size;
};

typedef struct bfd bfd;
typedef unsigned char bfd_byte;
typedef int bfd_boolean;
typedef unsigned long bfd_vma;

struct asymbol {
    unsigned long flags;
    unsigned long value;
    struct asection *section;
};

struct asection {
    // minimal definition needed
};

typedef struct {
    struct {
        unsigned long st_size;
    } internal_elf_sym;
} elf_symbol_type;

#define BSF_SECTION_SYM 0x1
#define BSF_SYNTHETIC 0x2
#define bfd_target_elf_flavour 1

extern struct asymbol *sort_x;
extern struct asymbol *sort_y;

#define xmalloc malloc

static int size_forward1(const void *a, const void *b) { return 0; }
static int size_forward2(const void *a, const void *b) { return 0; }
static unsigned long valueof(struct asymbol *sym) { return sym ? sym->value : 0; }

static struct asymbol *bfd_minisymbol_to_symbol(bfd *abfd, bfd_boolean is_dynamic, const void *minisym, struct asymbol *sym) { return NULL; }
static void bfd_fatal(const char *msg) {}
static const char *bfd_get_filename(bfd *abfd) { return ""; }
static struct asection *bfd_get_section(struct asymbol *sym) { return NULL; }
static int bfd_get_flavour(bfd *abfd) { return 0; }
static int bfd_is_com_section(struct asection *sec) { return 0; }
static unsigned long bfd_get_section_vma(bfd *abfd, struct asection *sec) { return 0; }
static unsigned long bfd_section_size(bfd *abfd, struct asection *sec) { return 0; }

typedef struct asymbol asymbol;
typedef struct asection asection;