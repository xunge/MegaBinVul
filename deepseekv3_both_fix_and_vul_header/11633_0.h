#include <stdint.h>
#include <string.h>

typedef enum bfd_reloc_status_type {
    bfd_reloc_ok,
    bfd_reloc_outofrange
} bfd_reloc_status_type;

typedef struct reloc_howto_type {
    uint64_t dst_mask;
} reloc_howto_type;

typedef struct bfd {
} bfd;

typedef struct asection {
} asection;

typedef uint8_t bfd_byte;
typedef uint64_t bfd_vma;

bfd_vma read_reloc(bfd *input_bfd, bfd_byte *location, reloc_howto_type *howto);
void write_reloc(bfd *input_bfd, bfd_vma x, bfd_byte *location, reloc_howto_type *howto);
int bfd_reloc_offset_in_range(reloc_howto_type *howto, bfd *input_bfd, asection *input_section, bfd_vma off);
const char *bfd_get_section_name(bfd *abfd, asection *section);