#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define FALSE false
#define TRUE true

typedef bool bfd_boolean;
typedef uint32_t file_ptr;

typedef struct bfd bfd;

enum bfd_format {
    bfd_unknown,
    bfd_object,
    bfd_archive,
    bfd_core,
    bfd_type_end
};

typedef struct {
    uint32_t type;
    uint32_t namesz;
    uint32_t descsz;
    char name[1];
} Elf_External_Note;

typedef struct {
    uint32_t type;
    uint32_t namesz;
    char *namedata;
    uint32_t descsz;
    char *descdata;
    file_ptr descpos;
} Elf_Internal_Note;

#define H_GET_32(abfd, ptr) (*(uint32_t *)(ptr))
#define ELF_NOTE_DESC_OFFSET(namesz, align) \
    ((offsetof(Elf_External_Note, name) + (namesz) + ((align) - 1)) & ~((align) - 1))
#define ELF_NOTE_NEXT_OFFSET(namesz, descsz, align) \
    (ELF_NOTE_DESC_OFFSET(namesz, align) + (descsz))
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

extern bfd_boolean elfcore_grok_note(bfd *, Elf_Internal_Note *);
extern bfd_boolean elfcore_grok_freebsd_note(bfd *, Elf_Internal_Note *);
extern bfd_boolean elfcore_grok_netbsd_note(bfd *, Elf_Internal_Note *);
extern bfd_boolean elfcore_grok_openbsd_note(bfd *, Elf_Internal_Note *);
extern bfd_boolean elfcore_grok_nto_note(bfd *, Elf_Internal_Note *);
extern bfd_boolean elfcore_grok_spu_note(bfd *, Elf_Internal_Note *);
extern bfd_boolean elfobj_grok_gnu_note(bfd *, Elf_Internal_Note *);
extern bfd_boolean elfobj_grok_stapsdt_note(bfd *, Elf_Internal_Note *);
extern enum bfd_format bfd_get_format(bfd *);