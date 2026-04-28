#include <stdint.h>
#include <stdlib.h>

typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

typedef struct bfd bfd;
typedef struct asymbol asymbol;

typedef size_t bfd_size_type;
typedef uint64_t bfd_uint64_t;
typedef unsigned char bfd_byte;

struct asection {
    bfd_size_type size;
    bfd_size_type rawsize;
};

typedef struct asection asection;

struct dwarf_debug_section {
    const char *uncompressed_name;
    const char *compressed_name;
};

enum bfd_error {
    bfd_error_bad_value
};

static inline const char* _(const char* s) { return s; }
static inline void _bfd_error_handler(const char* fmt, ...) {}
static inline void bfd_set_error(enum bfd_error error) {}
static inline asection* bfd_get_section_by_name(bfd* abfd, const char* name) { return NULL; }
static inline bfd_byte* bfd_simple_get_relocated_section_contents(bfd* abfd, asection* sec, void* ptr, asymbol** syms) { return NULL; }
static inline void* bfd_malloc(bfd_size_type size) { return malloc(size); }
static inline bfd_boolean bfd_get_section_contents(bfd* abfd, asection* sec, void* buffer, bfd_uint64_t offset, bfd_size_type count) { return FALSE; }