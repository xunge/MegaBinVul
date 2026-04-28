#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

typedef struct bfd bfd;
typedef uint8_t bfd_byte;

typedef struct Elf_Internal_Note {
  unsigned long type;
  bfd_byte *descdata;
  unsigned long descsz;
} Elf_Internal_Note;

typedef struct elf_backend_data {
  struct {
    unsigned int elfclass;
  } *s;
  unsigned int elf_machine_code;
  enum elf_property_kind (*parse_gnu_properties)(bfd *, unsigned int, bfd_byte *, unsigned int);
} elf_backend_data;

enum elf_property_kind {
  property_ignored,
  property_number,
  property_corrupt
};

typedef struct elf_property {
  enum elf_property_kind pr_kind;
  union {
    uint64_t number;
  } u;
} elf_property;

#define ELFCLASS32 1
#define ELFCLASS64 2
#define EM_NONE 0
#define GNU_PROPERTY_LOPROC 0xc0000000
#define GNU_PROPERTY_LOUSER 0x80000000
#define GNU_PROPERTY_STACK_SIZE 1
#define GNU_PROPERTY_NO_COPY_ON_PROTECTED 2

extern const struct elf_backend_data *get_elf_backend_data(bfd *);
extern void _bfd_error_handler(const char *, ...);
extern elf_property *_bfd_elf_get_property(bfd *, unsigned int, unsigned int);
extern void elf_set_properties(bfd *, elf_property *);
extern void elf_set_no_copy_on_protected(bfd *, bfd_boolean);
extern unsigned int bfd_h_get_32(bfd *, const bfd_byte *);
extern uint64_t bfd_h_get_64(bfd *, const bfd_byte *);
extern const char *_(const char *);

static inline void elf_clear_properties(bfd *abfd) {
    elf_set_properties(abfd, NULL);
}

static inline void elf_enable_no_copy_on_protected(bfd *abfd) {
    elf_set_no_copy_on_protected(abfd, TRUE);
}

static inline elf_property **elf_get_properties_ptr(bfd *abfd) {
    static elf_property *props = NULL;
    return &props;
}

static inline bfd_boolean *elf_get_no_copy_on_protected_ptr(bfd *abfd) {
    static bfd_boolean flag = FALSE;
    return &flag;
}

#define elf_properties(abfd) (*elf_get_properties_ptr(abfd))
#define elf_has_no_copy_on_protected(abfd) (*elf_get_no_copy_on_protected_ptr(abfd))