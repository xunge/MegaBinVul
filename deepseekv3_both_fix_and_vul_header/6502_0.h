#include <string.h>

typedef unsigned int flagword;
typedef enum { FALSE, TRUE } bfd_boolean;
typedef unsigned long bfd_vma;

struct asymbol {
    flagword flags;
    void *section;
    void *bfd;
};

typedef struct asymbol asymbol;

struct elf_symbol_type {
    struct {
        bfd_vma st_size;
    } internal_elf_sym;
};

typedef struct elf_symbol_type elf_symbol_type;

#define BSF_FILE 0
#define BSF_DEBUGGING 0
#define BSF_FUNCTION 0
#define BSF_LOCAL 0
#define BSF_GLOBAL 0
#define BSF_SECTION_SYM 0
#define BSF_SYNTHETIC 0

extern int bfd_asymbol_value(const asymbol *);
extern const char *bfd_asymbol_name(const asymbol *);
extern void *bfd_asymbol_bfd(const asymbol *);
extern int bfd_get_flavour(void *);
extern int bfd_target_elf_flavour;