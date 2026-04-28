#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define SEEK_SET 0

typedef int bfd_boolean;
typedef size_t bfd_size_type;

struct bfd_window {
    void *data;
};

struct bfd {
    struct external_nlist* aout_external_syms;
    bfd_size_type aout_external_sym_count;
    char* aout_external_strings;
    bfd_size_type aout_external_string_size;
    struct bfd_window sym_window;
    struct bfd_window string_window;
};

struct external_nlist {
    uint32_t e_strx;
    uint8_t e_type;
    uint8_t e_other;
    uint16_t e_desc;
    uint32_t e_value;
};

#define EXTERNAL_NLIST_SIZE (12)
#define BYTES_IN_WORD (4)
#define USE_MMAP

enum bfd_error {
    bfd_error_bad_value
};

struct exec_hdr {
    bfd_size_type a_syms;
};

static struct exec_hdr* exec_hdr(bfd* abfd) { return NULL; }
static struct external_nlist** obj_aout_external_syms(bfd* abfd) { return &abfd->aout_external_syms; }
static bfd_size_type obj_sym_filepos(bfd* abfd) { return 0; }
static bfd_boolean bfd_get_file_window(bfd* abfd, bfd_size_type offset, bfd_size_type size, struct bfd_window* window, bfd_boolean writable) { return FALSE; }
static struct bfd_window* obj_aout_sym_window(bfd* abfd) { return &abfd->sym_window; }
static void* bfd_malloc(bfd_size_type size) { return malloc(size); }
static int bfd_seek(bfd* abfd, bfd_size_type offset, int whence) { return 0; }
static bfd_size_type bfd_bread(void* ptr, bfd_size_type size, bfd* abfd) { return 0; }
static bfd_size_type* obj_aout_external_sym_count(bfd* abfd) { return &abfd->aout_external_sym_count; }
static char** obj_aout_external_strings(bfd* abfd) { return &abfd->aout_external_strings; }
static bfd_size_type obj_str_filepos(bfd* abfd) { return 0; }
static bfd_size_type GET_WORD(bfd* abfd, unsigned char* chars) { return 0; }
static void bfd_set_error(enum bfd_error error) {}
static struct bfd_window* obj_aout_string_window(bfd* abfd) { return &abfd->string_window; }
static bfd_size_type* obj_aout_external_string_size(bfd* abfd) { return &abfd->aout_external_string_size; }

#define obj_aout_external_syms(abfd) (*obj_aout_external_syms(abfd))
#define obj_aout_external_sym_count(abfd) (*obj_aout_external_sym_count(abfd))
#define obj_aout_external_strings(abfd) (*obj_aout_external_strings(abfd))
#define obj_aout_external_string_size(abfd) (*obj_aout_external_string_size(abfd))

static inline struct bfd_window* obj_aout_sym_window_ptr(bfd* abfd) { return &abfd->sym_window; }
static inline struct bfd_window* obj_aout_string_window_ptr(bfd* abfd) { return &abfd->string_window; }

#define obj_aout_sym_window(abfd) (*obj_aout_sym_window_ptr(abfd))
#define obj_aout_string_window(abfd) (*obj_aout_string_window_ptr(abfd))