#include <stdbool.h>
#include <stdlib.h>

#define MAX_COMPRESSION_HEADER_SIZE 64

typedef struct bfd bfd;
typedef struct sec {
    unsigned long rawsize;
    void *contents;
    int compress_status;
    unsigned long size;
    unsigned long compressed_size;
} *sec_ptr;

typedef unsigned char bfd_byte;
typedef unsigned long bfd_size_type;

typedef struct {
    unsigned int avail_in;
    unsigned int avail_out;
} z_stream;

#define COMPRESS_SECTION_NONE 0
#define DECOMPRESS_SECTION_ZLIB 1
#define DECOMPRESS_SECTION_ZSTD 2
#define ELFCOMPRESS_ZSTD 2

enum bfd_error {
    bfd_error_invalid_operation,
    bfd_error_wrong_format,
    bfd_error_nonrepresentable_section
};

extern int bfd_get_compression_header_size(bfd *, sec_ptr);
extern bool bfd_get_section_contents(bfd *, sec_ptr, void *, unsigned long, int);
extern bool bfd_check_compression_header(bfd *, bfd_byte *, sec_ptr, unsigned int *, bfd_size_type *, unsigned int *);
extern void bfd_set_error(enum bfd_error);
extern void bfd_set_section_alignment(sec_ptr, unsigned int);
extern bool startswith(const char *, const char *);
extern long bfd_getb64(const void *);