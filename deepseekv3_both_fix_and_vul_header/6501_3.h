#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE_SIZE 4
#define SEEK_SET 0

typedef struct bfd bfd;
typedef long long file_ptr;
typedef size_t bfd_size_type;

enum bfd_error {
    bfd_error_no_symbols,
    bfd_error_file_truncated,
    bfd_error_bad_value
};

extern void bfd_set_error(enum bfd_error error);
extern enum bfd_error bfd_get_error(void);
extern int bfd_seek(bfd *abfd, file_ptr offset, int whence);
extern bfd_size_type bfd_bread(void *ptr, bfd_size_type size, bfd *abfd);
extern void *bfd_malloc(bfd_size_type size);
extern void _bfd_error_handler(const char *fmt, ...);

#define H_GET_32(abfd, ptr) (*(unsigned int *)(ptr))

struct bfd {
    char *strings;
    bfd_size_type strings_len;
};

#define obj_coff_strings(abfd) ((abfd)->strings)
#define obj_coff_strings_set(abfd, str) ((abfd)->strings = (str))
#define obj_coff_strings_len(abfd) ((abfd)->strings_len)
#define obj_coff_strings_len_set(abfd, len) ((abfd)->strings_len = (len))

extern file_ptr obj_sym_filepos(bfd *abfd);
extern unsigned int obj_raw_syment_count(bfd *abfd);
extern unsigned int bfd_coff_symesz(bfd *abfd);