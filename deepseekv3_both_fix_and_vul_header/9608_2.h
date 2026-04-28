#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int bfd_boolean;
#define FALSE 0
#define TRUE 1

typedef long file_ptr;
typedef size_t bfd_size_type;

struct areltdata {
    bfd_size_type parsed_size;
};

struct artdata {
    file_ptr first_file_filepos;
    char *extended_names;
    bfd_size_type extended_names_size;
};

typedef struct bfd {
    struct artdata *ardata;
} bfd;

#define ARFMAG "`\n"
#define CONST_STRNEQ(a,b) (strncmp((a),(b),16) == 0)
#define SEEK_SET 0
#define SEEK_CUR 1

extern int bfd_seek(bfd *, file_ptr, int);
extern struct artdata *bfd_ardata(bfd *);
extern bfd_size_type bfd_bread(void *, bfd_size_type, bfd *);
extern struct areltdata *_bfd_read_ar_hdr(bfd *);
extern void *bfd_zalloc(bfd *, bfd_size_type);
extern file_ptr bfd_tell(bfd *);
extern void bfd_release(bfd *, void *);
extern int bfd_get_error(void);
extern void bfd_set_error(int);
extern int bfd_error_system_call;
extern int bfd_error_malformed_archive;