#include <stdint.h>
#include <stddef.h>

typedef unsigned char bfd_byte;

struct bfd;

struct dwarf2_debug {
    void *debug_sections;
};

struct dwarf2_debug_file {
    void *syms;
    bfd_byte *dwarf_addr_buffer;
    size_t dwarf_addr_size;
};

struct comp_unit {
    struct dwarf2_debug *stash;
    struct dwarf2_debug_file *file;
    struct bfd *abfd;
    size_t addr_size;
    size_t dwarf_addr_offset;
    size_t offset_size;
};

extern int _bfd_mul_overflow(uint64_t, uint64_t, size_t *);
extern uint32_t bfd_get_32(struct bfd *, const void *);
extern uint64_t bfd_get_64(struct bfd *, const void *);
extern int read_section(struct bfd *, void *, void *, int, void **, size_t *);

enum {
    debug_addr
};